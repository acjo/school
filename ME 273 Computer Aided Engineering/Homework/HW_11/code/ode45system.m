    clc
    clear all
    close all
    
    yinit = 9;
    xinit = -1;
    tinit = 0;
    tfinal = 5;
    
    TSPAN = [tinit tfinal];
    initcond = [yinit xinit];
    
    [t,y] = ode45(@(t,y)odeFunc(t,y),TSPAN,initcond);
    
    figure(1)
    plot(t, y(:,1),'b -*', t, y(:,2), 'r --', 'linewidth', 3)
    grid on
    xlabel('time')
    ylabel('yfunc')
    legend('ode45 y', 'ode45 y prime', 'location', 'northwest')
    
    function dydt = odeFunc(t,y)
    dydt = zeros(length(y),1);
    dydt(1) =  y(2);
    dydt(2) = ((2*y(2))/3) + ((4*y(1))/3) + 2;
    end