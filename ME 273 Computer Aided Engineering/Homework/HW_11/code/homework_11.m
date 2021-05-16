dt = 0.1;
tinit = 0;
tfinal = 5;
yinit = 3;

time = tinit:dt:tfinal;
y = zeros(size(time));
i = length(y);

y(1) = yinit;

for n = 1:i-1
    y(n+1) = y(n) + (f1(0,y(n)) * dt);
end

plot(time,y, 'r --')
xlabel('time')
ylabel('y')
axis([0 5 0 4])
tspan = [0 5];
[t,x] = ode45(@(t,x) f1(t,x), tspan, y(1));
hold on
plot(t,x, 'g-x')
legend({['Euler''s Method, dt = ' num2str(dt)],'ODE45'}, 'location', 'southeast')

function [res] = f1(~,y)

res = -(y^2)+13+sqrt(y);

end