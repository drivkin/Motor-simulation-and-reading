
close all;
figure

plot(ThetaEst);
hold all;
plot(ThetaReal);
legend('Estimated angular position','True angular position');
axis([1.5 4.5 -1 7]);

figure
plot(Torque)
hold all;
plot(Tcom);
legend('Torque produced','Torque commanded');
axis([1.5 4.5 -5*10^-3 5*10^-3]);