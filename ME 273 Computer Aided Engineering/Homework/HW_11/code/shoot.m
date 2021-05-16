%shooting method for homework 11

function yFinal = shoot(myguessforx)

global t y dt;
L = 10; % left boundary
tmin = 0; %the domain of the problem
tmax = 3;
xinit = myguessforx;% the guess

%tvector
t = tmin:dt:tmax;

N = length(t);

%system of 1st order odes
dy1dt = @(y2) y2;
dy2dt = @(x,y1) 3 * x - 4 * y1;


%defining the initial conditions

y = zeros(1,N);
y(1) = L;
x = zeros(1,N);
x(1) =xinit;


for i = 1:N-1
    y(i+1) = y(i) + dy1dt(x(i)) * dt;
    x(i+1) = x(i) + dy2dt(t(i), y(i)) * dt;
end

yFinal = y(N);

end