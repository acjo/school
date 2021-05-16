%----------------------------------------------------------------------------------
% File:: Project2.m
% By: Caelan osman
% Date: March 22 2020
% This program use a root finding algorthim to find when to functions are equal,
% by requirement this happens at two points as we need a closed plane and then uses
% those two points to nmerically calculate the centroid of the shape created by 
% the enclosing functions. Change the functions in the Function1.m and Function2.m
% tabs, Function1 being the upper function and Function2 being the lower function.
%-----------------------------------------------------------------------------------


% Artist, input the x coordinate of that is inside the region of the two graphs here: 
x = -0.5;
steppingValue = 0.01;

%The sign of our initial point
if Function3(x) < 0
    initpositive = true;
else
    initpositive = false;
end

%initial guesses for bracketing the roots
x2 = x - 0.01;
x3 = x + 0.01;
initialbracket = [x2 x3];
positive = zeros(2);

%sets an array of booleans for the sign of the output of Function3 for our
%intial bracket elements.
for n = 1:2
    if Function3(initialbracket(n)) < 0
        positive(n) = false;
    else
        positive(n) = true;
    end
end

%Finds our initial bracketing guesses for the right and left root
for n = 1:2
    if n == 1
        while positive(1) ~= initpositive
            initialbracket(1) = initialbracket(1) - steppingValue;
            if Function3(initialbracket(1)) < 0
            positive(1) = false;
            else
            positive(1) = true;
            end
        end
    else
        while positive(2) ~= initpositive
            initialbracket(2) = initialbracket(2) + steppingValue;
            if Function3(initialbracket(2)) < 0
            positive(2) = false;
            else
            positive(2) = true;
            end
        end
    end
end

%our roots/intersection points
intersectionpoints = zeros(2);
%calls the RootFinding function and finds both roots
for n = 1:2
    intersectionpoints(n) = RootFinding(x, initialbracket(n));
end


%next step is approximating the area we call our AreaBetweenCurves
%function. We use the initalh and initialval because we will be using
%recurssion for the next 3 functions
initialn = 100;
initialval = 0;
[area, areaError] = AreaBetweenCurves(initialn, initialval,intersectionpoints(1), intersectionpoints(2));
disp(area)
disp(areaError)

%%next we find our x centroid
[positionXCentroid, xError] = XCENTROIDFUNCTION(initialn, initialval, intersectionpoints(1), intersectionpoints(2));
positionXCentroid = positionXCentroid / area;
disp(positionXCentroid)
disp(xError)

%%we find our y centroid
[positionYCentroid, yError] = YCENTROIDFUNCTION(initialn, initialval, intersectionpoints(1), intersectionpoints(2));
positionYCentroid = positionYCentroid / area;
disp(positionYCentroid)
disp(yError);


%plotting the function and the centroid
figure(1)
fplot(@(x) Function1(x), [(intersectionpoints(1)-0.1) (intersectionpoints(2)+0.1)])
hold on
grid on
fplot(@(x) Function2(x), [(intersectionpoints(1)-0.1) (intersectionpoints(2)+0.1)])
hold on
plot(positionXCentroid, positionYCentroid, 'x')
hold off

