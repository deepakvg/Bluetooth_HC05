
#include <SoftwareSerial.h>
int bluetoothTx = 10; 
int bluetoothRx = 11;
String content; //content buffer to concatenate characters

char character; //To store single character


SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup(){
  bluetooth.begin(38400);
  Serial.begin(9600);
}

void loop(){
  bluetooth();

}

void bluetooth(){ //
  while(bluetooth.available()){
    character = bluetooth.read();
    content.concat(character);
   if(character == '\r'){ // find if there is carriage return
     Serial.print(content); //display content (Use baud rate 9600)
     content = ""; //clear buffer
     Serial.println();
  }
  }
}
