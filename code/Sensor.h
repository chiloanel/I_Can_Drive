const float minObjectDistance = 30; // Minimum distance between receiver and object
float duration = 0; // time taken to receive the sound sent

class Sensor{
public:
Sensor()
{
  distance = 400.0; // 400cm maximum ranging distance of ultrasonic sensor 
  objectDistance = 0.0;
}

void transReceiveSound(const int& trigPin, const int& echoPin )
{
  digitalWrite(trigPin, LOW); //clears the trigPin
  delayMicroseconds(2);              /*Change this time */
  noInterrupts(); // disable interrupts as they might interfere with the measurement
  digitalWrite(trigPin, HIGH); //sets the trigPin on HIGH state for 10 micro seconds 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  interrupts(); // enable interrupts, we are done with the measurement
  if (duration == 0.0){ return;} // error
  
  updateDistance(duration);
}
  
void updateDistance(const float& duration) // calculates distance in centimeters
{
  distance = (duration/2.0) / 29.1;
  Serial.println(distance , DEC);
}

void storeObjectDistance(){objectDistance = distance;} // stores the object distance detected by the US
void clearObectDistace(){objectDistance = 0.0;} // clears the object distance

bool isObjectAdjacent(){return distance < minObjectDistance;}
bool isObjectDistanceCovered() {return distance > objectDistance;}
bool isReverseComplete() {return distance > 2.0*objectDistance;} //
float getDistance() {return distance;}

private:
float distance; // distance in centimeters
float objectDistance; // saves the distance of the receiver  
};

