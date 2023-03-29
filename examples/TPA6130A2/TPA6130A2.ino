#include <Wire.h>
#include "TPA6130A2.h"

byte volume = 40; // Value between 0-63

TPA6130A2 Headphones;

void setup()
{
  Serial.begin (115200);
  if (!Headphones.Init()) {
    Serial.println("TPA6130A2 not detected!");
    while (true);
  } else {
    Serial.println("TPA6130A2 detected!");
  }

}


void loop()
{
Headphones.SetVolume(volume);
Serial.println("Headphones volume set to " + String(Headphones.GetVolume()) + "dB");
Serial.println();

delay(2000);
Headphones.SetMute(1);
Serial.println("Muting status set to: " + String(Headphones.GetMute()));
Serial.println();

delay(2000);
Headphones.SetMute(0);
Serial.println("Muting status set to: " + String(Headphones.GetMute()));
Serial.println();

delay(2000);
Headphones.SetHiZ(0);
Serial.println("Hi-Z impedance set Off");
Serial.println();

delay(2000);
Headphones.SetHiZ(1);
Serial.println("Hi-Z impedance set On");
Serial.println();

delay(2000);
Headphones.Shutdown();
Serial.println("Headphones amplifier is now in standby");
Serial.println();

delay(2000);
Headphones.Init();
Serial.println("Headphones amplifier is now reinitialised");
Serial.println();

delay(2000);
}
