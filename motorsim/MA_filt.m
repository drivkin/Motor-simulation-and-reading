function [ filtered ] = MA_filt(sig, filter_length )
%Moving average filter on a already existing time signal
%   Detailed explanation goes here
filtered = zeros(size(sig));
filtered(1:filter_length) = mean(sig(1:filter_length));

rsum = filtered(1);
for i = filter_length+1:length(sig)
    
    filtered(i) = filtered(i-1)+sig(i)/filter_length - sig(i-filter_length+1)/filter_length;
end


end

