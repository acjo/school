clc
clear all
close all

%we will use these for plotting our exact function
tinit = 0;
tfinal = 30;
dt = 0.01;
A = 71.7; %ambient air temp

%reading in file
fileID = fopen('tempvalues.txt');
formatSpec = '%f';
TTemp = fscanf(fileID, formatSpec);
fclose(fileID);

%fscanf gives us a column vec we want a row vec
Temp = transpose(TTemp);
n = length(Temp);
%getting our times
t = zeros(1, n);
for i = 1:n
    t( i ) = ( i - 1 ) * 3;
end
figure(1)
plot(t, Temp, 'k x')
xlabel('Time')
ylabel('Temperature (F)')
grid on
[P,S] = polyfit(t, Temp, 1);
time = tinit:dt:tfinal;
TempPoly = polyval(P, time);
hold on
plot(time, TempPoly, 'g -', 'linewidth', 1.5);

%computing the r^2 value
r2val = 1 - (S.normr/norm(Temp - mean(Temp)))^2

%plotting Newton's Law of Cooling
alpha = A - Temp(1);
k = -0.5 * log((Temp(2) - A) / -alpha);
NewtonCooling = @(t) A - alpha * exp(-k * t);
N = length(time);
funcVal = zeros(1,N);
for i = 1:N
   funcVal(i) = NewtonCooling(time(i)); 
end


hold on
plot(time, funcVal, 'r -', 'linewidth', 1.5)
legend('Measured Temp', 'Line of Best Fit', 'Newton''s Law of Cooling')

















