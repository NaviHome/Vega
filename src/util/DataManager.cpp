/*
 * Copyright (C) 2018 iTX Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include "DataManager.h"
#include "../config.h"

#define CMD_WIFI_MODULE_INFO 0
#define CMD_REINIT_DISPLAY 1
#define CMD_UPDATE_TIME 2
#define CMD_GET_INFO 3
#define CMD_SET_WIFI_INFO 4

#define RESP_TICK_INFO 0
#define RESP_INFO 1

const char *DataManager::wifiSsid;
const char *DataManager::wifiPass;

void DataManager::init()
{
    Serial.begin(SERIAL_BAUDRATE);
    Serial.setTimeout(SERIAL_READ_TIMEOUT);
    sendInfo();
}

void DataManager::sendInfo()
{
    char str[30];
    sprintf(str, "{\"c\":0,\"n\":%s,\"v\":%s}", NAME, VER);
    Serial.println(str);
}

void DataManager::requestInfo()
{
    Serial.println(F("{\"c\":3}"));
}

bool DataManager::update()
{
    if(!WiFi.isConnected())
    {
        requestInfo();
    }

    DynamicJsonBuffer jsonBuffer(256);
    char json[64];
    Serial.readBytes(json, sizeof(json));
    JsonObject &resp = jsonBuffer.parseObject(json);
    if (!resp.success())
    {
        return false;
    }
    //process response first
    if (resp.containsKey("r"))
    {
        int type = resp["r"];
        switch (type)
        {
        case RESP_TICK_INFO:
            break;
        case RESP_INFO:
            wifiSsid = resp["d"];
            wifiPass = resp["p"];
            connectWifi();
            break;
        }
        return true;
    }
    return false;
}

void DataManager::connectWifi()
{
    WiFi.begin(wifiSsid, wifiPass);
}