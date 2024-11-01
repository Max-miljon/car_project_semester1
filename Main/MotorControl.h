#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void driveStraight();
void steerTankRight();
void steerTankLeft();
void driveReverse();
void stopMotors();
int getSlaveDirection(int LDValue, int LDValue1);

#endif