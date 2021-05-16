%% Least squares regression Notes
% interpolation -> method of constructing new data points with the range of
% a discret set of known datat points
%Regression curve represents the trend, but does not neccesarily exactly
%intercept any data points
% we will focus on polynomial regression, although any function form can be
% used
%higher order regressions do not always give better representations of the
%trend
% Plotting the data points and the regression curve is essential to verify
% the correctness of it


% y = sum(yi) / n the average of the data set. 

%standar deviation -> A measure of the "spread" of the data points
% st = sqrt((sum(yi^2)-(sum(yi)^2/n))/n-1
%histogram provides a visual representation of the distribution by sorthing
%the date into value "bins"
%Normal distribution Given enough points, we would expect a smooth "bell
%shaped" distribution around the mean. 68% of the data points fall within 1
%standard deviation of the mean and 95% within two standard deviations of
%the mean. 
%Residual: Vertical distance between a data point and the best fit line. A
%best fit line minimizes the residuals in some way.
%When minimizing residuals summing residuals and summing absolute values of
%residuals are both poor examples of measurements because they are not
%unique. The maximum error of any indiviual point is not a good meas
%urement
%
%
%
%
%because it gives too much influence on singlue outlier points. Using least
%squares solutions is the best way to overcome these errors. You minimize
%the sum of the squares of the residuals. Sr = sum(yiactual - yi model)^2
%For linear regression, yimodel = a0 + a1xi 
% Sr = sum(yiactual - ao -a1xi)^2
%in order to minimize, we take the partial derivatives with respect to a0
%and a1 and set them equal to zero
%we can use this same equation to to determine our error. To do so we'll
%compare the error to our fit to the total error of the horizontal line
%through the mean of the data. 
%st = sum(yi - ybar) where ybar is the mean or average. 
%we want to look @ the error because why are we increasing the complexity
%with a slanted line over a horizontal line if it isn't any better. 

%We use the correlation coefficent.
% r^2 = st-sr/st
% for a perfect fit, sr = 0 or r = 1 (the line captures the date perfectly)
% for r = 0, sr = st and the fit represents no improvement over the mean.

%we can keep adding powers. to try and fit the model even better. 
% [n sum(xi) sum(xi^2().....sum(xi^m);
%  sum(xi) sum(xi^2) ..... sum(xi^m+1);
%  .
%  .                                             [a0; a1; a2; .... am] =
%  [sum(yi); sum(xi yi); sum(xi^2 yi).....sum(xi^m yi)]
%  .
%  sum(xi^m) sum(xi^m+1)......sum(xi^2m)]
%This method can be extended to any polynomial of order m with restrection
% m <= n-1 where n is the number of data points. 
%



%%
clc 
clear all
close all
x = [1;2;5;4;7];
y = [9;4;1;3;11];

figure(1)
plot(x,y, 'ro') % plotting points instead of a line
xlabel('x')
ylabel('y') %labels access
axis([0 10 0 12]) %sets x min x max ymin ymax for plot

n = length(x);

%sum sums all the elements in an array

a1 = (n*sum(x.*y) - sum(x)*sum(y)) /(n*sum(x.*x)-sum(x)^2); % x.*y is an array multiplication operator element wise multiplication

a0 = mean(y) - a1*mean(x); %mean returns the man value in a vector



xline = 0:10;
yline = a0 + a1*xline; %adds a0 to each element in a1*xline

hold on %keeps data

plot(xline, yline, 'b-')

%% Calculating r^2 value

SR = sum((y - (a0+a1*x)).^2); % have to add a dot since the qunatity is a vecotr

ST = sum( (y-(mean(y))).^2);

r2value = (ST-SR) / ST;

%because r value is so close to zero it is indicitave that a second order
%might be better. 


A = [n sum(x) sum(x.^2);
    sum(x) sum(x.^2) sum(x.^3)
    sum(x.^2) sum(x.^3) sum(x.^4)];

b = [sum(y); sum(x.*y); sum(x.^2.*y)] ;

a = A^-1 * b;

xline2 = 0:0.1:10;%0.1. is the stepper
yline2 = a(1) + a(2)*xline2 + a(3)*xline2.^2;

hold on %keeps data

plot(xline2, yline2, 'g--')


SRDEG2 = sum((y - (a(1) + a(2)*x + a(3)*x.^2)).^2); % have to add a dot since the qunatity is a vector

% STDEG2 = sum( (y-(mean(y))).^2); this model doesn't change from the first
% order polynomial

r2valueDEG2 = (ST-SRDEG2) / ST;

%if we only had two points we wouldn't be able to fit it as well. because
%now we can't solve a 3x3 matrix because we have 2 equations and 3 unknowns. 

hold off
%% Interpolating polynomials
% remember, an interpolating polynomial exactly passes through each data
% point. The polynomial will have the form f(x) = a0 +a1x +a2x^2 = ...+
% an-1x^{n-1} where n is the number o fdata points. The most straight
% forward way to find the coefficients is to consider the function
% evaluated at each point. The matrix equations that result from this
% approach are notoriously ill-conditioned, so this is not the most
%efficient way to compute the polynomial coefficients typically there are
%problems with interpolation of large numbers of data points. 

clc
clear all 
close all

x = [1;2;4;5;3];
y = [3;14;4;8;18];

figure(2)
plot(x,y,"rx")
xlabel('x')
ylabel('y')
axis([0 6 -20 40])

A = [1 x(1) x(1)^2 x(1)^3 x(1)^4;
    1 x(2) x(2)^2 x(2)^3 x(2)^4;
    1 x(3) x(3)^2 x(3)^3 x(3)^4;
    1 x(4) x(4)^2 x(4)^3 x(4)^4;
    1 x(5) x(5)^2 x(5)^3 x(5)^4];

b = [y(1); y(2); y(3); y(4); y(5)];

a = inv(A)*b;

xpoly = 0:0.1:10;
ypoly = a(1)+a(2)*xpoly + a(3) *xpoly.^2 + a(4)*xpoly.^3 + a(5)*xpoly.^4;

hold on

plot(xpoly,ypoly,'b--')

P = polyfit(x, y, 3);

ypoly2 = polyval(P,xpoly);

plot(xpoly,ypoly2, 'g*', 'linewidth', 0.5)

%%Note that in the case where the degree of your polynomial is less than
%%the number of points you have minus one, it will give you a lest squares
%%regression that matches our earlier methods. and when the degree is
%%greater than the number of points then the polynomial is no longer
%%unique. 










