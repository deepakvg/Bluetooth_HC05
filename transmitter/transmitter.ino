
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
#define trigPin 6
#define echoPin 7

void setup() {
 
  Serial.begin(9600); //Communication rate serial monitor
  BTSerial.begin(38400);// Default communication rate of the Bluetooth module
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4,OUTPUT);
}

void loop() {


 long duration;
  float distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  digitalWrite(4, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
 BTSerial.print(distance); 
 BTSerial.print("\r");
 delay(500);
 
}
