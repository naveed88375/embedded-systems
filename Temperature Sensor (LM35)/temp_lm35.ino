//Define sensor pin
#define sensor A0
//Variables to store temperature reading
int reading;
float temp;


void setup() {
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);

}

void loop() {
//Read sensor output
reading=analogRead(sensor);
//Convert to temperature
temp=reading*(5.0/1024.0)*100;
//Put some delay
delay(10);
//Prints values to serial monitor
  Serial.print("temperature= "); 
  Serial.println(temp);
//Delay of 0.5 seconds
delay(500);

}
