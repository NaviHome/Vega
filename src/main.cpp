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
#include "util/DataManager.h"
#include "util/TimeHelper.h"
#include "config.h"

void setup()
{
    DataManager::init();
    TimeHelper::init();
}

void loop()
{
    DataManager::update();
    TimeHelper::update();
    delay(MAIN_LOOP_DELAY);
}