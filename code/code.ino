#include "Car.h"
#include "Sensor.h"


#define trigPin 7
#define echoPin 6
#define wheel = 8
#define steering = 9


Car mycar;
Sensor detect;

void setup() {
Serial.begin(9600); // starts serial communication
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

//myservo.attach(8); 
//servo.attach(9);

delay (5000); // delay to start engine
}

void loop() {

detect.transReceiveSound(trigPin,echoPin); // Send and Receive sound all the time

/*LOGIC CODE*/
if (detect.isObjectAdjacent() == true && mycar.isCarMovingForward()) // object detected while the car is moving forward
{
 mycar.brake();
}

else if (detect.isObjectAdjacent() == true && (mycar.isCarNotMoving()== true  || mycar.isCarReversing()) ) // object detected after car stopped or when reversing
{
 mycar.turnleft();
 mycar.reverse();
}

else if (detect.isObjectAdjacent() == false && mycar.isCarReversing() == true)
{
   // 
}


else  // When there is no object
{
mycar.turnstraight();
mycar.moveForward();
}

/*PRESENTATION*/

//servo.write(mycar.getDirection());
//myservo.write(mycar.getSpeed());
}
