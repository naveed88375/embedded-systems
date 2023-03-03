
int feedback = A1;      //The feedback input is A1
int PWM = 3;            //Digital pin D3 for PWM signal
int pwm = 0;            //Initial value of PWM width

void setup() {
  //pinMode(potentiometer, INPUT);
  pinMode(feedback, INPUT);
  pinMode(PWM, OUTPUT);  
  TCCR2B = TCCR2B & B11111000 | B00000001;    // pin 3 PWM frequency of 31372.55 Hz

}

void loop() {  
  
  float output  = analogRead(feedback);         //We read the feedback, which is the real value
  

  //If the desired value is HIGHER than the real value, we increase PWM width

  if(output < 268)
   {
    pwm = pwm+5;
    pwm = constrain(pwm, 0, 255);
   }
   
  //If the desired value is LOWER than the real value, we decreaase PWM width
  if(output > 284)
   {
    pwm = pwm-1;
    pwm = constrain(pwm, 0, 255);
   }

   analogWrite(PWM,pwm);  //Finally, we create the PWM signal*/
  
   
  
}
