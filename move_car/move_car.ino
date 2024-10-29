int motor1pin1 = 6;       //pin init3 =pin D6
int motor1pin2 = 11;       //pin init1 =pin D11
int motor2pin1 = 10;       //pin init2 =pin D10
int motor2pin2 = 9;       //pin init4 = pin D9
int buttonPin = 20;        //button
int Snelheid;
void setup() {
  // put your setup code here, to run once:
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
    } else {
        stopMotors(); // Stop de motoren als de knop niet is ingedrukt
    }
}
void MotorLinks(){
  Snelheid = Snelheid25();
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);

  analogWrite(motor1pin1, Snelheid);
  analogWrite(motor2pin1, Snelheid);

}
void MotorRechts(){
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor2pin1, LOW);

}
void MotorVooruit(){
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor2pin1, HIGH);

}
void MotorAchteruit(){
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor2pin1, LOW);
}

int moveMotors() {
  // put your main code here, to run repeatedly:
  //achteruit
  MotorAchteruit();
  delay(10000)
  //vooruit
  MotorVooruit();
  delay(10000)
  //rechts
  MotorRechts();
  delay(10000)
  //links

  MotorLinks();
  delay(10000)
  
}
int Snelheid25(){
  Snelheid = 64;
  return Snelheid;
}
int Snelheid50(){
  Snelheid = 128;
  return Snelheid;
}
int Snelheid75(){
  Snelheid = 192;
  return Snelheid;
}
int Snelheid100(){
  Snelheid = 255;
  return Snelheid;
  
}
void stopMotors() {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}
