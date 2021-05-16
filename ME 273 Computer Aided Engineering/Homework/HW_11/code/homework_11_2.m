clc
clear all
close all

dt = 2;
tinit = 0;
tfinal = 2;
x1init = 1;
x2init = 0;

f1 = @(x2) x2;
f2 = @(x1,x2) -0.4 * x2 + 0.6 * x1;

time = tinit:dt:tfinal;

x1 = zeros(1,length(time));
x2 = zeros(1,length(time));

x1(1) = x1init;
x2(1) = x2init;

i = length(time);

for n = 1:i-1
    x1(n+1) = x1(n) + f1(x2(n)) * dt;
    x2(n+1) = x2(n) + f2(x2(n), x1(n)) * dt;    
end
 
figure(1)
plot(time, x1, 'b -*',time, x2, 'r --', 'linewidth', 3)
grid on
xlabel('time')
ylabel('y')
legend(['Y Euler''s Method dt = ' num2str(dt)], ['Y prime Euler''s Method dt = ' num2str(dt)], 'location', 'NorthWest')

disp(x1(i))