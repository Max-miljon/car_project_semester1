int motor1pin1 = 6;        //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D10
int motor2pin2 = 9;        //pin init4 = pin D9
int buttonPin = 20;        //button
int Speed = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}
void loop() {
    // Controleer of de knop is ingedrukt
    
    if (digitalRead(buttonPin) == LOW) { // Knop ingedrukt
        moveMotors();
        Serial.println(Speed);
    } else {
        stopMotors(); // Stop de motoren als de knop niet is ingedrukt
    }
}

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

int moveMotors() {
  // put your code here, to run repeatedly:
  //achteruit
  MotorBackward();
  delay(4000);
  //vooruit
  MotorForward();
  delay(4000);
  //rechts
  MotorRight();
  delay(3000);
  //links
  MotorLeft();
  delay(4000);
  
  
}
int Speed25(){
  Speed = 70;
  return Speed;
}
int Speed50(){
  Speed = 128;
  return Speed;
}
int Speed75(){
  Speed = 192;
  return Speed;
}
int Speed100(){
  Speed = 255;
  return Speed;
  
}
void stopMotors() {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}
