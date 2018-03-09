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

// Examples
#ifdef CFG_HOLDER
#undef CFG_HOLDER
#endif






#ifdef STA_SSID1
#undef STA_SSID1
#endif
#define STA_SSID1              "T100"

#ifdef STA_PASS1
#undef STA_PASS1
#endif
#define STA_PASS1             "xxxx"

#ifdef WIFI_GATEWAY
#undef WIFI_GATEWAY
#endif
#define WIFI_GATEWAY           "192.168.0.1"     // {IpAddress2] If not using DHCP set Gateway IP address

#ifdef WIFI_SUBNETMASK
#undef WIFI_SUBNETMASK
#endif
#define WIFI_SUBNETMASK        "255.255.255.0"   // [IpAddress3] If not using DHCP set Network mask

#ifdef WIFI_DNS
#undef WIFI_DNS
#endif
#define WIFI_DNS               "8.8.8.8"



#ifdef WIFI_IP_ADDRESS
#undef WIFI_IP_ADDRESS
#endif


#ifdef MQTT_FULLTOPIC
#undef MQTT_FULLTOPIC
#endif


#ifdef MQTT_CLIENT_ID
#undef MQTT_CLIENT_ID
#endif


#ifdef FRIENDLY_NAME
#undef FRIENDLY_NAME
#endif


#ifdef APP_TIMEZONE
#undef APP_TIMEZONE
#endif
#define APP_TIMEZONE           1



#ifdef MQTT_HOST
#undef MQTT_HOST
#endif
#define MQTT_HOST            "192.168.0.50"          // [MqttHost]

#ifdef MQTT_PORT
#undef MQTT_PORT
#endif
#define MQTT_PORT            1883              // [MqttPort] MQTT port (10123 on CloudMQTT)

#ifdef MQTT_USER
#undef MQTT_USER
#endif
#define MQTT_USER            "mariuszb"       // [MqttUser] Optional user

#ifdef MQTT_PASS
#undef MQTT_PASS
#endif
#define MQTT_PASS            "xxxx"       // [MqttPassword] Optional



#ifdef NTP_SERVER1
#undef NTP_SERVER1
#endif
#define NTP_SERVER1            "ntp2.tp.pl"

#ifdef USE_ADC_VCC
#undef USE_ADC_VCC
#endif
//#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices



<<<<<<< HEAD
#ifdef USE_DOMOTICZ
#undef USE_DOMOTICZ
#endif
//#define USE_DOMOTICZ

#ifdef USE_HOME_ASSISTANT
#undef USE_HOME_ASSISTANT
#endif
//#define USE_HOME_ASSISTANT

#ifdef USE_DISCOVERY
#undef USE_DISCOVERY
#endif
//#define USE_DISCOVERY

#ifdef WS2812_LEDS
#undef WS2812_LEDS
#endif
//#define WS2812_LEDS            30                // [Pixels] Number of WS2812 LEDs to start with

#ifdef USE_IR_REMOTE
#undef USE_IR_REMOTE
#endif
//#define USE_IR_REMOTE



#ifdef  APP_PULSETIME
#undef APP_PULSETIME
#endif



#ifdef  USE_USERTIMERS
#undef  USE_USERTIMERS
#endif


#ifdef  SYS_LOG_HOST
#undef  SYS_LOG_HOST
#endif
#define SYS_LOG_HOST           "192.168.0.50"

#ifdef  SERIAL_LOG_LEVEL
#undef  SERIAL_LOG_LEVEL
#endif
#define SERIAL_LOG_LEVEL  LOG_LEVEL_INFO  //LOG_LEVEL_NONE

#ifdef  SYS_LOG_LEVEL
#undef  SYS_LOG_LEVEL
#endif
#define SYS_LOG_LEVEL  LOG_LEVEL_INFO



#ifdef  MQTT_SENSOR_RETAIN
#undef  MQTT_SENSOR_RETAIN
#endif
#define MQTT_SENSOR_RETAIN     1

#ifdef  MQTT_POWER_RETAIN
#undef  MQTT_POWER_RETAIN
#endif
#define MQTT_POWER_RETAIN      0




#define USE_USERTIMERSWEB            // view user timers on WEB
#define MAX_USERTIMERS       16      // fixed configuration memory max size , do not change it
#define USED_USERTIMERS      8       // realy used timers 1 to 16

//#define ONOFF_TEMPERATURE_LOWHIGH    // timer on/off is temperature dependent 
       
#ifdef MODULE
#undef MODULE
#endif

#ifdef WIFI_HOSTNAME
#undef WIFI_HOSTNAME
#endif

//-------------------------------------------------------------
#define CFG_HOLDER             0x20180308
//#define ROOM35   // Sypialnia
//#define ROOM34   // Dzieci
//#define ROOM33   // parter
#define ROOMX
//-------------------------------------------------------------


#ifdef ROOM35               //sypialnia
#define WIFI_IP_ADDRESS        "192.168.0.35"    // [IpAddress1] Set to 0.0.0.0 for using DHCP or IP address
#define MQTT_FULLTOPIC         "main/%topic%/35/%prefix%/" // Up to max 80 characers
#define MQTT_CLIENT_ID         "OgrzewanieSypialnia"
#define FRIENDLY_NAME          "OgrzewanieSypialnia"
#define WIFI_HOSTNAME          "Sypialnia"
#define APP_PULSETIME          (60*55)+100   // 55 min
#define USE_THINGSPEAK     1
#define THINGSPEAKTYPE     6
#define USE_USERTIMERS              //Local timers funcionality active
#define MODULE                 SONOFF_POW // [Module] Select default model
#endif

#ifdef ROOM34               //dzieci
#define WIFI_IP_ADDRESS        "192.168.0.34"    // [IpAddress1] Set to 0.0.0.0 for using DHCP or IP address
#define MQTT_FULLTOPIC         "main/%topic%/34/%prefix%/" // Up to max 80 characers
#define MQTT_CLIENT_ID         "OgrzewanieDzieci"
#define FRIENDLY_NAME          "OgrzewanieDzieci"
#define WIFI_HOSTNAME          "Dzieci"
#define APP_PULSETIME          (60*55)+100   // 55 min
#define USE_THINGSPEAK     1
//#define THINGSPEAKTYPE     4
#define USE_USERTIMERS              //Local timers funcionality active
#define MODULE                 SONOFF_BASIC // [Module] Select default model
#endif

#ifdef ROOM33               //parter
#define WIFI_IP_ADDRESS        "192.168.0.33"    // [IpAddress1] Set to 0.0.0.0 for using DHCP or IP address
#define MQTT_FULLTOPIC         "main/%topic%/33/%prefix%/" // Up to max 80 characers
#define MQTT_CLIENT_ID         "OgrzewanieParter" //"OgrzewanieSypainia" //"Lampka1" // "OgrzewanieDzieci"
#define FRIENDLY_NAME          "OgrzewanieParter" //"OgrzewanieSypialnia" //"Lampka1"  //"OgrzewanieDzieci"
#define WIFI_HOSTNAME          "Parter"
#define APP_PULSETIME          (60*55)+100   // 55 min
#define USE_USERTIMERS              //Local timers funcionality active
#define MODULE                 SONOFF_BASIC // [Module] Select default model
#endif

#ifdef ROOMX                   //Test
#define WIFI_IP_ADDRESS        "192.168.0.39"    // [IpAddress1] Set to 0.0.0.0 for using DHCP or IP address
#define MQTT_FULLTOPIC         "main/%topic%/39/%prefix%/" // Up to max 80 characers
#define MQTT_CLIENT_ID         "Test" 
#define FRIENDLY_NAME          "Test" 
#define WIFI_HOSTNAME          "Test" 
#define APP_PULSETIME          (60*55)+100   // 55 min max switch on time
#define USE_USERTIMERS              //Local timers funcionality active
#define MODULE                  WEMOS   //SONOFF_BASIC // [Module] Select default model
#endif



=======
>>>>>>> a039b51e0d9a73e52c114a77e0e3c0846a56e10e
#ifdef ESP32
#undef USE_ADC_VCC    // Needs to be ported
#undef USE_IR_REMOTE  // IRremoteESP8266 needs to be ported
#undef SNFBRIDGE      // No commercial device, no sense porting
#else
#define SNFBRIDGE
#define USE_ENERGY_SENSOR
#endif
<<<<<<< HEAD

=======
>>>>>>> a039b51e0d9a73e52c114a77e0e3c0846a56e10e

#endif  // _USER_CONFIG_OVERRIDE_H_
