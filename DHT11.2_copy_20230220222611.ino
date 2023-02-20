#include <TroykaDHT.h>
#include <SoftwareSerial.h>
DHT dht(4, DHT11);
SoftwareSerial HC12(2,3);
constexpr auto pinSensor = A0;
constexpr auto radiomodule = A1;

int Rate = 9600;
int min_temp=16;
int max_temp=32;
int min_hum=30;
int min_soil=300;
int idnt=0;
int s=0;
void setup()
{
Serial.begin(Rate);
dht.begin();
HC12.begin(Rate);
}
void loop()
{
int hum=0;
int temp=0;
int soil=0;

dht.read();
switch(dht.getState()) {
case DHT_OK:
Serial.println("------------— \t");
Serial.print("Soil moisture  = ");
Serial.print(analogRead(pinSensor)/(7));
Serial.println(" % \t");
Serial.print("Temperature = ");
Serial.print(dht.getTemperatureC());
Serial.println(" C \t");
Serial.print("Air humidity = ");
Serial.print(dht.getHumidity());
Serial.println(" %");
break;

case DHT_ERROR_CHECKSUM:
Serial.println("Checksum error");
break;

case DHT_ERROR_TIMEOUT:
Serial.println("Time out error");
break;

case DHT_ERROR_NO_REPLY:
Serial.println("Sensor not connected");
break;
}
if (dht.getTemperatureC()<min_temp){
  s=s+4; 
}
if (dht.getTemperatureC()<max_temp){
  s=s+8;
}
if (dht.getHumidity()<min_hum){
  s=s+32;
} 
if (analogRead(pinSensor)<min_soil){
  s=s+16;
}

HC12.write(s);


delay(2000);
}
