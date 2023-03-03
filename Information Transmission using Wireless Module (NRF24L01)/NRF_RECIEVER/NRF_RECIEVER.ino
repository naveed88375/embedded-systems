//Reciever Code

//Required Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Radio Object
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);   // Initializing serial communication
  radio.begin();
  radio.openReadingPipe(0,address);  // Putting module into listening mode
  radio.setPALevel(RF24_PA_MAX);     // Setting power level of the module
  radio.startListening();            // Begining listening of the module
}
void loop() {
  //Listen for message from the transmitter
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    // Write the message to serial monitor
    Serial.println(text);
  }
}
