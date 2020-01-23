const byte PIR_SensorPin = 2;
const byte LED_pin = A1;
volatile byte state = LOW;


void setup() {
   pinMode (LED_pin, OUTPUT);
   pinMode(PIR_SensorPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(PIR_SensorPin), stateChange, RISING);
}

void loop() {
   digitalWrite(LED_pin ,state);
}

void stateChange(){state = !state;}

