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

#pragma once

#include <Arduino.h>

const String NAME = "Vega";
const String VER = "0.1.0";
const String COPYRIGHT = "(C) 2018 iTX Technologies";

//Serial config
#define SERIAL_BAUDRATE 115200
#define SERIAL_READ_TIMEOUT 200

#define MAIN_LOOP_DELAY 200