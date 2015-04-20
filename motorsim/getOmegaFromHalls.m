function w = getOmegaFromHalls(halls,prev_halls,alpha_com,t,prev_t)
%This function is called on a transition between hall states. t is the time
%of the transition, prev_t is the time of the previous transition. The 2
%hall inputs are used to determine the direction of rotation.

pr_hl_str = [num2str(prev_halls(1)) num2str(prev_halls(2)) num2str(prev_halls(3))];

dt = t - prev_t;

d= pi/3;
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

w = (2*d+alpha_com*dt^2)/(2*dt);


% w = (pi/3)/(t-prev_t);
% 
% switch pr_hl_str
%     case '100'
%         if(sum(halls == [1 0 1])==3)
%             w=-w;
%         end
%     case '110'
%         if(sum(halls == [1 0 0])==3)
%             w=-w;
%         end
%     case '010'
%         if(sum(halls == [1 1 0])==3)
%             w=-w;
%         end
%     case '011'
%         if(sum(halls == [0 1 0])==3)
%             w=-w;
%         end
%     case '001'
%         if(sum(halls == [0 1 1])==3)
%             w=-w;
%         end
%     case '101'
%         if(sum(halls == [0 0 1])==3)
%             w=-w;
%         end
%     otherwise
% 
% end




end

