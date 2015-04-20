function [omega theta omegaInterp tracking alpha e] = feedback_rotor_estimate(ha,hb,hc,alphaCom,time);

halls = [ha hb hc];

ki = -5;
kp = -30;

persistent v;   %velocity
persistent p;   %position
persistent groundCovered; %total position of motor up to last hall pulse
persistent prevHalls;
persistent prevTime;
persistent a;
persistent tPrevHalls;
persistent eInt;
persistent eDInt;
persistent eTInt;
persistent hallCount;
persistent error;
% 
if(isempty(prevTime))
    theta = getThetaFromHalls(halls); % initial position
    groundCovered = 0;
    prevTime = -1;
    prevHalls = halls;
    a = 0;
    v = 0;
    p = theta;
    eInt = 0;
    eDInt = 0;
    eTInt = 0;
    tPrevHalls = -1;
    hallCount = 0;
    error = 0;
end
% 
% deltaT = time - prevTime;
%  if(sum(halls == prevHalls)~=3) %new hall
%      hallCount = hallCount+1;
%      if(hallCount == 1)
%          p = getThetaFromHalls(halls);
%      end
%  end
%  
%  p = p+v*deltaT;
%  prevTime = time;
%  
% e = error;
% omega = v;
% omegaInterp = v;
% theta = wrapTo2Pi(p);
% tracking = 1;
% alpha = alphaCom;
%      
    


% deltaT = time-prevTime;
% 
% v = v+alphaCom*deltaT;
% groundCovered = groundCovered + v*deltaT;
% 
% if(sum(halls == prevHalls)~=3) %new hall
%     direction = getDirectionFromHalls(halls,prevHalls);
%   %  p = getThetaFromHalls(halls);
%     if(direction > 0)
%         error = groundCovered - pi/6;
%     else
%         error = groundCovered + pi/6;
%     end
%     
%     groundCovered = 0;    
%     eInt = eInt + error;
%     v = v +eInt*ki;
% end
% 
% p = p+v*deltaT;
% p = wrapTo2Pi(p);
% 
% prevHalls = halls;
% prevTime = time;
% 
% e = error;
% omega = v;
% omegaInterp = v;
% theta = p;
% tracking = 1;
% alpha = alphaCom;
%     

% %implement feedback on the acceleration estimate, see if it works
% e=0;
% %proportionality constants
% ki = -10;
% kp = -100;

% % these three values are all estimated
% persistent a;  %acceleration
% persistent v;   %velocity
% persistent p;   %position
% persistent groundCovered; %amount of rotation by the estimator since the last hall pulse
% persistent prevHalls;
% persistent prevTime;
% persistent tPrevHalls;
% persistent eInt;
% persistent eDInt;
% persistent eTInt;
% persistent hallCount;
% 
% halls = [ha hb hc];
% 
% 
% if(isempty(prevTime))
%     theta = getThetaFromHalls(halls); % initial position
%     groundCovered = 0;
%     prevTime = -1;
%     prevHalls = halls;
%     a = 1;
%     v = 1;
%     p = theta;
%     eInt = 0;
%     eDInt = 0;
%     eTInt = 0;
%     tPrevHalls = -1;
%     hallCount = 0;
% end
% 
% deltaT = time - prevTime;
% 

deltaT = time - prevTime;

if(sum(halls == prevHalls)~=3) % if new hall state
     hallCount = hallCount+1;
    direction = getDirectionFromHalls(halls,prevHalls);
    
    if(hallCount == 1)
        p = getThetaFromHalls(halls); % need an offset if turning in opposite direction
        groundCovered = getThetaFromHalls(halls);
    end
        
    
    if(direction>0)
        groundCovered = groundCovered - pi/6;
    else
        groundCovered = groundCovered + pi/6;
    end
    
    error = p - groundCovered;
    %double penalties for leading
    if(error > 0)
        error = error*5;
    end      
    
    if(hallCount>1)
            eInt = eInt+error*(time-tPrevHalls);
            eDInt = eDInt+eInt*(time-tPrevHalls);
            eTInt = eTInt + eDInt*(time-tPrevHalls);
            a = kp*error+ki*eInt;
    end
    tPrevHalls = time;  
end

v = v+a*deltaT;
p = p+v*deltaT;

prevHalls = halls;
prevTime = time;

omega = v;
omegaInterp = v;
theta = wrapTo2Pi(p);
tracking = 1;
alpha = a;
e = error;




end

