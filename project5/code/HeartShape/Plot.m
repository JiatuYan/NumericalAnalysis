data1=load('Plot1y_160.txt')
data2=load('Plot2y_160.txt')
data3=load('Plotx_160.txt')
x1=data3(:,2);
y1=data1(:,2);
x2=data3(:,2);
y2=data2(:,2); 
plot(x1,y1,'-m',x2,y2,'-c');
axis([-1 1 -0.2 1.2])
