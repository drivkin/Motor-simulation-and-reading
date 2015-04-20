function [ theta ] = getThetaFromHalls( halls )
%UNTITLED2 Summary of this function goes here
%halls is an array of 3 halls states [halla hallb hallc]
%theta is the position of the rotor at the time of transition to the hall
%state if the motor is spinning in the positive theta direction. 

hlstr = [ num2str(halls(1)) num2str(halls(2)) num2str(halls(3))];
shift = pi/6;

switch hlstr
    case '100'
        theta = 10*pi/6 -shift;
    case '110'
        theta = 0 -shift;
    case '010'
        theta = 2*pi/6 - shift;
    case '011'
        theta = 4*pi/6 - shift;
    case '001'
        theta = 6*pi/6 - shift;
    case '101'
        theta = 8*pi/6 - shift;     
    otherwise
        theta =100;
end

end

