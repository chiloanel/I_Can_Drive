class Car{
public:
Car(){
 //Direction
 leftdir = 60;
 rightdir = 120;
 straightdir = 90;
 steering = 100;
 //Motion
 movingSpeed = 100;
 maxForwardSpeed = 50;
 minForwardSpeed = 95;
 maxReverseSpeed = 125;
 minReverseSpeed = 105;
 brakeSpeed = 100;
 //constants 
 acceleration = 0;
 }

void turnleft(){steering = leftdir;}
void turnright(){steering = rightdir;}
void turnstraight(){steering = straightdir;}

void moveForward(){ // derease from 100 to increase speed;
if (movingSpeed ==  brakeSpeed) {movingSpeed = minForwardSpeed;}  // start at min speed

if (movingSpeed > maxForwardSpeed && acceleration%50 == 0) {movingSpeed = movingSpeed-1;}
   acceleration++;
  }

void reverse(){ // increase from 100 to increase speed;
if (movingSpeed == brakeSpeed) {movingSpeed = minReverseSpeed;} // start at min speed

if(movingSpeed < maxReverseSpeed && acceleration%100 == 0) {movingSpeed = movingSpeed + 1;}
  acceleration++;
  }
void brake(){
  acceleration = 0;
  movingSpeed = brakeSpeed;}

// bools and getters
bool isCarMovingForward() {return movingSpeed <= minForwardSpeed;}
bool isCarReversing() {return movingSpeed >= minReverseSpeed;}
bool isCarNotMoving() {return movingSpeed == brakeSpeed;}
int getDirection() {return steering;}
int getSpeed() {return movingSpeed;}

private:
// Direction
int leftdir;
int rightdir;
int straightdir;
int steering; // needed
//motion
int  movingSpeed; // needed
int maxForwardSpeed;
int minForwardSpeed;
int maxReverseSpeed;
int minReverseSpeed;
int brakeSpeed;
//constants 
int acceleration;
};

