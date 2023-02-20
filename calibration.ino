           
#include <SoftwareSerial.h>            
                                       
#define RX 8                           
#define TX 9                           
SoftwareSerial Serial1(RX,TX);         
                                       
#define S  3                           
                                       
void setup() {                        
  Serial.begin(9600);                  
  Serial1.begin(9600);                 
  pinMode(S, OUTPUT);                  
  digitalWrite(S, LOW);                
  delay(40);                           
}                                   
                                     
void loop() {                       
  if(Serial1.available()){             
    Serial.write(Serial1.read());     
    }                                
  if(Serial.available()){              
    Serial1.write(Serial.read());     
  }                                   
}                                    
