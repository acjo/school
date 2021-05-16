clc
clear all
close all
syms t s
% 
% f = laplace(2+heaviside(t-1)*exp(-t), t, s)
% 
% ilaplace(f/(s+1), s, t)

% l = laplace(heaviside(t-2), t, s)
% 
% ilaplace((l+1)/(s^2+4*s+4), s, t)


f1 = @(t) t*exp(-2*t) - heaviside(t - 2)*(exp(4 - 2*t)/4 + (exp(4 - 2*t)*(t - 2))/2 - 1/4);
f2 = @(t) t*exp(-2*t)+heaviside(t-2)*(1/4+((3/4 - t/2)*exp(4-2*t)));
f3 = @(t) heaviside(t-2);

dt = 0.01;
time = 0:dt:10;
N = length(time);
x1 = zeros(1,N);
x2 = zeros(1,N);
x3 = zeros(1,N);

for i =1:N
  x1(i) = f1(time(i));
  x2(i) = f2(time(i));
  x3(i) = f3(time(i));
end

figure(2)
plot(time,x1,'r',time, x2,'b', time, x3, 'g')
axis([0 10 0 1.1])
grid on
legend('matlab', 'book', 'forcing')