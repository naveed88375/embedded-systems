//Transmitter Code

// Required Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Creating Radio Object
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {  
  //Setup the module for communication
  radio.begin();
  radio.openWritingPipe(address);   // Putting transceiver in transmitting mode
  radio.setPALevel(RF24_PA_MAX);    // Power level of the module
  radio.stopListening();            // Stopping module from receiving data
}
void loop() {
  //Write a simple helloworld message and transmit it.
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
