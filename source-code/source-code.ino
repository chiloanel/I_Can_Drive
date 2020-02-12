#include <Servo.h>
#include "Car.h"

  const byte wheel = 8;
  const byte steering = 9;
  const byte reverseLightPin = A5;
  const byte forwardLightPin = A4;
  const byte interruptStartButtonPin = 2;

  
  bool state = false;
  int state_ = 0;
  unsigned long bounce = 0; // debouncing
  Servo myservo;  
  Servo servo;
  Car mycar;

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
    state_ = Serial.read(); // Reads the data from the serial port
 }


// DIRECTION
 if (state_ == 30) { // left
 mycar.turnleft();
 }
 
 else if (state_ == 35) { // straight
  mycar.turnstraight();
 } 
 else if (state == 40){ // right
  mycar.turnright();
 }

// MOTION 
 else if (state_ == 10) { // forward
  mycar.moveForward();
  mycar.turnOnLight(forwardLightPin);
  mycar.turnOffLight(reverseLightPin);
 }
 
 else if (state_ == 20) { // reverse
  mycar.reverse();
  mycar.turnOnLight(reverseLightPin);
  mycar.turnOffLight(forwardLightPin);
 } 
 
 else if (state == 15){ // brake
 mycar.brake();
 mycar.turnOffLight(forwardLightPin);
 state_ = 0;
 }

 else if (state == 5){ // stop increasing speed
 state_ = 0;
 }

servo.write(mycar.getDirection());
myservo.write(mycar.getSpeed());

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


