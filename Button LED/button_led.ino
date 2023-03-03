//Define button and led pins
int button = 2;
int led = 3;
//Variable to store button status
int buttonstate;

void setup(){
  //Set pin modes
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}
void loop(){
  //Check button status
  buttonstate=digitalRead(button);
  //If button is pressed turn on led otherwise turn it off
  if(buttonstate==HIGH)
  digitalWrite(led,HIGH);
  else 
  digitalWrite(led,LOW);
}

