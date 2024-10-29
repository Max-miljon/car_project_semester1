#include <HCSR04.h>
#define LDpin1 4
#define LDpin2 5
int motor1pin1 = 6;       //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D11
int motor2pin2 = 9;       //pin init4 = pin D9
unsigned long lastSteerTime = 0;  
int turningState = 0;             
unsigned long turningDuration = 100;
//distance measurement vars
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

int getSlaveDirection(int LDValue, int LDValue1) {
  if (LDValue == 0 && LDValue1 == 1) {
    return -1;  // Right
  }

  if (LDValue1 == 0 && LDValue == 1) {
    return 1;  // Left
  }

  if (LDValue1 == 1 && LDValue == 1) {
    return 0;  // Straight
  }

  return 0;
}

void driveStraight()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  analogWrite(motor2pin1, 100);
  analogWrite(motor2pin2, 100);
}

void steerTankRight()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, 200);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, 200);  
}

void steerTankLeft()
{
  digitalWrite(motor1pin1, 200);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, 200);
  digitalWrite(motor2pin2, LOW);
}

void driveReverse()
{
  analogWrite(motor1pin1, 140);
  analogWrite(motor1pin2, 140);

  analogWrite(motor2pin1, LOW);
  analogWrite(motor2pin2, LOW);
}

void stopMotors()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void sonicCalc()
{
  long intervalMillis = 500;
  float duration;
  unsigned long currentMillis1 = millis();

  if (currentMillis1 - previousMillis1 >= intervalMillis) 
  {
    previousMillis1 = currentMillis1;

    digitalWrite(12, LOW);
    delayMicroseconds(2);
    digitalWrite(12, HIGH);
    delayMicroseconds(10);
    digitalWrite(12, LOW);

    duration = pulseIn(echoPins[0], HIGH, 30000);
    distance = (duration*0.034)/2; 
    Serial.println("distance1");
    Serial.println(distance);
  }

  if (distance == 0) 
  {
    distance = 100;
  }
}

void sonicCalc2() 
{
  long intervalMillis2 = 100;
  float duration2;
  unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= intervalMillis2) {
    previousMillis2 = currentMillis2;
    digitalWrite(13, LOW);
    delayMicroseconds(2);
    digitalWrite(13, HIGH); 
    delayMicroseconds(10);
    digitalWrite(13, LOW);
    
    duration2 = pulseIn(echoPins[1], HIGH, 30000);
    distance2 = (duration2*0.034)/2;
    Serial.println("distance2:");
    Serial.println(distance2);
  }
    if (distance2 == 0) 
  {
    distance2 = 100;
  }
}

void ultrasonicSetup() 
{
  for (int thisTrigPin = 0; thisTrigPin < trigPinCount; thisTrigPin++) 
  {
    pinMode(trigPins[thisTrigPin], OUTPUT);
    digitalWrite(trigPins[thisTrigPin], LOW);
  }
  for (int thisEchoPin = 0; thisEchoPin < echoPinCount; thisEchoPin++) 
  {
    pinMode(echoPins[thisEchoPin], INPUT);
  }
}