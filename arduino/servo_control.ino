/*
  servo potentiometer control
*/

#include <Servo.h>

Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Attach the ESC on pin 9 (pin, min pulse width, max pulse width in microseconds) 
  ESC.attach(9,1000,2000);
}

// the loop routine runs over and over again forever:
void loop() {
  // reads the value of the potentiometer (value between 0 and 1023)
  potValue = analogRead(A0);

  // scale it to use it with the servo library (value between 0 and 180)
  potValue = map(potValue, 0, 1023, 0, 180);

  // Send the signal to the ESC
  ESC.write(potValue);
  
  // print out the value you read:
  Serial.println(potValue);

  // delay in between reads for stability
  delay(1);
}
