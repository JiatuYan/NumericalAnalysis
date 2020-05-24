data1=load('fpoints.txt')
data2=load('Apoints.txt')
x1=data1(:,1);
y1=data1(:,2);
x2=data2(:,1);
y2=data2(:,2); 
plot(x1,y1,'-m',x2,y2,'-c');
legend('Condf','CondA');
axis([0 1 0 10])
print(gcf,'-depsc','result.eps')