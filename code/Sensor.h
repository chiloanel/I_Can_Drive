long minObjectDistance = 30; //Minimum distance between receiver and object

class Sensor{
public:
Sensor(){distance = 400; //400cm maximum ranging distance of ultrasonic sensor 
objectDistance = 0;
}

void transReceiveSound(const int& trigPin, const int& echoPin ){
long tempDuration, duration;
duration = 0;

for(int circle = 0; circle != 10 ; circle++) // loop used to calculate the average of duration
{
digitalWrite(trigPin, LOW); //clears the trigPin
delayMicroseconds(2);              /*Change this time */
digitalWrite(trigPin, HIGH); //sets the trigPin on HIGH state for 10 micro seconds 
delayMicroseconds(10);
digitalWrite(trigPin, LOW); // reads the echoPin, returns the sound wave travel time in microseconds
tempDuration = pulseIn(echoPin, HIGH);
duration = duration+(tempDuration/10.00); // Takes the average of duration
}

updateDistance(duration);
}
  
void updateDistance(long duration){distance = (duration/58.2);} // calculates distance in centimeters || (duration/2) / 29.1
void storeObjectDistance(){objectDistance = distance;} // stores the object distance detected by the US
void clearObectDistace() {objectDistance = 0;} // clears the object distance

bool isObjectAdjacent(){return distance < minObjectDistance;}
bool isObjectDistanceCovered() {return distance > objectDistance;}
bool isReverseComplete() {return distance > 2*objectDistance;} //
long getDistance() {return distance;}

private:
long distance; // distance in centimeters
long objectDistance; // saves the distance of the receiver  
};

