function A = randint(m,n,a,b) 
% RANDINT tạo ma trận nguyên ngẫu nhiên. 
% randint(m,n) cho mxn ma trận với các thành phần trong khoảng từ 0 đến 9. 
% rand(m,n,a,b) cho các phần tử từ a đến b.
if nargin < 3, a = 0, b = 9; end 
A = floor((b-a-1)*rand(m,n)) + a+1;
