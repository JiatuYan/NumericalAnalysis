data1=load('Plot_6.txt')
x1=data1(:,1);
y1=data1(:,2);
data2=load('Plot_11.txt')
x2=data2(:,1);
y2=data2(:,2);
data3=load('Plot_21.txt')
x3=data3(:,1);
y3=data3(:,2);
data4=load('Plot_41.txt')
x4=data4(:,1);
y4=data4(:,2);
data5=load('Plot_81.txt')
x5=data5(:,1);
y5=data5(:,2);
x6=-1:0.001:1;
y6=1./(1+25.*x6.*x6)

plot(x1,y1,'-m',x2,y2,'-c',x3,y3,'-b',x4,y4,'-y',x5,y5,'g',x6,y6,':r');
axis([-1 1 -0.2 1.2])
legend('N=6','N=11','N=21','N=41','N=81','1/1+25x^2');
