#include "main.hpp"

#include <Arduino.h>

#include "spiffsManager.hpp"
#include "wifiPost.hpp"
#include "bleScan.hpp"


void setup()
{
    init();
    Serial.begin(115200);
    deviceState = SPIFFS_LOAD;
}

void loop()
{
    switch (deviceState)
    {
    case SPIFFS_LOAD:
        deviceState = BLE_SCAN;
        break;

    case BLE_SCAN:
        Serial.print(String(bleScan(30)));
        deviceState = SPIFFS_SAVE;
        break;

    case WIFI_POST:
        wifiPost();
        deviceState = SPIFFS_SAVE;
        break;

    case SPIFFS_SAVE:
        deviceState = REBOOT;
        break;

    case REBOOT:
        ESP.restart();
        break;
    }
}