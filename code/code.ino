#include <Servo.h>
#include "Car.h"
#include "Sensor.h"

#define trigPin 7
#define echoPin 6
#define wheel = 8
#define steering = 9

Servo myservo;  
Servo servo;
Car mycar;
Sensor detect;

void setup() {
Serial.begin(9600); // starts serial communication
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

myservo.attach(8); 
servo.attach(9);
delay (5000); // delay to start engine
}

void loop() {


detect.transReceiveSound(trigPin,echoPin); // Send and Receive sound all the time

/*LOGIC CODE*/
if (detect.isObjectAdjacent() == true && mycar.isCarMovingForward() == true && mycar.isCarReversing() == false) //object detected while the car is moving forward
{
 mycar.turnstraight();
 mycar.brake();
 detect.storeObjectDistance();
}

else if ( (mycar.isCarNotMoving()== true  || mycar.isCarReversing() == true) && detect.isReverseComplete() == false && mycar.isCarMovingForward() == false) //object detected after car stopped or when reversing
{
 mycar.turnleft();
 mycar.reverse();
}

else if (mycar.isCarReversing() == true && detect.isReverseComplete() == true && mycar.isCarMovingForward() == false)
{
   mycar.brake();
}



else  // When there is no object
{ 

if (mycar.moveRight() == true && (mycar.isCarMovingForward() == true || mycar.isCarNotMoving()== true))
{
  mycar.turnright();
}
else
{
mycar.turnstraight();
}
mycar.moveForward();

}


/*PRESENTATION*/
long speed_ = mycar.getSpeed();
Serial.println(speed_ , DEC);

servo.write(mycar.getDirection());
myservo.write(mycar.getSpeed());
//if (mycar.isCarNotMoving() == true) {delay(10);}
}
