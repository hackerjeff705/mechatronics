/*
   Multiple DC Motor Brushed sketch
   potentiometer values are mapped from 0-255
   and fed to motors in pins 3 and 11
*/
const int motorPins3 = 3; // motor driver is connected to pin 3
const int motorPins11 = 11;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  int speed = map(sensorValue, 0, 1023, 0, 255);

  // pin 3, 6,9,10,11 clocks are in sync use these pins for motor
  // (check hardware specs & schematics)
  analogWrite(motorPins3, speed);
  analogWrite(motorPins11, speed);
  
  Serial.println(speed);
  delay(1);
}
