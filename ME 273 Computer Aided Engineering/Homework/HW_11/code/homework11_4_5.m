clc
clear all
close all

global t y dt;

L = 10;
R = -4;
initialguess = 2;
dtvec = [0.01 0.01];

yError = @(guess) shoot(guess) - R;

% figure(1)
% plot(t,y)

for n = 1:2
    dt = dtvec(n);
    fzero(yError, initialguess)
if n == 1
    t1 = t;
    y1 = y;
else
%     t2 = t;
%     y2 = y;
end
end

disp(y1(101))
disp(y1(201))
figure(1)
plot(t1, y1)
% , t2, y2)
xlabel('time')
ylabel('yfunc')
hold on
plot(0, L, 'o')
plot(3, R, 'o')
% legend(num2str(dtvec(1)), num2str(dtvec(2)))