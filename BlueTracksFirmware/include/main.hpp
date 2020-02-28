#ifndef _MAIN_HPP_
#define _MAIN_HPP_

enum States
{
    BLE_SCAN,
    WIFI_POST,
    SPIFFS_LOAD,
    SPIFFS_SAVE,
    REBOOT,
};

int deviceState;

void setup();
void loop();



#endif