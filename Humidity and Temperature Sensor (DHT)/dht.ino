//Include DHT sensor library
#include <dht.h>
//Define DHT sensor digital pin
#define DHT11_PIN 7
dht DHT;

void setup(){
  //Set connection to serial monitor
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop()
{
  //Read data from sensor
   DHT.read11(DHT11_PIN);
  //print temperature and humidity values to monitor
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  //Put a delay of 1 second
  delay(1000);
}
