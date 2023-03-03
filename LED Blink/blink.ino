// Declate digital pin number
int led = 7;

void setup()
{
  //Set pin mode to output
  pinMode(led, OUTPUT);
}

void loop()
{
  //Write digital high and low on pin with 1 second delay
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

