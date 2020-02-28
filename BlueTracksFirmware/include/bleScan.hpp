#ifndef _BLE_SCAN_HPP_
#define _BLE_SCAN_HPP_

#include <BLEDevice.h>

extern String scanResults;

class AdvertisedDeviceCallback : public BLEAdvertisedDeviceCallbacks
{
public:
    void onResult(BLEAdvertisedDevice advertisedDevice);
};

String bleScan(int time);

#endif