#include <Arduino.h>
#include <SoftwareSerial.h>
#include "MotorControl.h"
int K2L = 0;
SoftwareSerial Serial2(8, 7); // RX, TX for HM-10
// Define commands
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
int buttonPin = 20;        //button
int Speed = 64;

void bluethoothSetup() {
    Serial.begin(9600);       // Start USB Serial for debugging
    Serial2.begin(9600);      // Start HM-10 Serial communication
    Serial.println("HM-10 Bluetooth Module Ready");
    motorSetup();
    pinMode(buttonPin, INPUT_PULLUP);
}

void bluethoothMode() {
K2L = 0;
while(K2L == 0)
{
    int K1 = digitalRead(buttonPin);
    if (K1 == LOW) 
    {
    K2L = 1;
    stopMotors();
    break;
    }
    // UARTStringAvailable()
    // Check for data from HM-10 and relay to Serial Monitor
    while (Serial2.available()) {
        String receivedText = UARTRead(Serial2); // Read until newline
        Serial.print("Received: ");
        Serial.println(receivedText); // Print received data to Serial Monitor
        
        // Handle command
        getCommand(receivedText);
        if (K1 == LOW) 
        {
        K2L = 1;
        stopMotors();
        break;
        }
    }

    // Check for data from Serial Monitor and relay to HM-10
    while (Serial.available()) {
        String sendText = UARTRead(Serial); // Read until newline
        Serial2.println(sendText); // Send data to HM-10
        Serial.print("Sent: ");
        Serial.println(sendText); // Print sent data to Serial Monitor
        if (K1 == LOW) 
        {
        K2L = 1;
        stopMotors();
        break;
        }
    }
}   
}


