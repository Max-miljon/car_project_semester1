#include <Arduino.h>
#include "MotorControl.h"
#include <SoftwareSerial.h>
SoftwareSerial Serial1(8, 7); // RX, TX for HM-10
const String COMMAND_FORWARD = "F";
const String COMMAND_BACKWARD = "B";
const String COMMAND_LEFT = "L";
const String COMMAND_RIGHT = "R";
const String COMMAND_STOP = "S";
const String COMMAND_AUTONOOM = "A";
const String COMMAND_SLAVE = "N";
const String COMMAND_RC = "C";
const String COMMAND_SPEED1 = "1";
const String COMMAND_SPEED2 = "2";
const String COMMAND_SPEED3 = "3";
const String COMMAND_SPEED4 = "4";
int motor1pin1 = 6;       //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D11
int motor2pin2 = 9; 

extern int Speed;
void motorSetup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}
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

void MotorLeft(){

  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);

  analogWrite(motor1pin1, Speed);
  analogWrite(motor2pin1, Speed);

}
void MotorRight(){
  analogWrite(motor1pin2, Speed);
  analogWrite(motor2pin2, Speed);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor2pin1, LOW);

}
void MotorForward(){
  digitalWrite(motor1pin2, LOW);
  analogWrite(motor2pin2, Speed);

  digitalWrite(motor1pin1, LOW);
  analogWrite(motor2pin1, Speed);

}
void MotorBackward(){
  analogWrite(motor1pin2, Speed);
  digitalWrite(motor2pin2, LOW);

  analogWrite(motor1pin1, Speed);
  digitalWrite(motor2pin1, LOW);
}


int Speed25(){
  Speed = 64;
  return Speed;
}
int Speed50(){
  Speed = 128;
  return Speed;
}
int Speed75(){
  Speed = 192;
  return Speed;
}
int Speed100(){
  Speed = 255;
  return Speed;
  
}

void getCommand(String command) {
    command.toUpperCase();
    if (command == COMMAND_FORWARD) {
        // Code to move forward
        Serial1.println("Moving forward");
        Serial.println("Command: Move Forward");
        MotorForward();
    } else if (command == COMMAND_BACKWARD) {
        // Code to move backward
        Serial1.println("Moving backward");
        Serial.println("Command: Move Backward");
        MotorBackward();
    } else if (command == COMMAND_LEFT) {
        // Code to move left
        Serial1.println("Moving left");
        Serial.println("Command: Move left");
        MotorLeft();
    } else if (command == COMMAND_RIGHT) {
        // Code to move right
        Serial1.println("Moving right");
        Serial.println("Command: Move right");
        MotorRight();
    } else if (command == COMMAND_STOP) {
        // Code to stop
        Serial1.println("Stopping");
        Serial.println("Command: Stop");
        stopMotors();
    } else if (command == COMMAND_AUTONOOM ) {
        // Code for autnoom mode
        Serial1.println("In autonoom mode");
        Serial.println("Command: Autonoom");
    } else if (command == COMMAND_SLAVE) {
        // Code for slave mode
        Serial1.println("In slave mode");
        Serial.println("Command: Slave");
    } else if (command == COMMAND_RC) {
        // Code for rc mode
        Serial1.println("In RC mode");
        Serial.println("Command: RC");
    } else if (command == COMMAND_SPEED1) {
        // Code for 25% speed
        Serial1.println("Going to 25% speed");
        Serial.println("Command: 25% speed");
        Speed25();
    } else if (command == COMMAND_SPEED2) {
        // Code for 50% speed
        Serial1.println("Going to 50% speed");
        Serial.println("Command: 50% speed");
        Speed50();
    } else if (command == COMMAND_SPEED3) {
        // Code for 75% speed
        Serial1.println("Going to 75% speed");
        Serial.println("Command: 75% speed");
        Speed75();
    } else if (command == COMMAND_SPEED4) {
        // Code for 100% speed
        Serial1.println("Going to 100% speed");
        Serial.println("Command: 100% speed");
        Speed100();
    } else {
        // Code for unknown command
        Serial1.println("Unknown command");
        Serial.println("Command: Unknown");
    }
}

String UARTRead(Stream &stream) {
    String text = "";
    while (stream.available()) {
        char c = stream.read();
        if (c == '\n') break; // Stop reading at newline
        text += c; // Append character to the string
    }
    return text;
}
