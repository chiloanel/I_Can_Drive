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

  int bluetoothValue = 0;
  String bluetoothValueString = "";
  int bluetoothValueInt = 0;

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

bluetoothValue =  Serial.read();

//Serial.println(bluetoothValue);
//Serial.println('/n');  
   
 }




// DIRECTION
 if (bluetoothValue == 'L') { // left
 mycar.turnleft();
 }
 
 else if (bluetoothValue == 'S') { // straight
  mycar.turnstraight();
 } 
 else if (bluetoothValue == 'R'){ // right
  mycar.turnright();
 }

// MOTION 
 else if (bluetoothValue == 'F') { // forward
  mycar.setForward();
  mycar.turnOnLight(forwardLightPin);
  mycar.turnOffLight(reverseLightPin);
 }
 
 else if (bluetoothValue == 'r') { // Back or reverse
  mycar.setReverse();
  mycar.turnOnLight(reverseLightPin);
  mycar.turnOffLight(forwardLightPin);
 } 
 
 else if (bluetoothValue == 'B'){ // brake
 mycar.brake();
 mycar.turnOffLight(forwardLightPin);
 bluetoothValue = 0;
 }

//bluetoothValueInt = bluetoothValueString.toInt();
if (bluetoothValue >= 150 && bluetoothValue <= 250 && mycar.isCarNotMoving() == false) {
    
 if (mycar.isCarMovingForward() == true) {mycar.accelerateForward(bluetoothValue);}
 else if (mycar.isCarReversing() == true) {mycar.accelerateReverse(bluetoothValue);}

}


servo.write(mycar.getDirection()); // print direction

if ( bluetoothValue != 'R' || bluetoothValue != 'L' || bluetoothValue != 'S')

{ myservo.write(mycar.getSpeed()); // print speed
}



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


