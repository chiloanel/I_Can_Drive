
#define forward 10
#define backward 11


void setup() {
pinMode(forward, OUTPUT);
pinMode(backward, OUTPUT);

}

void loop() {
 analogWrite(forward, 255);
 delay(5000);
 analogWrite(forward, 0);
 delay(200);
 analogWrite(backward, 255);
 delay(5000);
 analogWrite(backward, 0);
 delay(200);

}
