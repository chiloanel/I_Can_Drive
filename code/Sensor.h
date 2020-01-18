class Sensor{
public:
Sensor(){distance = 400; // 400cm maximum ranging distance of ultrasonic sensor 
minObjectDistance = 40; 
}

void transReceiveSound(const int& trigPin, const int& echoPin ){
long tempDuration, duration;
duration = 0;

for(int circle = 0; circle != 5 ; circle++) // loop used to calculate the average of duration
{
digitalWrite(trigPin, LOW); //clears the trigPin
delayMicroseconds(2);              /*Change this time */
digitalWrite(trigPin, HIGH); //sets the trigPin on HIGH state for 10 micro seconds 
delayMicroseconds(10);
digitalWrite(trigPin, LOW); // reads the echoPin, returns the sound wave travel time in microseconds
tempDuration = pulseIn(echoPin, HIGH);
duration = duration+(tempDuration/5.00); // Takes the average of duration
}

updateDistance(duration);
}
  
void updateDistance(long duration){
distance = (duration/2) / 29.1; // calculates distance in centimeters
}


bool isObjectAdjacent(){return distance < minObjectDistance;}
long getDistance() {return distance;}

private:
long distance; // distance in centimeters
long minObjectDistance; // Minimum distance between receiver and object
};

