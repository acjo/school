f1 = inline('(t^2)-(y*sin(x))', 't', 'x', 'y');

f2 = inline('(cos(t)*x)+(y^2)-t', 't', 'x', 'y');

h = 0.05;
t=0:h:1;
x = zeros(size(t));
y = zeros(size(t));
y(1) = 0.2;
x(1) = 0.1;
i = numel(y);

for n = 1:i-1
    x(n+1) = x(n)+ h * f1((n-1)*h, x(n), y(n));
    y(n+1) = y(n) + h * f2((n-1)*h, x(n), y(n)); 
end

plot(t,x,t,y);
xlim([0, 1])
ylim([-0.2, 0.3])
grid on
y(21)
x(21)



