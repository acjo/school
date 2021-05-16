clc
clear all
close all
x = [18.93; 19.35; 19.65; 19.92; 20.04]
y = [18.0; 19.5; 20.0; 25.7; 29.7];
plot(x,y,'kx')
axis([15 30 10 30])
xlabel('Year x 10')
ylabel('10 lb')

n = length(x);
a1 = (n*sum(x.*y) - sum(x)*sum(y)) /(n*sum(x.*x)-sum(x)^2);
a0 = mean(y) - a1*mean(x);
xline = 15:30;
yline = a0 + a1*xline;
hold on %keeps data
plot(xline, yline, 'b-')
SR = sum((y - (a0+a1*x)).^2); % have to add a dot since the qunatity is a vector

ST = sum( (y-(mean(y))).^2);

r2value = (ST-SR) / ST

A = [n sum(x) sum(x.^2);
    sum(x) sum(x.^2) sum(x.^3)
    sum(x.^2) sum(x.^3) sum(x.^4)];
b = [sum(y); sum(x.*y); sum(x.^2.*y)];

a = A^-1 * b;

xline2 = 15:0.1:30;%0.1. is the stepper
yline2 = a(1) + a(2)*xline2 + a(3)*xline2.^2;
hold on %keeps data

plot(xline2, yline2, 'r--')

SRDEG2 = sum((y - (a(1) + a(2)*x + a(3)*x.^2)).^2); 
r2valueDEG2 = (ST-SRDEG2) / ST

C =[1 x(1) x(1)^2 x(1)^3 x(1)^4; 
    1 x(2) x(2)^2 x(2)^3 x(2)^4;
    1 x(3) x(3)^2 x(3)^3 x(3)^4; 
    1 x(4) x(4)^2 x(4)^3 x(4)^4;
    1 x(5) x(5)^2 x(5)^3 x(5)^4;];

c = (C^-1) * y

xpoly = 15:0.01:30;
ypoly = c(1)+c(2)*xpoly + c(3) *xpoly.^2 + c(4)*xpoly.^3 + c(5)*xpoly.^4;

hold on

plot(xpoly,ypoly,'m -')
legend({'data points','first order', '2nd order', 'interpolating'}, 'location', 'southeast') 


