/*
  ST7571 ERC128128FS02-3 — I2C address scan
  Date: 2026-01-31

  Purpose:
  - Find the I2C address of the ST7571 display controller.
  - Typical addresses: 0x3E or 0x3F.

  Hardware:
  - Board: ESP32-C3 Super Mini
  - SDA -> GPIO8
  - SCL -> GPIO9
  - RST is not required for scanning (can be left as is).

  How to use:
  1) Upload this sketch.
  2) Open Serial Monitor at 115200 baud.
  3) The sketch prints any found I2C addresses.
*/

#include <Wire.h>

#define SDA_PIN 8
#define SCL_PIN 9

void setup() {
  Serial.begin(115200);
  delay(300);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println();
  Serial.println("I2C scan start...");

  int found = 0;
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    uint8_t err = Wire.endTransmission();

    if (err == 0) {
      Serial.print("Found device at 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
      found++;
    }
  }

  if (found == 0) Serial.println("No I2C devices found.");
  else {
    Serial.print("Total found: ");
    Serial.println(found);
  }

  Serial.println("I2C scan done.");
}

void loop() {
  // Nothing.
}
