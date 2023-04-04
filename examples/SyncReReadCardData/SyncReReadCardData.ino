// This example uses synchronous blocking API.
// It assumes that your reader has ID 2 and it will change it back to 1.
// To set the ID, you need reader serial number. This is found on the back of the reader
// or you can read it using this library. See DetectAvailableReaders.ino for example
// how to detect available readers and their IDs.

#include <Arduino.h>
#include <ArduinoLog.h>
#include "RfidReader.h"

#define RO_PIN 5
#define DI_PIN 19
#define RE_PIN 18

void setup() {
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_NOTICE, &Serial);
    delay(1000);

    Log.noticeln("Reading card data from reader 2.");

    Serial2.begin(19200, SERIAL_8E1, RO_PIN, DI_PIN);

    RfidReader reader = RfidReader(Serial2, RE_PIN);
    const char * cardData = reader.reReadCardData(2);

    Log.noticeln("Reader 2 card data: %s.", cardData);
}

void loop() {
}