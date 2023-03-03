//Include Sensor MQ135 Library file
#include <MQ135.h>

//Setup connection to serial monitor
void setup() {
  Serial.begin(9600);
}

void loop() {
  //Read data from the sensor
  MQ135 gasSensor = MQ135(A0);
  //Convert data to Parts Per Million (PPM)
  float air= gasSensor.getPPM();
  //Print value to the serial monitor
  Serial.println(air);
  //Put a delay of 1 second
  delay(1000);

}
