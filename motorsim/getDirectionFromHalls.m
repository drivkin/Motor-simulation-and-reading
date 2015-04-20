function [ direction ] = getDirectionFromHalls( halls,prev_halls )
%UNTITLED2 direction = 1 means theta increasing, direction = -1 theta
%decreasing
%   Detailed explanation goes here
pr_hl_str = [num2str(prev_halls(1)) num2str(prev_halls(2)) num2str(prev_halls(3))];

d = 1;

switch pr_hl_str
    case '100'
        if(sum(halls == [1 0 1])==3)
            d=-d;
        end
    case '110'
        if(sum(halls == [1 0 0])==3)
            d=-d;
        end
    case '010'
        if(sum(halls == [1 1 0])==3)
            d=-d;
        end
    case '011'
        if(sum(halls == [0 1 0])==3)
            d=-d;
        end
    case '001'
        if(sum(halls == [0 1 1])==3)
            d=-d;
        end
    case '101'
        if(sum(halls == [0 0 1])==3)
            d=-d;
        end
    otherwise

end

direction = d;


end

