clc 
clear all
close all

f1 = @(t,x) -x+2 + heaviside(t-1)*exp(-t);
%mysolution
f2 = @(t)heaviside(t - 1)*exp(- t)*(t - 1) - 2*exp(-t) + 2;
f3 = @(t) 2 + heaviside(t-1)*exp(-t);


dt = 0.1;

time = 0:dt:10;
N = length(time);
x2 = zeros(1,N);
x3 = zeros(1,N);

for i = 1:N
    x2(i) = f2(time(i));
    x3(i) = f3(time(i));
end

Tspan = [0 10];



Y0 = 0;


[t,x] = ode45(f1, Tspan, Y0);

figure(1)
plot(t,x, 'r --')
grid on
hold on
plot(time, x2, 'b -', time, x3, 'm -o')
legend('sol ode 45', 'my sol', 'forcing function')