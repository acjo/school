clc
clear all
close all

dx = 0.1;
xlower = 0;
xupper = 3;
ylower = 10;
yupper = -4q`;

x = xlower:dx:xupper;

a = -2 - (2*dx)+(2*(dx^2));
b = 1 + (2*dx);
c = 12 * (dx^2);

%empty matrix A
N = length(x); 
A = zeros(N);

B = zeros(N,1);

%known quantities. 
A(1,1) = 1;
A(N,N) = 1;
B(1) = ylower;
B(N) = yupper;

for i = 2:N-1
    A(i,i) = a;
    A(i, i-1) = 1;
    A(i, i+1) = b;
    B(i) = c;
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
legend(['Finite Difference Method dx = ' num2str(dx)], 'location', 'southeast')