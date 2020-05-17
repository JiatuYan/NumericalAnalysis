data1=load('NormalizedN.txt')
data2=load('SubnormalN.txt')
x1=data1(:,1);
y1=x1-x1;
x2=data2(:,1);
y2=x2-x2; 
x3=-4:0.001:4;
y3=x3-x3;
plot(x1,y1,'xr',x2,y2,'xb',x3,y3,'-k')
legend('normalized FPN','subnormal FPN')
for i = -4 : 4
    text(i,-0.1,num2str(i),'color','k');
end

axis([-4.5 4.5 -1 1]) 
