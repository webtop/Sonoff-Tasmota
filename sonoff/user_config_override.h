/*
  user_config_override.h - user configuration overrides user_config.h for Sonoff-Tasmota

  Copyright (C) 2018  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#define RELEASE_CONFIG

#ifndef RELEASE_CONFIG
/*****************************************************************************************************\
 * ATTENTION: - Changes to most PARAMETER defines will only override flash settings if you change
 *              define CFG_HOLDER.
 *            - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *            - You still need to update user_config.h for major defines MODULE and USE_MQTT_TLS.
 *            - Changing MODULE defines are not being tested for validity as they are in user_config.h.
 *            - Most parameters can be changed online using commands via MQTT, WebConsole or serial.
 *            - So I see no use in this but anyway, your on your own.
\*****************************************************************************************************/

#define APP_POWERON_STATE      0                      // [PowerOnState] Power On Relay state (0 = Off, 1 = On, 2 = Toggle Saved state, 3 = Saved state)

#undef CFG_HOLDER
#define CFG_HOLDER             0x20161200             // [Reset 1] Change this value to load following default configuration parameters

#define SAVE_DATA              0                      // [SaveData] Save changed parameters to Flash (0 = disable, 1 - 3600 seconds)

#define SAVE_STATE             0                      // [SetOption0] Save changed power state to Flash (0 = disable, 1 = enable)

#define STA_SSID1              "hipolitek"           // [Ssid1] Wifi SSID
#define STA_PASS1              "12hipolitek34"        // [Password1] Wifi password
//#define STA_SSID2              "hipolitek2"            // [Ssid2] Optional alternate AP Wifi SSID
//#define STA_PASS2              "12hipolitek34"        // [Password2] Optional alternate AP Wifi password
#define STA_SSID2              ""
#define STA_PASS2              ""

#define WIFI_CONFIG_TOOL       WIFI_WAIT              // [WifiConfig] Default tool if wifi fails to connect

#define MQTT_USE               1
#define MQTT_HOST              "hipolitek.ddns.info"  // [MqttHost]
#define MQTT_PORT              1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)
#define MQTT_USER              "jacek"                // [MqttUser] Optional user
#define MQTT_PASS              "jacekj"               // [MqttPassword] Optional password

#define MQTT_FULLTOPIC         "/%topic%/%prefix%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic
//#define PROJECT                "watervalve2"
#define PROJECT                "esp32test"
#define MQTT_CLIENT_ID         PROJECT

#define SERIAL_LOG_LEVEL       LOG_LEVEL_ALL          // [SerialLog]

// TO TEST COMPILATION:
#define TEST_ALL

#ifdef TEST_ALL
  #define USE_ENERGY_SENSOR
  #define USE_DHT
  #define USE_DS18x20
  //#define USE_DS18x20_LEGACY
  #define USE_SPI

  #define USE_VEML6070                           // Add I2C code for VEML6070 sensor (+0k5 code)
  #define USE_TSL2561                            // Add I2C code for TSL2561 sensor using library Adafruit TSL2561 Arduino (+1k2 code)
  #define USE_ADS1115                            // Add I2C code for ADS1115 16 bit A/D converter based on Adafruit ADS1x15 library (no library needed) (+0k7 code)
  //#define USE_ADS1115_I2CDEV                     // Add I2C code for ADS1115 16 bit A/D converter using library i2cdevlib-Core and i2cdevlib-ADS1115 (+2k code)
  #define USE_INA219                             // Add I2C code for INA219 Low voltage and current sensor (+1k code)
  #define USE_DISPLAY                            // Add I2C Display Support for LCD, Oled and up to eigth Matrices (+19k code)
#else
  // NOT USED:
  #undef USE_DOMOTICZ
  #undef USE_HOME_ASSISTANT
  #undef USE_EMULATION
  #undef USE_DS18x20                              // Optional for more than one DS18x20 sensors with id sort, single scan and read retry (+1k3 code)
  #undef USE_DS18x20_LEGACY                       // Optional for more than one DS18x20 sensors with dynamic scan using library OneWire (+1k5 code)
  #undef USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
  #undef USE_SPI                                  // SPI using library TasmotaTFT
  #undef USE_DISCOVERY
  #undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //   
  #undef USE_SENSEAIR
  #undef USE_MHZ19
  #undef USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
  #undef USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
  #undef USE_ARILUX_RF
  #undef USE_ENERGY_SENSOR
#endif

#define TIME_WITH_MILLIS

#else // RELEASE

#endif

// NOT PORTED:
#undef USE_ADC_VCC    // Needs to be ported
#undef USE_IR_REMOTE  // IRremoteESP8266 needs to be ported
#undef SNFBRIDGE      // No commercial device, no sense porting

#endif  // _USER_CONFIG_OVERRIDE_H_
