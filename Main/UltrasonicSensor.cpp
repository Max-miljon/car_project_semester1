#include <Arduino.h>
#include "UltrasonicSensor.h"

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
unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 

void ultrasonicSetup() {
  for (int thisTrigPin = 0; thisTrigPin < trigPinCount; thisTrigPin++) {
    pinMode(trigPins[thisTrigPin], OUTPUT);
    digitalWrite(trigPins[thisTrigPin], LOW);
  }
  for (int thisEchoPin = 0; thisEchoPin < echoPinCount; thisEchoPin++) {
    pinMode(echoPins[thisEchoPin], INPUT);
  }
}

void sonicCalc() {
  long intervalMillis = 500;
  float duration;
  unsigned long currentMillis1 = millis();

  if (currentMillis1 - previousMillis1 >= intervalMillis) {
    previousMillis1 = currentMillis1;
    digitalWrite(trigPins[0], LOW);
    delayMicroseconds(2);
    digitalWrite(trigPins[0], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPins[0], LOW);
    duration = pulseIn(echoPins[0], HIGH, 30000);
    distance = (duration * 0.034) / 2;
    if (distance == 0) distance = 100;
  }
}

void sonicCalc2() {
  long intervalMillis2 = 100;
  float duration2;
  unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= intervalMillis2) {
    previousMillis2 = currentMillis2;
    digitalWrite(trigPins[1], LOW);
    delayMicroseconds(2);
    digitalWrite(trigPins[1], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPins[1], LOW);
    duration2 = pulseIn(echoPins[1], HIGH, 300000);
    distance2 = (duration2 * 0.034) / 2;
    if (distance2 == 0) distance2 = 100;
  }
}
