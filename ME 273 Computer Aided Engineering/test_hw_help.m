%% Midterm #1:
%% Q6 There are 32 bits used to store an int in VS c++
% [10] Consider a hypothetical 12-bit floating point representation that has one sign bit, a 4-bit exponent, and a 7-bit mantissa with comparable rules to traditional IEEE representation. The bias for the exponent is 7.
% 
% A number stored in this representation is 101010110100.
% 
% Is the number that is stored negative or positive (enter "n" for negative or "p" for positive)?
%% Q15 n
% 
% What is the decimal value of the exponent (after the bias has been applied)?
%% Q16 -1  (-2) <- actual
% 
% What is the decimal value of the mantissa (with the shadow bit)?
%% Q17 1.40625
% 
% What is the decimal floating point value of the number?
%% Q18 -0.703125  -.3515625
% 
% What is machine epsilon for this representation?
%% Q19 0.00781250



%% Midterm #2:
%% NOTE: Simpson's 3/8 Rule can only be used with a segment number that is a multiple of 3. 
%% Q15
% % Using the Newton-Raphson Method, solve for the root of
% % xln(x) = sin(2x)+3 to an approximate error less than 3%,
% % starting with x0 = 2. (In other words, what is the value of
% % xi when your value of ea drops below 3% ? )
% % Note: d/dx (ln(x)) = 1/x and the first value of ea can be
% % calculated once you have x1. (Only
% % answers within 1% of the correct response will receive credit).
% 
% % fx = -xlog(x) + sin(2x) + 3
% clc
% xold = 2;
% 
% xnew = xold - (-xold*log(xold) + sin(2*xold) + 3)/(-log(xold) - 1 + 2*cos(2*xold))
% ea = (xnew - xold)/xnew * 100
% xold = xnew;
% 
% xnew = xold - (-xold*log(xold) + sin(2*xold) + 3)/(-log(xold) - 1 + 2*cos(2*xold))
% ea = (xnew - xold)/xnew * 100
% xold = xnew;

 
%% Q26
%% For the Newton-Raphson method, and The centered difference approximation I fixed the excel notebook.  
% f(x)=x3?10

% Using the centered difference approximation for a derivative with a step size of 0.1,
% what is the next (or second) guess for the root of the above equation using the
% secant method if the first guess is 5.
% You must be within 1% of the correct answer to receive credit.

% xnew = xold - fx/fxp;
% x0 = 5;
% xmin1 = 4.9;
% x1 = 5.1;
% fxp = ((x1^3-10) - (xmin1^3-10))/(0.2);
% 
% xnew = x0 - (x0^3-10)/fxp
% un = @x -(55 * x) + (38 * x^2)-(10.5 * x^3) + x^4 + 37;

%% Q12
% Using Simpson's Rules, calculate the approximation of the area under
% the curve defined by f(x) = 37 -55x + 38x2-10.5x3 + x4 between x = 1
% and x = 3.5 using 5 segments? What is the error with respect to the
% true value?

%fx = 37 - 55*x + 38*x^2-10.5*x^3 + x^4

% x = 1:0.5:3.5
% x = 1;
% f1 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% x = 1.5;
% f2 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% x = 2;
% f3 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% x = 2.5;
% f4 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% x = 3;
% f5 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% x = 3.5;
% f6 = 37 - 55*x + 38*x^2-10.5*x^3 + x^4
% 
% EstArea = 0.5*(1/3)*(f1+4*f2+f3) + 0.5*(3/8)*(f3+3*f4+3*f5+f6)
% 
% x = 3.5
% fxpH = 37*x - 55*x*x/2 + 38*x^2*x/3 - 10.5*x^3*x/4 + x^4*x/5
% x = 1
% fxpL = 37*x - 55*x*x/2 + 38*x^2*x/3 - 10.5*x^3*x/4 + x^4*x/5
%% Q13
% % TrueArea = fxpH - fxpL
% fun = @(x) (-55 * x) + (38 * x.^2) - (10.5 * x.^3) + (x.^4) + 37;
% format long
% q = integral(fun, 1, 3.5)

%% Q14
% TrueArea - EstArea



%% there are 2048 bits in an array used to store 64 integers. 

%% Finding the condition of a matrix using the euclidean norm
% A = [5 0 0
% -1 -2 -4
% -3 -1 -4]
% 
% anorm = sqrt(sum(A.^2,'all'))
% Ainv = A^-1 % This step would take a little bit of time by hand but not much because of the zeros!
% ainorm = sqrt(sum(Ainv.^2,'all'))
% cond_a = anorm*ainorm










%% HW 29 Math 334

% A = [0 -1;
%     -2 -2];
% 
% 
% [V, D] = eig(A);
% N1 = V(:,1);
% N2 = V(:,2);
% % disp(H)
% 
% n1 = norm(N1);
% n2 = norm(N2);
% N1 = N1/n1;
% N2 = N2/n1;
% 
% b = trace(A)
% d = det(A)
% disp(D)
% disp(V)


















