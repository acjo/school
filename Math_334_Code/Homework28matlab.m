function [x'] = f1(t,x,y)
x' = t^2 - y*sin(t);
end
function [y'] = f2(t,x,y)
y' = cos(t)*x + y^2 - t;
end

