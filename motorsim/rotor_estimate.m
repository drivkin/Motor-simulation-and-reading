function [omega theta omegaInterp tracking] = rotor_estimate(ha,hb,hc,alpha_com,time)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%estimate the position of the rotor in degrees electrical


persistent prev_sim_time
persistent prev_t;
persistent t;
persistent prev_halls;
persistent tToNextHall;
persistent w;
persistent wdiff;
persistent theta1;
persistent alpha;
persistent hallCount;


theta = 0;
omega = 0;
omegaInterp = 0;
tracking = 0;

if(isempty(prev_t))
    prev_sim_time = time;
    alpha = 0;
    prev_t=0;
    t = 0;
    prev_halls = [ha hb hc];
    tToNextHall = 1000000;
    w = 0;
    wdiff = 0;
    theta1 = getThetaFromHalls([ha hb hc])+pi/6;
    hallCount = 0;
    theta = wrapTo2Pi(theta1);
    omega =0;
    omegaInterp = 0;
    return
end
Test = time-prev_sim_time;

t = time;
halls = [ha hb hc];

if(sum(halls == prev_halls)==3)
    %if w is now known to be lower than calculated
    w = w+Test*2*alpha_com;
%     if(t-prev_t > tToNextHall)
%         w = ((pi/3)/(t-prev_t))*sign(w);
%     end
    theta1 = theta1 + w*Test;
    
%     wdiff = wdiff+Test*2*alpha_com;%factor of 2 for mech to elec conversion
%     theta1 = theta1 + (w+wdiff)*Test;
    %theta1 = theta1+w*Test;
    
 
else
    if(hallCount>1)
        wnew = getOmegaFromHalls(halls,prev_halls,alpha_com,t,prev_t);
        
%         tToNextHall = abs((pi/3)/wnew);
        alpha = (wnew - w)/(t-prev_t);
        w = wnew;
        if(w>=0)
            d = pi/3;
            theta1 = getThetaFromHalls(halls);
        else
            d = -pi/3;
            theta1 = getThetaFromHalls(prev_halls);
        end
        tToNextHall = max(roots([alpha_com 2*w -2*d]));      
    end
        
    
    wdiff = 0;
    prev_t = t;
    prev_halls = halls;
    hallCount = hallCount + 1;
end

theta = wrapTo2Pi(theta1);
omega = w;
omegaInterp = w+wdiff;
prev_sim_time = time;

if(hallCount>3)
    tracking =1;
else
    tracking =0;
end


end

