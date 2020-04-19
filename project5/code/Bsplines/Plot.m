data1=load('Quadratic.txt')
x1=data1(:,1);
y1=data1(:,2);
data2=load('Cubic.txt')
x2=data2(:,1);
y2=data2(:,2);
x3=-5:0.1:5;
y3=1./(1+x3.*x3)
plot(x1,y1,'-m',x2,y2,'-c',x3,y3,'*k');
axis([-5 5 -0.2 1.2])
legend('Quadratic B-splines','Cubic B-splines','1/1+x^2');
