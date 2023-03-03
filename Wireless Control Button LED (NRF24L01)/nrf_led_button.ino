//Include required libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Define pin numbers
#define led 5
#define button 4

//Buttons setup
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
boolean buttonStateO = 0;
boolean buttonStateI = 0;

void setup() {
  //Pin mode setup
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  //NRF setup
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MAX);
}
void loop()
{
  delay(5);
  //Check button status and transmit it.
  radio.stopListening();
    buttonStateO = digitalRead(button);
    radio.write(&buttonStateO, sizeof(buttonStateO));
  delay(5);

  //Listen to button status from reciever
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonStateI, sizeof(buttonStateI));

  //If button is pressed turn on led, else turn it off
  if (buttonStateI == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}

