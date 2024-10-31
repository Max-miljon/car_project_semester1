#include <HCSR04.h>
#include "MotorControl.h"
#include "UltrasonicSensor.h"
#define LDpin1 4
#define LDpin2 5
int motor1pin1 = 6;       //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D11
int motor2pin2 = 9;       //pin init4 = pin D9
unsigned long lastSteerTime = 0;  
int turningState = 0;             
unsigned long turningDuration = 50; 

void setup() 
{
  Serial.begin(9600);
  Serial.println("slave");
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  ultrasonicSetup();
}

void loop() 
{
  unsigned long currentMillis = millis();
  // slave mode directions
  int directionX = getSlaveDirection(digitalRead(LDpin1), digitalRead(LDpin2));
  // straight
  if (directionX == 0) 
  {
   driveStraight();
  }

  // right tank
  else if (directionX == -1) 
  {
    turningState = -1;
    lastSteerTime = currentMillis;
    steerTankRight();
  }

  // left tank
  else if (directionX == 1) {
    turningState = 1;
    lastSteerTime = currentMillis;
    steerTankLeft();
  }

  //keep turning
  if (directionX == 0 && (currentMillis - lastSteerTime <= turningDuration)) 
  {
   while(currentMillis - lastSteerTime <= turningDuration)
   {
    currentMillis = millis();
    if (turningState == -1)
    {
    steerTankRight();
    }
    if (turningState == 1)
    {
    steerTankLeft();
    }
    if (turningState == 0)
    {
      break;
    }
   }
  }
  sonicCalc();
  sonicCalc2(); 
   while (distance < 7 || distance2 < 7)
   {
    stopMotors(); 
    sonicCalc();
    sonicCalc2();
    if (distance > 7 || distance2 > 7)
    {
      break;
    }
   }
}
