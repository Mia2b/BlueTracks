#include <BLEDevice.h>
#include <Arduino.h>

#include "bleScan.hpp"

String scanResults = "";

void AdvertisedDeviceCallback::onResult(BLEAdvertisedDevice advertisedDevice)
{
    scanResults += String(advertisedDevice.getRSSI()) + " " + String(advertisedDevice.getAddress().toString().c_str()) + "\n";
}

String bleScan(int time)
{
    Serial.println("Starting scan");
    BLEDevice::init("");
    scanResults = "";
    BLEDevice::setPower(ESP_PWR_LVL_P9);
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new AdvertisedDeviceCallback());
    pBLEScan->setActiveScan(true);
    BLEScanResults foundDevices = pBLEScan->start(time);
    Serial.println("Scan complete");
    return scanResults;
}