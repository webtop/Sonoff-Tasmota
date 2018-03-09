# ESP32

ESP32 port of [Tasmota](https://github.com/arendst/Sonoff-Tasmota)
Prepared for Wemos ESP32.

## Working (Tested)

- Wifi
- Flash (by NVS)
- Relays
- Switches (as inputs)
- Webserver (USE_WEBSERVER)
- MQTT (MQTT_USE)
- Logging (Serial, Web)
- NTP (with simple one zone)
- HTTP Update

## Should work (compiles, not tested)

- DOMOTICZ (USE_DOMOTICZ)
- Home Assistant (USE_HOME_ASSISTANT)
- Emulation (USE_EMULATION)
- I2C (USE_I2C)
- SPI (USE_SPI)
- MDNS Discovery (USE_DISCOVERY)
- WS2812 (USE_WS2812)
- Counter
- DHT (USE_DHT)
- DS DS18x20 (USE_DS18x20 or USE_DS18x20_LEGACY)
- SHT (USE_SHT, USE_SHT)
- HTU (USE_HTU)
- BMx (USE_BMP, USE_BME680, USE_BH1750)
- VEML6070 (USE_VEML6070)
- TSL2561 (USE_TSL2561)
- ADS1115 (USE_ADS1115)
- INA219 (USE_INA219)
- DISPLAY (USE_DISPLAY)
- MHZ19 (USE_MHZ19)
- ENERGY SENSOR (USE_ENERGY_SENSOR)
- SENSEAIR (USE_SENSEAIR)
- ARILUX RF (USE_ARILUX_RF)

## Not ported

- USE_ADC_VCC
- USE_IR_REMOTE
- SNFBRIDGE
- ADC
- LED

## Installation

### ESP32 for Arduino IDE

Please follow [Installation Instructions](https://github.com/espressif/arduino-esp32#installation-instructions)

### Libraries

If working with Arduino IDE: copy all project libraries from \lib to Arduino\libraries

External additional libraries (in lib directory):
- [ESP32Ticker](https://github.com/bertmelis/ESP32Ticker)
- [WebServer-esp32](https://github.com/zhouhan0126/WebServer-esp32)

### Board

If working with Arduino IDE: set Tool->Board->ESP32 Dev Module

### Headers definitions

To compile in user_config_override.h should be:

```
#undef USE_ADC_VCC    // Needs to be ported
#undef USE_IR_REMOTE  // IRremoteESP8266 needs to be ported
#undef SNFBRIDGE      // No commercial device, no sense porting
```

### WString support

Additionally add:
- Support of unsigned long long in [WString](https://github.com/espressif/arduino-esp32/issues/1066)


### Partially not working

In code there are marked parts with #warning


### License

This program is licensed under GPL-3.0
