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
#include <ESP8266WiFi.h>
#include <time.h>
#include "TimeHelper.h"
#include "../config.h"

unsigned long TimeHelper::lastNtpUpdate = 0;
unsigned long TimeHelper::timestampNow = 0;

void TimeHelper::init()
{
    configTime(0, 0, NTP_SERVER_1, NTP_SERVER_2, NTP_SERVER_3);
}

void TimeHelper::update()
{
    if (millis() - lastNtpUpdate > NTP_INTERVAL)
    {
        time_t now = time(NULL);
        if(now > 0)
        {
            lastNtpUpdate = millis();
            timestampNow = now;
        }
        sendTime();
    }
}

void TimeHelper::sendTime()
{
    char str[40];
    sprintf(str, "{\"c\":2,\"t\":\"%ld\"", timestampNow);
    Serial.println(str);
}