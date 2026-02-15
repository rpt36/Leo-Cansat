/*License: CC 4.0 - Attribution, NonCommercial (by Mitch Davis, github.com/thekakester)
* https://creativecommons.org/licenses/by-nc/4.0/   (See README for details)*/
#include <LoraSx1262.h>

LoraSx1262 radio;
byte receiveBuff[255];
int flag = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial){
  }
  Serial.println("Booted");
  radio.configSetFrequency(869525000);
  radio.configSetBandwidth(0x05);
  radio.configSetCodingRate(0x01);
  radio.configSetSpreadingFactor(8);

  flag = 1;
  if (!radio.begin()) { //Initialize the radio
    Serial.println("Failed to initialize radio");
    flag = -2;
  }
}

void loop() {
  // Receive a packet over radio
  int bytesRead = radio.lora_receive_async(receiveBuff, sizeof(receiveBuff));
  Serial.println(sizeof(receiveBuff));
  Serial.println(bytesRead);
  if (bytesRead > -1) {
    //Print the payload out over serial
    Serial.print("Received: ");
    Serial.write(receiveBuff,bytesRead);
    Serial.println(); //Add a newline after printing
  }
  else{
  }
} // Testing Git Push