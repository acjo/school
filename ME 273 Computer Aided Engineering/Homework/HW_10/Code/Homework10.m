clc
clear all
close all

%The vectors containg the x and y cordinates of the points
x = [3;8;1;5;9];
y = [18.4;19.2;12.1;15.9;21.6];

figure(1)
plot(x,y,'ko')
axis([0 10 8 25])
xlabel('x')
ylabel('y')

%this is for a first order polynomial
n = length(x);
a1 = (n*sum(x.*y) - sum(x)*sum(y)) /(n*sum(x.*x)-sum(x)^2);
a0 = mean(y) - a1*mean(x);
xline = 0:10;
yline = a0 + a1*xline;
hold on %keeps data
plot(xline, yline, 'b-')
SR = sum((y - (a0+a1*x)).^2); % have to add a dot since the qunatity is a vector

ST = sum( (y-(mean(y))).^2);

r2value = (ST-SR) / ST %The r^2 value for the first oder polynomial

%This is for a second order polynomial

A = [n sum(x) sum(x.^2);
    sum(x) sum(x.^2) sum(x.^3)
    sum(x.^2) sum(x.^3) sum(x.^4)];
b = [sum(y); sum(x.*y); sum(x.^2.*y)];

a = A^-1 * b;

xline2 = 0:0.1:10;%0.1. is the stepper
yline2 = a(1) + a(2)*xline2 + a(3)*xline2.^2;
hold on %keeps data

plot(xline2, yline2, 'r--')

SRDEG2 = sum((y - (a(1) + a(2)*x + a(3)*x.^2)).^2); 
r2valueDEG2 = (ST-SRDEG2) / ST %r^2 value for a quadratic regression polynomial. 

%We will now find the interpolating polynomial

C =[1 x(1) x(1)^2 x(1)^3 x(1)^4; 
    1 x(2) x(2)^2 x(2)^3 x(2)^4;
    1 x(3) x(3)^2 x(3)^3 x(3)^4; 
    1 x(4) x(4)^2 x(4)^3 x(4)^4;
    1 x(5) x(5)^2 x(5)^3 x(5)^4;];

c = (C^-1) * y

xpoly = 0:0.1:10;
ypoly = c(1)+c(2)*xpoly + c(3) *xpoly.^2 + c(4)*xpoly.^3 + c(5)*xpoly.^4;

hold on

plot(xpoly,ypoly,'m x-')
legend({'data points','first order', '2nd order', 'interpolating'}, 'location', 'southeast') 


