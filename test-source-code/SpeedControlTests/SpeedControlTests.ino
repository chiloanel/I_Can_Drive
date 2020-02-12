#include <Servo.h>

Servo servo;

const byte fowardPin = 9;
const byte reversePin = 8;


void setup() {
  // put your setup code here, to run once:

servo.attach(fowardPin);


}

void loop() {

 servo.write(100);

}
