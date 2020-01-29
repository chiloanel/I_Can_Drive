#include <Servo.h>

Servo servo;

const byte steering = 9;


void setup() {
  // put your setup code here, to run once:

servo.attach(steering);


}

void loop() {

 servo.write(140);

}
