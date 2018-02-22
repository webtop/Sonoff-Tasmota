# ESP32

ESP32 port of Tasmota.
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

To compile add in user_config_override.h:

```
#undef USE_ADC_VCC    // Needs to be ported
#undef USE_IR_REMOTE  // IRremoteESP8266 needs to be ported
#undef SNFBRIDGE      // No commercial device, no sense porting
```

Additionally add:
- Support of unsigned long long in [WString](https://github.com/espressif/arduino-esp32/issues/1066)

External additional libraries (in lib directory):
- [ESP32Ticker](https://github.com/bertmelis/ESP32Ticker)
- [WebServer-esp32](https://github.com/zhouhan0126/WebServer-esp32)

### Partially not working

In code there are marked parts with #warning

# ESP8266

## Sonoff-Tasmota
Provide ESP8266 based Sonoff by [iTead Studio](https://www.itead.cc/) and ElectroDragon IoT Relay with Serial, Web and MQTT control allowing 'Over the Air' or OTA firmware updates using Arduino IDE.

Current version is **5.12.0b** - See [sonoff/_releasenotes.ino](https://github.com/arendst/Sonoff-Tasmota/blob/development/sonoff/_releasenotes.ino) for change information.

### ATTENTION All versions

Only Flash Mode DOUT is supported. Do not use Flash Mode DIO / QIO / QOUT as it might seem to brick your device.

See [Wiki](https://github.com/arendst/Sonoff-Tasmota/wiki/Theo's-Tasmota-Tips) for background information.

### ATTENTION Version 5 and up

These versions use a new linker script to free flash memory for future code additions. It moves the settings from Spiffs to Eeprom. If you compile your own firmware download the new linker to your IDE or Platformio base folder. See [Wiki > Prerequisite](https://github.com/arendst/Sonoff-Tasmota/wiki/Prerequisite).

Best practice to implement is:
- Open the webpage to your device
- Perform option ``Backup Configuration``
- Upgrade new firmware using ``Firmware upgrade``
- If configuration conversion fails keep the webpage open and perform ``Restore Configuration``

You should now have a device with 32k more code memory to play with.

### Version Information

- Sonoff-Tasmota provides all (Sonoff) modules in one file and starts with module Sonoff Basic.
- Once uploaded select module using the configuration webpage or the commands ```Modules``` and ```Module```.
- After reboot select config menu again or use commands ```GPIOs``` and ```GPIO``` to change GPIO with desired sensor.

<img src="https://github.com/arendst/arendst.github.io/blob/master/media/sonoffbasic.jpg" width="250" align="right" />

See [Wiki](https://github.com/arendst/Sonoff-Tasmota/wiki) for more information.<br />
See [Community](https://groups.google.com/d/forum/sonoffusers) for forum and more user experience.

The following devices are supported:
- [iTead Sonoff Basic](https://www.itead.cc/smart-home/sonoff-wifi-wireless-switch-1.html)
- [iTead Sonoff RF](https://www.itead.cc/smart-home/sonoff-rf.html)
- [iTead Sonoff SV](https://www.itead.cc/smart-home/sonoff-sv.html)<img src="https://github.com/arendst/arendst.github.io/blob/master/media/sonoff_th.jpg" width="250" align="right" />
- [iTead Sonoff TH10/TH16 with temperature sensor](https://www.itead.cc/smart-home/sonoff-th.html)
- [iTead Sonoff Dual (R2)](https://www.itead.cc/smart-home/sonoff-dual.html)
- [iTead Sonoff Pow](https://www.itead.cc/smart-home/sonoff-pow.html)
- [iTead Sonoff 4CH](https://www.itead.cc/smart-home/sonoff-4ch.html)
- [iTead Sonoff 4CH Pro](https://www.itead.cc/smart-home/sonoff-4ch-pro.html)
- [iTead S20 Smart Socket](https://www.itead.cc/smart-socket.html)
- [Sonoff S22 Smart Socket](https://github.com/arendst/Sonoff-Tasmota/issues/627)
- [iTead Sonoff S31 Smart Socket with Energy Monitoring](https://www.itead.cc/sonoff-s31.html)
- [iTead Slampher](https://www.itead.cc/slampher.html)
- [iTead Sonoff Touch](https://www.itead.cc/sonoff-touch.html)
- [iTead Sonoff T1](https://www.itead.cc/sonoff-t1.html)
- [iTead Sonoff SC](https://www.itead.cc/sonoff-sc.html)
- [iTead Sonoff Led](https://www.itead.cc/sonoff-led.html)<img src="https://github.com/arendst/arendst.github.io/blob/master/media/sonoff4ch.jpg" height="250" align="right" />
- [iTead Sonoff BN-SZ01 Ceiling Led](https://www.itead.cc/bn-sz01.html)
- [iTead Sonoff B1](https://www.itead.cc/sonoff-b1.html)
- [iTead Sonoff RF Bridge 433](https://www.itead.cc/sonoff-rf-bridge-433.html)
- [iTead Sonoff Dev](https://www.itead.cc/sonoff-dev.html)
- [iTead 1 Channel Switch 5V / 12V](https://www.itead.cc/smart-home/inching-self-locking-wifi-wireless-switch.html)
- [iTead Motor Clockwise/Anticlockwise](https://www.itead.cc/smart-home/motor-reversing-wifi-wireless-switch.html)
- [Electrodragon IoT Relay Board](http://www.electrodragon.com/product/wifi-iot-relay-board-based-esp8266/)
- AI Light or any my9291 compatible RGBW LED bulb
- H801 PWM LED controller
- [MagicHome PWM LED controller](https://github.com/arendst/Sonoff-Tasmota/wiki/MagicHome-LED-strip-controller)
- AriLux AL-LC01, AL-LC06 and AL-LC11 PWM LED controller
- [Supla device - Espablo-inCan mod. for electrical Installation box](https://forum.supla.org/viewtopic.php?f=33&t=2188)
- [Luani HVIO board](https://luani.de/projekte/esp8266-hvio/)
- Wemos D1 mini, NodeMcu and Ledunia

### License

This program is licensed under GPL-3.0