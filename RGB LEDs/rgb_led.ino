//Define pins for each led
int redpin = 11;
int bluepin = 10;
int greenpin = 9;
void setup () {
  //Set pin modes
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
}
void loop ()
{
  //Iterate over each led and write continuous voltage values
  for(int i=0; i<255; i++)
  {
    analogWrite(redpin, i);
    analogWrite(greenpin, i-100);
    analogWrite(bluepin, i-50);
  }
}
