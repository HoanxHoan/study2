function [mean, stdev] = stat(x) 
% STAT Mean and standard deviation 
% For a vector x, stat(x) returns the 
% mean and standard deviation of x. 
% For a matrix x, stat(x) returns two row vectors containing, 
% respectively, the mean and standard deviation of each column. 
[m n] = size(x); 
if m == 1 
m = n; % handle case of a row vector 
end 
mean = sum(x)/m; 
stdev = sqrt(sum(x.^2)/m - mean.^2); 
