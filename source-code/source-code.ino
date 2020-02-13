#include <Servo.h>
#include "Car.h"

  const byte wheel = 8;
  const byte steering = 9;
  const byte reverseLightPin = A5;
  const byte forwardLightPin = A4;
  const byte interruptStartButtonPin = 2;

  
  bool state = false;
  unsigned long bounce = 0; // debouncing
  Servo myservo;  
  Servo servo;
  Car mycar;

  String bluetoothValue = "";
  int  bluetoothValueInt = 0;

void setup() {
  Serial.begin(9600); // starts serial communication
  pinMode(reverseLightPin, OUTPUT);
  pinMode(forwardLightPin, OUTPUT);
  pinMode(interruptStartButtonPin, INPUT_PULLUP);
  myservo.attach(wheel); 
  servo.attach(steering);
  
  attachInterrupt(digitalPinToInterrupt(interruptStartButtonPin), statefunc, RISING);
  waitUntilStart(); // wait for start button
}

void loop (){

 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  
    bluetoothValue = Serial.readString(); // Reads the data from the serial port
 }


// DIRECTION
 if (bluetoothValue == "LEFT") { // left
 mycar.turnleft();
 }
 
 else if (bluetoothValue == "STRAIGHT") { // straight
  mycar.turnstraight();
 } 
 else if (bluetoothValue == "RIGHT"){ // right
  mycar.turnright();
 }

// MOTION 
 else if (bluetoothValue == "FORWARD") { // forward
  mycar.setForward();
  mycar.turnOnLight(forwardLightPin);
  mycar.turnOffLight(reverseLightPin);
 }
 
 else if (bluetoothValue == "REVERSE") { // reverse
  mycar.setReverse();
  mycar.turnOnLight(reverseLightPin);
  mycar.turnOffLight(forwardLightPin);
 } 
 
 else if (bluetoothValue == "BRAKE"){ // brake
 mycar.brake();
 mycar.turnOffLight(forwardLightPin);
 bluetoothValue = "";
 }

bluetoothValueInt = bluetoothValue.toInt();
if (bluetoothValueInt >= 0 && bluetoothValueInt <= 100 && mycar.isCarNotMoving() == false) {
    
 if (mycar.isCarMovingForward() == true) {mycar.accelerateForward(bluetoothValueInt);}
 else if (mycar.isCarReversing() == true) {mycar.accelerateReverse(bluetoothValueInt);}

}

servo.write(mycar.getDirection()); // print direction
myservo.write(mycar.getSpeed()); // print speed



if(state == false) {stopfunc();}

}

void statefunc() // this function is okay
{
  if (millis() - bounce < 200) {return;} // Debounce
  bounce = millis();
  
  state = !state;
}


void stopfunc()
{  
  mycar.turnOffLight(reverseLightPin);
  mycar.turnOffLight(forwardLightPin);
  mycar.brake();
  mycar.turnstraight();
  servo.write(mycar.getDirection());
  myservo.write(mycar.getSpeed());

  waitUntilStart();
}


void waitUntilStart(){
 while(state == false){delay(10);} // wait for start button
} 


