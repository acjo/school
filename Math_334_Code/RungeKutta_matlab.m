digits(6)



tspan = [0 1];
y0 = [0.1 0.2];
[t,y] = ode45(@(t,y) odefcn(t,y), tspan, y0);

f1 = inline('(t^2)-(y*sin(x))', 't', 'x', 'y');

f2 = inline('(cos(t)*x)+(y^2)-t', 't', 'x', 'y');

h = 0.05;
time=0:h:1;
x = zeros(size(time));
z = zeros(size(time));
x(1) = 0.1;
z(1) = 0.2;
i = numel(z);

for n = 1:i-1
    k11 = f1(h*(n-1),x(n),z(n));
    k12 = f2(h*(n-1),x(n),z(n));
    k21 = f1(h*(n-0.5), x(n)+(k11*(h/2)), z(n)+(k12*(h/2)));
    k22 = f2(h*(n-0.5), x(n)+(k11*(h/2)), z(n)+(k12*(h/2)));
    k31 = f1(h*(n-0.5), x(n)+(k21*(h/2)), z(n)+(k22*(h/2)));
    k32 = f2(h*(n-0.5), x(n)+(k21*(h/2)), z(n)+(k22*(h/2)));
    k41 = f1(h*n, x(n)+(k31*h), z(n)+(k32*h));
    k42 = f2(h*n, x(n)+(k31*h), z(n)+(k32*h));
    x(n+1) = x(n)+((h/6)*(k11+(2*k21)+(2*k31)+k41));
    z(n+1) = z(n)+((h/6)*(k12+(2*k22)+(2*k32)+k42));
end

%plot(time,x,time,z);
% xlim([0, 1])
% ylim([-0.2, 0.3])
% grid on

vpa(x(21))
vpa(z(21))

plot(t,y(:,1),'o',t,y(:,2),'x',time,x,time,z)
xlim([0, 1])
ylim([-0.25,0.6])
grid on
legend({'= x computer sol', '= y computer sol', '= x my sol', '= y my sol'}, 'Location', 'southwest')

function dydt = odefcn(t,y)
dydt = zeros(2,1);
dydt(1) = (t^2)-(y(2)*sin(y(1)));
dydt(2) = (cos(t)*y(1))+(y(2))^2-t;
end





