%we have the end point values of a differential equation, we need to find
%the function that defines the space between the two points. For an nth
%order ODE, n conditions are required for a unique solution. 
% heat transfer analyses beam bending, flued, chemical diffusion. The
% numerical solution techniques for solving IVPs and BVPs are different. 

%The shooting method: 
%Convert the BVP to an IVP by initallly ignore the boundary @ the end. The
%2nd boundary condition will typically not be satisfied. For linear ODEs,
%linear interpolation between the first 2 "guess" shots will give the
%correct answer, Fo rnonlinear ODEs, several iterations are likely
%required. Fast for linear ODEs, very tedious for higher order ODEs, you
%have to assume 2 or more initial conditions. Solution can be very
%sensitive to the initial conditions which can make convergence difficult.

%finite diffence approximation:
%the equation for the first derivative is ti+1-ti/xi+1-xi if we use this to
%get the second derivative we get (ti+1-2ti+ti-1)/(xi+1-xi)^2. we can use
%this to help us solve 2nd order ODEs. 