#include <SoftwareSerial.h>

SoftwareSerial HC12(8, 9);
int c=0;

void setup() {
  Serial.begin(9600); 
  HC12.begin(9600); 
}

void loop() {
  int voda = 0;
  int hum = 0;
  int soil = 0;
  int temp = 0;
  int id = 0;
  if (HC12.available()) { 
     int c = HC12.read(); 
    Serial.print(c); 
  };
  while (c > 0) {
    if (c = 100) {
      voda = 1;
      c = c - 100;
    } else if (c >= 32) {
      hum = 1;
      c = c - 32;
    } else if (c >= 16) {
      soil = 1;
      c = c - 16;
    } else if (c >= 8) {
      temp = 1;
      c = c - 8;
    } else if (c >= 4) {
      temp = -1;
      c = c - 4;
    } else if (c >= 2) {
      id = 2;
      c = c -2;
    } else {
      id = 1;
      c = 0;
    }
  }
}