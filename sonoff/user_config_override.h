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

/*****************************************************************************************************\
 * ATTENTION: - Changes to most PARAMETER defines will only override flash settings if you change
 *              define CFG_HOLDER.
 *            - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *            - You still need to update user_config.h for major defines MODULE and USE_MQTT_TLS.
 *            - Changing MODULE defines are not being tested for validity as they are in user_config.h.
 *            - Most parameters can be changed online using commands via MQTT, WebConsole or serial.
 *            - So I see no use in this but anyway, your on your own.
\*****************************************************************************************************/

#define APP_POWERON_STATE      0                 // [PowerOnState] Power On Relay state (0 = Off, 1 = On, 2 = Toggle Saved state, 3 = Saved state)

#undef CFG_HOLDER
#define CFG_HOLDER             0x20161205        // [Reset 1] Change this value to load following default configuration parameters

#define SAVE_DATA              0                 // [SaveData] Save changed parameters to Flash (0 = disable, 1 - 3600 seconds)

#define SAVE_STATE             0                 // [SetOption0] Save changed power state to Flash (0 = disable, 1 = enable)

#define STA_SSID1              "hipolitek2"      // [Ssid1] Wifi SSID
#define STA_PASS1              "12hipolitek34"  // [Password1] Wifi password
#define STA_SSID2              "hipolitek"      // [Ssid2] Optional alternate AP Wifi SSID
#define STA_PASS2              "12hipolitek34"  // [Password2] Optional alternate AP Wifi password

#define WIFI_CONFIG_TOOL       WIFI_RETRY    // [WifiConfig] Default tool if wifi fails to connect

#define MQTT_HOST            "hipolitek.ddns.info"          // [MqttHost]
#define MQTT_PORT            1883              // [MqttPort] MQTT port (10123 on CloudMQTT)
#define MQTT_USER            "jacek"       // [MqttUser] Optional user
#define MQTT_PASS            "jacekj"       // [MqttPassword] Optional password

#define SERIAL_LOG_LEVEL       LOG_LEVEL_ALL    // [SerialLog]

// NOT USED:
/*
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT
#undef USE_EMULATION
#undef USE_DS18x20                              // Optional for more than one DS18x20 sensors with id sort, single scan and read retry (+1k3 code)
#undef USE_DS18x20_LEGACY                       // Optional for more than one DS18x20 sensors with dynamic scan using library OneWire (+1k5 code)
#undef USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
#undef USE_SPI                                  // SPI using library TasmotaTFT
*/

// NOT PORTED:
#undef USE_DISCOVERY
#undef USE_MHZ19
#undef USE_ENERGY_SENSOR
#undef USE_SENSEAIR
#undef USE_ADC_VCC
#undef USE_ARILUX_RF
#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k code, 0k3 mem, 48 iram)
#undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //

#endif  // _USER_CONFIG_OVERRIDE_H_
