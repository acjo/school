clc
clear all
close all

dx = 0.1;
xlower = 0;
xupper = 10;
ylower = 1;
yupper = 6;

x = xlower:dx:xupper;
N = length(x);

a = 4 - (3*dx)-(4*(dx^2));
b = -2 + (3*dx);
c = -2;

%empty matrix A
A = zeros(N);
B = zeros(N,1);

%known quantities. 
A(1,1) = 1;
A(N,N) = 1;
B(1) = ylower;
B(N) = yupper;

for i = 2:N-1
    A(i,i) = a;
    A(i, i-1) = c;
    A(i, i+1) = b;
    B(i) = (dx^2)*(4-x(i));
end

Y = A\B;

figure(1)
plot(x,Y, 'g -*', 'linewidth', 2)
grid on
hold on
plot(xlower, ylower, 'r x')
plot(xupper, yupper, 'r x')
xlabel('x')
ylabel('y')
legend(['Finite Difference Method dx = ' num2str(dx)], 'location', 'northwest')