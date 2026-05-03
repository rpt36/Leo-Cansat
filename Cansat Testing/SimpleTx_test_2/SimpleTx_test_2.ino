/*License: CC 4.0 - Attribution, NonCommercial (by Mitch Davis, github.com/thekakester)
* https://creativecommons.org/licenses/by-nc/4.0/   (See README for details)*/
#include <LoraSx1262.h>

const char* payload = "Hello world.  This a pretty long payload. We can transmit up to 255 bytes at once, which is pretty neat if you ask me";
LoraSx1262 radio;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){ 
  }
  if (!radio.begin()) { //Initialize radio
    Serial.println("Failed to initialize radio.");
  }
  Serial.println("Booted");
  radio.configSetFrequency(869525000);
  radio.configSetBandwidth(0x05);
  radio.configSetCodingRate(0x01);
  radio.configSetSpreadingFactor(8);
}

void loop() {
  Serial.print("Transmitting... ");
  radio.transmit((byte *) payload,strlen(payload));
  Serial.println("Done!");

  delay(1000);
}
