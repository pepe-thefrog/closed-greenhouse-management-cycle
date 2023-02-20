#include <TroykaDHT.h>
#include <SoftwareSerial.h>
DHT dht(4, DHT11);
SoftwareSerial HC12(2,3);
constexpr auto pinSensor = A0;
constexpr auto radiomodule = A1;
int Rate = 9600;
void setup()
{
Serial.begin(Rate);
dht.begin();
HC12.begin(Rate);
}
void loop()
{




dht.read();
switch(dht.getState()) {
case DHT_OK:
Serial.println("------------— \t");
Serial.print("Влажность почвы = ");
Serial.print(analogRead(pinSensor)/(7));
Serial.println(" % \t");
Serial.print("Температура = ");
Serial.print(dht.getTemperatureC());
Serial.println(" C \t");
Serial.print("Влажность воздуха = ");
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

int tempa =(dht.getTemperatureC()) ;
HC12.write(tempa);


delay(2000);
}
