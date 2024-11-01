#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
void motorSetup();
void driveStraight();
void steerTankRight();
void steerTankLeft();
void driveReverse();
void stopMotors();
void MotorLeft();
void MotorRight();
void MotorForward();
void MotorBackward();
int Speed25();
int Speed50();
int Speed75();
int Speed100();
int getSlaveDirection(int LDValue, int LDValue1);
void getCommand(String command);
String UARTRead(Stream &stream);

#endif