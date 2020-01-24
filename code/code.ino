#include <Servo.h>
#include "Car.h"
#include "Sensor.h"


#define echoPin 6
#define trigPin 7

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
  Sensor detect;

void setup() {
  Serial.begin(9600); // starts serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(reverseLightPin, OUTPUT);
  pinMode(forwardLightPin, OUTPUT);
  pinMode(interruptStartButtonPin, INPUT_PULLUP);
  myservo.attach(wheel); 
  servo.attach(steering);
  
  attachInterrupt(digitalPinToInterrupt(interruptStartButtonPin), statefunc, RISING);
  waitUntilStart(); // wait for start button
}

void loop (){

//LOGIC CODE

detect.transReceiveSound(trigPin,echoPin); // Send and Receive sound all the time

if (detect.isObjectAdjacent() == true && mycar.isCarMovingForward() == true && mycar.isCarReversing() == false) //object detected while the car is moving forward
{
  mycar.turnstraight();
  mycar.brake();
  detect.storeObjectDistance();
  mycar.turnOnLight(reverseLightPin);
  mycar.turnOffLight(forwardLightPin);
}

else if ( (mycar.isCarNotMoving()== true  || mycar.isCarReversing() == true) && detect.isReverseComplete() == false && mycar.isCarMovingForward() == false) //object detected after car stopped or when reversing
{
  mycar.turnleft();
  mycar.reverse();
  mycar.turnOnLight(reverseLightPin);
}

else if (mycar.isCarReversing() == true && detect.isReverseComplete() == true && mycar.isCarMovingForward() == false) // after reversing
{
   mycar.brake();
}

else  // When there is no object
{ 
  mycar.turnOffLight(reverseLightPin);
  mycar.turnOnLight(forwardLightPin);

    if (mycar.moveRight() == true)
    {
      mycar.turnright();
    }
    else
    {
      mycar.turnstraight();
    }

  mycar.moveForward();
}

//PRESENTATION
//long speed_ = mycar.getSpeed();
//Serial.println(speed_ , DEC);

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

