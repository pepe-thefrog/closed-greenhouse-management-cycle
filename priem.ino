#include <SoftwareSerial.h>

SoftwareSerial HC12(8, 9);

void setup() {
  Serial.begin(9600); 
  HC12.begin(9600); 
}

void loop() {
  if (HC12.available()) { 
     int  c = HC12.read(); 
    Serial.print(c); 
  }
}
