/*
ADXL335
note:vcc-->5v ,but ADXL335 Vs is 3.3V
The circuit:
      5V: VCC
analog A0: x-axis
analog A1: y-axis
analog A2: z-axis
*/


const byte xpin = A0;                  // x-axis of the accelerometer
const byte ypin = A1;                  // y-axis
const byte zpin = A2;                  // z-axis (only on 3-axis models)


void setup()
{
 Serial.begin(9600); // initialize the serial communications:
}


void loop()
{
int x = analogRead(xpin);  //read from xpin
 
int y = analogRead(ypin);  //read from ypin
 
int z = analogRead(zpin);  //read from zpin

// gravitity measurements

// Calculations
// 388 - reference point 
// (Orthogonal - 388) / 6.939 = 9.8 m/s^2
/*
Serial.print(((float)x - 338)/6.939);  //print x value on serial monitor
Serial.print("\t");
Serial.print(((float)y - 338)/6.939);  //print y value on serial monitor
Serial.print("\t");
Serial.print(((float)z - 343.5)/6.99);  //print z value on serial monitor
Serial.print("\n"); */

//angle measurements
// Calculations
// 388 - reference point 
// (Orthogonal - 388)*1.3235 = 90 degrees 
Serial.print(((float)x - 337.5)*1.3235);  //print x value on serial monitor
Serial.print("\t");
Serial.print(((float)y - 338.5)*1.3235);  //print y value on serial monitor
Serial.print("\t");
Serial.print(((float)z - 343)*1.3139);  //print z value on serial monitor
Serial.print("\n");


delay(100);
}
