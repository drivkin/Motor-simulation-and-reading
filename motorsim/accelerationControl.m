function [ Vd,Vq ] = accelerationControl( aDes,w, error )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
%take the desired torque current 
% speed and compute the output voltage vector in the DQ
%frame. 
persistent I

R = 28.2*sqrt(3)/2;
Kt = 18.1*10^-3*sqrt(3)/2; %Nm/Amp
Ke = Kt/sqrt(3);

if(isempty(I))
    I = aDes*.00012*1/Kt
end

ki = -0.2;

w=w/2;
 L = 1940*10^-6; % with a factor of sqrt(3)/2 multiplying, Id rises with w
%also with no factor
%also divided by sqrt(3)
%also divided by 3
%also divided by 3*sqrt(3)



%because I is assumed to be on Q axis, T = KtI
I = I+ki*error;

%bemf is on q axis
bemf = Ke*w;

%inductor impedance 
ZL = L*w;

Vq = (bemf+I*R)*sqrt(3);
Vd = (-ZL*I)*sqrt(3);


end

