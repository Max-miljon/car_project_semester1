// download HCSR04 ultrasonic sensor by gamegine in library

#include <HCSR04.h>


float distance;
float distance2;
const int trigPins[] = {
  12, 13
};
int trigPinCount = 2;
const int echoPins[] = {
  2, 3
};
int echoPinCount = 2;

int motor1pin1 = 6;       //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D11
int motor2pin2 = 9;       //pin init4 = pin D9

void setup() {
  ultrasonicSetup();
}

void loop() {
  sonicCalc();
  sonicCalc2();

  if (distance <= 20) {
    steerTankRight();
   } else if (distance2 <= 20) {
    steerTankLeft();
   } else {
    driveStraight();
   }
}

void sonicCalc() {
  float duration;
  unsigned long previousMillis = 0;
  long intervalMillis = 100;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalMillis) {
    previousMillis = currentMillis;

    digitalWrite(12, LOW);
    delayMicroseconds(2);
    digitalWrite(12, HIGH);
    delayMicroseconds(10);
    digitalWrite(12, LOW);

    duration = pulseIn(2, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);   
  }
  return distance;
}

void sonicCalc2() {
  float duration2;
  unsigned long previousMillis2 = 0;
  long intervalMillis2 = 100;

  unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= intervalMillis2) {
    previousMillis2 = currentMillis2;
    digitalWrite(13, LOW);
    delayMicroseconds(2);
    digitalWrite(13, HIGH); 
    delayMicroseconds(10);
    digitalWrite(13, LOW);
    
    duration2 = pulseIn(3, HIGH);
    distance2 = (duration2*.0343)/2;
    Serial.print("Distance2: ");
    Serial.println(distance2);
  }
  return distance2;
}

void driveStraight()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  analogWrite(motor2pin1, 150);
  analogWrite(motor2pin2, 150);
}

void steerTankRight()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);  
}

void steerTankLeft()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void ultrasonicSetup() {
  for (int thisTrigPin; thisTrigPin < trigPinCount; thisTrigPin++) {
    pinMode(trigPins[thisTrigPin], OUTPUT);
  }
  for (int thisEchoPin; thisEchoPin < echoPinCount; thisEchoPin++) {
    pinMode(echoPins[thisEchoPin], INPUT);
  }
  Serial.begin(9600);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}