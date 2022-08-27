/*
   DC Motor Brushed sketch
   commands from serial port control motor speed
   analog sin signal from 0-255 on pin 3 to demonstrate
   PWM control
*/
const int motorPins3 = 3;

void setup(){
  Serial.begin(9600);
}

void loop(){
  for(int i = 0; i<360; i++){
    //convert 0-360 angle to radian (needed for sin function)
    float rad = DEG_TO_RAD * i;
    
    //calculate sin of angle as number between 0 and 255
    int sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    
    analogWrite(motorPins3, sinOut);
    
    Serial.println(sinOut);
    delay(15);
  }
}
