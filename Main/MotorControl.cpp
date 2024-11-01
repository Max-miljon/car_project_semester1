#include <Arduino.h>
#include "MotorControl.h"

extern int motor1pin1;
extern int motor1pin2;
extern int motor2pin1;
extern int motor2pin2;

void driveStraight() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  analogWrite(motor2pin1, 50);
  analogWrite(motor2pin2, 50);
}

void steerTankRight() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, 55);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, 55);
}

void steerTankLeft() {
  digitalWrite(motor1pin1, 55);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, 55);
  digitalWrite(motor2pin2, LOW);
}

void driveReverse() {
  analogWrite(motor1pin1, 140);
  analogWrite(motor1pin2, 140);
  analogWrite(motor2pin1, LOW);
  analogWrite(motor2pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

int getSlaveDirection(int LDValue, int LDValue1) {
  if (LDValue == 0 && LDValue1 == 1) return -1;  // Right
  if (LDValue1 == 0 && LDValue == 1) return 1;   // Left
  if (LDValue1 == 1 && LDValue == 1) return 0;   // Straight
  return 0;
}