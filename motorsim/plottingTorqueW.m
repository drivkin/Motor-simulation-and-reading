figure
title('Torque Production Using Interpolated Rotor Speed');

subplot(1,3,1)
plot(Tcom);
hold on
plot(Torque,'g');
title('Torque');
legend('Commanded Torque','Produced Torque');

subplot(1,3,2)
plot(Wreal);
hold on;
plot(Winterp,'g');
legend('Actual','Estimated');
title('Rotor Speed (Electrical)');

subplot(1,3,3)
plot(ThetaReal);
hold on;
plot(ThetaEst,'g');
legend('Actual','Estimated');
title('Electrical Rotor Angle');
