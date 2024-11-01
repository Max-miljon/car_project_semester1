#include "SLAVEMODEV3.h"
#include "BluetoothMode.h"
#include "AutonoomMode.h"
#include "MotorControl.h"
#include <LiquidCrystal_I2C.h>
#define BUTTON 20
#define INTERVAL 200
#define SELECTDELAY 5000
unsigned long lastButtonPressTime;
LiquidCrystal_I2C lcd(0x27,16,2);
int mode = 0;
void setup() 
{
Serial.begin(9600);
Serial.println("main");
lcd.init();
lcd.backlight();
pinMode(BUTTON, INPUT_PULLUP);
}

void loop() 
{
  int K1 = digitalRead(BUTTON);
  unsigned long currentMillis = millis();
  lcd.setCursor(0,0);
  lcd.print("Mode selection");
  lcd.setCursor(0,1);
  lcd.print("Mode:");
  lcd.setCursor(6,1);
  lcd.print(mode);
  //buttoncheck
  if (K1 == LOW && currentMillis - lastButtonPressTime > INTERVAL) 
  {
    lastButtonPressTime = currentMillis;
    mode ++;
    Serial.println(mode);
  }

  //5 sec to select next mode
  if (mode > 0 && currentMillis - lastButtonPressTime > SELECTDELAY) 
  {
   if (mode == 1)
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SlaveMode");
    slaveSetup(); 
    slaveMode();
    mode = 0;
   }
   if (mode == 2)
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BluethoothMode");
    bluethoothSetup();
    bluethoothMode();
    mode = 0;
   }
   if (mode == 3)
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AutonoomMode");
    autonoomSetup();
    autonoomMode();
    stopMotors();
    mode = 0;
   }
  }
  
  if (mode > 3)
  {
    mode = 0;
  }
}
