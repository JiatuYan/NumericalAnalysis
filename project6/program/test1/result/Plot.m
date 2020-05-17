data1=load('magnified_function1.txt')
data2=load('magnified_function2.txt')
data3=load('magnified_function3.txt')
x1=data1(:,1);
y1=data1(:,2);
x2=data2(:,1);
y2=data2(:,2); 
x3=data3(:,1);
y3=data3(:,2);
plot(x1,y1,'-m',x2,y2,'-c',x3,y3,'-r');
legend('function1','function2','function3');
axis([0.99 1.01 -200 200])