%This is our function for finding the area between our two curves. DO NOT
%CHANGE!!!!
%because our n is always even we will always use simpsons 1/3 rule
function [area, error] = AreaBetweenCurves(oldn, oldarea, leftpoint, rightpoint)

n = oldn;
newarea = 0;
h = (rightpoint - leftpoint) / n;
points = zeros(n + 1);
for i = 1:n+1
    points(i) = leftpoint + ((i-1) * h);
end

for i = 1:n+1
    if i == 0
        newarea = Function3(points(i));
    elseif i == n + 1
        newarea = newarea + Function3(points(i));
    elseif mod(i, 2) == 0
        newarea = newarea + (4 * Function3(points(i)));
    else
        newarea = newarea + (2 * Function3(points(i)));
    end
end
newarea = newarea * h / 3;
approxerror =  abs((newarea-oldarea)*(100/newarea));
if approxerror > 0.0001
    n = n * 10;
    [area, error] = AreaBetweenCurves(n,newarea,leftpoint,rightpoint);
else
    area = newarea;
    error = approxerror;
end
end