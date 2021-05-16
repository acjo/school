%This is our algorithm for determnining the x of the region. DO NOT
%CHANGE!!
%%Again we will always use simpsons 1/3 rule
function [centroid, error] = XCENTROIDFUNCTION(oldn, oldcentr, leftpoint,rightpoint)

n = oldn;
newcentr = 0;
h = (rightpoint - leftpoint) / n;
points = zeros(n + 1);
for i = 1:n+1
   points(i) = leftpoint + ((i-1) * h); 
end

for i = 1:n+1
    if i == 0
        newcentr = Function4(points(i));
    elseif i == n + 1
        newcentr = newcentr + Function4(points(i));
    elseif mod(i, 2) == 0
        newcentr = newcentr + (4 * Function4(points(i)));
    else
        newcentr = newcentr + (2 * Function4(points(i)));
    end  
end
newcentr = newcentr * h / 3;
approxerror = abs((newcentr-oldcentr)*(100 / newcentr));
if  approxerror > 0.0001
      n = n * 10;
     [centroid, error] = XCENTROIDFUNCTION(n, newcentr, leftpoint, rightpoint);
else
    centroid = newcentr;
    error = approxerror;
end
end

function [res] = Function4(x)
res = x * Function3(x);
end