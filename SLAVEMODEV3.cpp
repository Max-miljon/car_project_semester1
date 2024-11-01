#include <HCSR04.h>
#include "MotorControl.h"
#include "UltrasonicSensor.h"
#include <LiquidCrystal_I2C.h>
#define LDpin1 4
#define LDpin2 5
#define INTERVAL 150
#define BUTTON 20
unsigned long lastSteerTime = 0;  
int turningState = 0;             
unsigned long turningDuration = 50; 
unsigned long lastButtonPressTime1 = 0;
int K1L = 0;
void slaveSetup() 
{
  Serial.begin(9600);
  Serial.println("slave");
  ultrasonicSetup();
  motorSetup();
  pinMode(BUTTON, INPUT_PULLUP);
}

void slaveMode() 
{
K1L = 0;
while(K1L == 0)
{
  int K1 = digitalRead(BUTTON);
  unsigned long currentMillis = millis();
  if (K1 == LOW || K1L == 1 && currentMillis - lastButtonPressTime1 > INTERVAL) 
  {
    stopMotors();
    K1L = 1;
    lastButtonPressTime1 = currentMillis;
    break;
  }
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
    if (K1 == LOW) 
    {
    K1L = 1;
    lastButtonPressTime1 = currentMillis;
    stopMotors();
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
  if (K1 == LOW) 
  {
    K1L = 1;
    lastButtonPressTime1 = currentMillis;
    stopMotors();
    break;
  }
  }
}
}
