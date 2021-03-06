const float minObjectDistance_ = 25;

class Car{
public:
Car(){
 //Direction
  leftdir = 40;
  rightdir = 110;
  straightdir = 75;
  steering = 75;
 //Motion
  movingSpeed = 100;
  maxForwardSpeed = 30;
  minForwardSpeed = 95;
  maxReverseSpeed = 200;
  minReverseSpeed = 102;
  brakeSpeed = 101;
 //constants 
  reverseAcceleration = 0.2;
  forwardAcceleration = 0.05;

  moveRightDistance = 0;
 }

void turnleft(){steering = leftdir;}
void turnright(){steering = rightdir;}
void turnstraight(){steering = straightdir;}

void moveForward(){ // subract from 100 to increase speed;
if (movingSpeed ==  brakeSpeed) {movingSpeed = minForwardSpeed;}  // start at min speed

if (movingSpeed > maxForwardSpeed) {movingSpeed = movingSpeed-forwardAcceleration;}
  }  

void reverse(){ // add from 100 to increase speed;
if (movingSpeed == brakeSpeed) {movingSpeed = minReverseSpeed;} // start at min speed

if(movingSpeed < maxReverseSpeed) {movingSpeed = movingSpeed+reverseAcceleration;}

  }
void brake(){movingSpeed = brakeSpeed;
//moveRightDistance = 0;
} // stop the wheels

// Control for bluetooth system
void setForward() {movingSpeed = minForwardSpeed;}
void setReverse() {movingSpeed = minReverseSpeed;}

void accelerateForward(int& bluetoothValueInt){
  movingSpeed = minForwardSpeed-bluetoothValueInt-150;
  }

void accelerateReverse(int& bluetoothValueInt){
  movingSpeed = minReverseSpeed+bluetoothValueInt-150;
  }


void turnOnLight(const byte &reverseLightPin){ // turn the LED on
    digitalWrite(reverseLightPin, HIGH);   
  }
void turnOffLight(const byte& reverseLightPin){ // turn the LED off
    digitalWrite(reverseLightPin, LOW);    
    }

// bools and getters
bool isCarMovingForward() {return movingSpeed <= minForwardSpeed;}
bool isCarReversing() {return movingSpeed >= minReverseSpeed;}
bool isCarNotMoving() {return movingSpeed == brakeSpeed;}
bool moveRight() {
  moveRightDistance = moveRightDistance+1;
  return moveRightDistance < minObjectDistance_;}
int getDirection() {return steering;}
float getSpeed() {return movingSpeed;}

private:
  // Direction
  int leftdir;
  int rightdir;
  int straightdir;
  int steering; // needed
  //motion
  float movingSpeed; // needed
  float maxForwardSpeed;
  float minForwardSpeed;
  float maxReverseSpeed;
  float minReverseSpeed;
  float brakeSpeed;
  //constants 
  float reverseAcceleration;
  float forwardAcceleration;
  
  float moveRightDistance;
};

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
