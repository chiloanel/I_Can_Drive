

float duration, distance; 

#define echoPin 6
#define trigPin 7


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // starts serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW); //clears the trigPin
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); //sets the trigPin on HIGH state for 10 micro seconds 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2.0) / 29.1;
  Serial.println(distance , DEC);

}
