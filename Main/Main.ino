#include "Move_Car.h"

//Motor pins
int motor1pin1 = 6;        //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D10
int motor2pin2 = 9;        //pin init4 = pin D9
int buttonPin = 20;        //button

//speed
int Speed = 100;             // speed of the car 

void setup() {
  // begin
  Serial.begin(9600);
  // pinmode motors
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  Serial.println(Speed);
  if (digitalRead(buttonPin) == LOW) { // Knop ingedrukt
        moveMotors();
        Serial.println(Speed);
    } else {
        stopMotors(); // Stop de motoren als de knop niet is ingedrukt
    }

}
