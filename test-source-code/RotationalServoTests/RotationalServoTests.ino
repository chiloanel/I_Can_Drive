#include <Servo.h>
// straight wheels - 75
// maximum left direction - 40
// maximum right direction - 110

Servo rotServo;

const byte steering = A5;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
rotServo.attach(steering);

}

void loop() {

 rotServo.write(40);
 delay(1000);
 rotServo.write(110);
 delay(1000);
 
}
