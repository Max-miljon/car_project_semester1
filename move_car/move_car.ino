#include "Move_Car.h"

extern int motor1pin1;
extern int motor1pin2;
extern int motor2pin1;
extern int motor2pin2;
extern int Speed;
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(motor1pin1, OUTPUT);
//   pinMode(motor1pin2, OUTPUT);
//   pinMode(motor2pin1, OUTPUT);
//   pinMode(motor2pin2, OUTPUT);
//   pinMode(buttonPin, INPUT_PULLUP);
// }
// void loop() {
//     // Controleer of de knop is ingedrukt
    
//     if (digitalRead(buttonPin) == LOW) { // Knop ingedrukt
//         moveMotors();
//         Serial.println(Speed);
//     } else {
//         stopMotors(); // Stop de motoren als de knop niet is ingedrukt
//     }
// }

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

void stopMotors() {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}
