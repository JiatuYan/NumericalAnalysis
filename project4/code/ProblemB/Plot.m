
function f=plotTruncatedPowerFunc2Bsplines(n)
%Illustrate the relation between truncated power functions and B-splines.
%
%INPUT
%   n : the degree of B-splines.
%Preconditions:
%   CHECK:n==1 or n==2,i.e. the code only works for linear and quadratic
%   cases.
y=cell(n+2, n+2)
x=0:0.001:2+n;
for i=1:n+2
    for j=i:n+2        
        if i==1
            y{i,j}=(x<j).*(j-x).^n
        else
            y{i,j}=(y{i-1,j} - y{i-1,j-1})/(i-1)
        end
        subplot(n + 2,n + 2,(j-1) * (n + 2) + i)
        plot(x,y{i,j},'b');
    end
end
