
#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(10, 11);

int bluetoothTx = 10; 
int bluetoothRx = 11;
String content; //content buffer

char character;


SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup(){
  bluetooth.begin(38400);
  Serial.begin(9600);
}

void loop(){
  roll_pitch();
// delay(1000); // <-- This delay signifies me doing things other than reading the serial info it's also screwing things up.
}

void roll_pitch(){ //
  while(bluetooth.available()){
    character = bluetooth.read();
    content.concat(character);
   if(character == '\r'){ // if end of content received
     Serial.print(content); //display content and
     content = ""; //clear buffer
     Serial.println();
  }
  }
}
