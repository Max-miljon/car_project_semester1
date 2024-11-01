//HCSR04 ultrasonic sensor by gamegine
#include <HCSR04.h>
#include "MotorControl.h"
#include "UltrasonicSensor.h"
#include <LiquidCrystal_I2C.h>
int K3L = 0;

void autonoomSetup() {
  ultrasonicSetup();
}

void autonoomMode() {
K3L = 0;
while (K3L == 0)
{
    int K1 = digitalRead(20);
    if (K1 == LOW) 
    {
    stopMotors();
    K3L = 1;
    }
  sonicCalc();
  sonicCalc2();
  
  if (distance <= 10) {
    steerTankRight();
   } else if (distance2 <= 10) {
    steerTankLeft();
   } else {
    driveStraight();
   }
}   
}
