/*
Copyright (c) 2017 Theo Arends.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef USE_DSSERIAL
/*********************************************************************************************\
 * DSSERIAL - A curruption of DS18b20 to write and read reply for serial over onewire.
\*********************************************************************************************/

#define W1_SKIP_ROM 0xCC
#define W1_READ_SCRATCHPAD 0xBE
#define W1_WRITE_SCRATCHPAD 0x4E

#define DSSERIAL_MAX_SENSORS 8

#include <OneWire.h>

extern OneWire *ds;

uint8_t dsserial_addr[DSSERIAL_MAX_SENSORS][8];
uint8_t dsserial_idx[DSSERIAL_MAX_SENSORS];
uint8_t dsserial_snsrs = 0;

char serialdata[20];

void dsserial_init()
{
}

void dsserial_search()
{
  uint8_t num_sensors=0;
  uint8_t sensor = 0;
  uint8_t i;

  ds->reset_search();
  for (num_sensors = 0; num_sensors < DS18X20_MAX_SENSORS; num_sensors)
  {
    if (!ds->search(dsserial_addr[num_sensors])) {
      ds->reset_search();
      break;
    }
    // If CRC Ok and Type DS18S20 or DS18B20
    if ((OneWire::crc8(dsserial_addr[num_sensors], 7) == dsserial_addr[num_sensors][7]) &&
       (dsserial_addr[num_sensors][0]==0xF0))
       num_sensors++;
  }
  for (int i = 0; i < num_sensors; i++) dsserial_idx[i] = i;
  for (int i = 0; i < num_sensors; i++) {
    for (int j = i + 1; j < num_sensors; j++) {
      if (uint32_t(dsserial_addr[dsserial_idx[i]]) > uint32_t(dsserial_addr[dsserial_idx[j]])) {
        std::swap(dsserial_idx[i], dsserial_idx[j]);
      }
    }
  }
  dsserial_snsrs = num_sensors;
}

uint8_t dsserial_sensors()
{
  return dsserial_snsrs;
}

String dsserial_address(uint8_t sensor)
{
  char addrStr[20];
  uint8_t i;

  for (i = 0; i < 8; i++) sprintf(addrStr+2*i, "%02X", dsserial_addr[dsserial_idx[sensor]][i]);
  return String(addrStr);
}



boolean dsserial_read(uint8_t sensor, char **dest)
{
  uint8_t present = 0;

  ds->reset();
  ds->select(dsserial_addr[dsserial_idx[sensor]]);
  ds->write(W1_READ_SCRATCHPAD); // Read Scratchpad

  for (int i = 0; i < 20; i++) serialdata[i] = ds->read();
  serialdata[19] = 0;

  *dest = serialdata;

  return true;
}


// write data to scratchpad, null term with crc appended
// variable length
boolean dsserial_write(uint8_t sensor, uint8_t *src)
{
  uint8_t present = 0;

  uint8_t l = strlen((char *)src)+1;
  uint8_t crc = OneWire::crc8(src, l);

  ds->reset();
  ds->select(dsserial_addr[dsserial_idx[sensor]]);
  ds->write(W1_WRITE_SCRATCHPAD); // Write Scratchpad
  for (int i = 0; i < l; i++){
    ds->write((uint8_t)src[i]);
  }
  ds->write(crc);

  return true;
}


/*********************************************************************************************\
 * Presentation
\*********************************************************************************************/

void dsserial_mqttPresent(char* svalue, uint16_t ssvalue, uint8_t* djson)
{
  char stemp1[10], stemp2[10];
  float t;

  byte dsxflg = 0;
  for (byte i = 0; i < dsserial_sensors(); i++) {
    char *t = "";
    if (dsserial_read(i, &t)) {           // Check if read failed
      snprintf_P(svalue, ssvalue, PSTR("%s, \"DSSERIAL\":{"), svalue);
        *djson = 1;
        stemp1[0] = '\0';
      }
      dsxflg++;
      snprintf_P(svalue, ssvalue, PSTR("%s%s\"DSS%d\":{\"Type\":\"%s\", \"Address\":\"%s\", \"String\":\"%s\"}"),
        svalue, stemp1, i +1, "DSSERIAL", dsserial_address(i).c_str(), t);
      strcpy(stemp1, ", ");

  }
  if (dsxflg) snprintf_P(svalue, ssvalue, PSTR("%s}"), svalue);
}

#ifdef USE_WEBSERVER
String dsserial_webPresent()
{
  float t;
  String page = "";

  int s = dsserial_sensors();

  page += F("<tr><td>Num");
  page += String(s);
  page += F("<td><tr>");

  for (byte i = 0; i < dsserial_sensors(); i++) {
    char *t;
    if (dsserial_read(i, &t)) {   // Check if read failed
      page += F("<tr><td>DS"); page += String(i +1); page += F(" Data: </td><td>"); page += t; page += F("</td></tr>");
    }
  }
  return page;
}
#endif  // USE_WEBSERVER


boolean dsserial_command(char *type, uint16_t index, char *dataBuf, uint16_t data_len, int16_t payload, char *svalue, uint16_t ssvalue)
{
  boolean serviced = false;

  if (!strcmp(type,"DSSWRITE")) {
    if (index < dsserial_sensors())
    {
      dataBuf[data_len] = 0;
      dsserial_write(index, (uint8_t *)dataBuf);

      char *t = "bad";
      if (dsserial_read(index, &t)){
        snprintf(svalue, ssvalue, "{\"DSSERIAL\":{\"DSS%d\":\"%s\"}}", index+1, t);
      }

      serviced = true;
    }
  }

#ifdef OLDCODE
  if (!strcmp(type,"PIXELS")) {
    if ((data_len > 0) && (payload > 0) && (payload <= WS2812_MAX_LEDS)) {
      sysCfg.ws_pixels = payload;
      ws2812_pixels();
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Pixels\":%d}"), sysCfg.ws_pixels);
  }
  else if (!strcmp(type,"LED") && (index > 0) && (index <= sysCfg.ws_pixels)) {
    if (data_len == 6) {
//       ws2812_setColor(index, dataBufUc);
      ws2812_setColor(index, dataBuf);
    }
    ws2812_getColor(index, svalue, ssvalue);
  }
  else if (!strcmp(type,"COLOR")) {
    if (data_len == 6) {
//        ws2812_setColor(0, dataBufUc);
      ws2812_setColor(0, dataBuf);
      power = 1;
    }
    ws2812_getColor(0, svalue, ssvalue);
  }
  else if (!strcmp(type,"DIMMER")) {
    if ((data_len > 0) && (payload >= 0) && (payload <= 100)) {
      sysCfg.ws_dimmer = payload;
      power = 1;
#ifdef USE_DOMOTICZ
      mqtt_publishDomoticzPowerState(index);
#endif  // USE_DOMOTICZ
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Dimmer\":%d}"), sysCfg.ws_dimmer);
  }
  else if (!strcmp(type,"LEDTABLE")) {
    if ((data_len > 0) && (payload >= 0) && (payload <= 2)) {
      switch (payload) {
      case 0: // Off
      case 1: // On
        sysCfg.ws_ledtable = payload;
        break;
      case 2: // Toggle
        sysCfg.ws_ledtable ^= 1;
        break;
      }
      ws2812_update();
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"LedTable\":\"%s\"}"), (sysCfg.ws_ledtable) ? MQTT_STATUS_ON : MQTT_STATUS_OFF);
  }
  else if (!strcmp(type,"FADE")) {
    if ((data_len > 0) && (payload >= 0) && (payload <= 2)) {
      switch (payload) {
      case 0: // Off
      case 1: // On
        sysCfg.ws_fade = payload;
        break;
      case 2: // Toggle
        sysCfg.ws_fade ^= 1;
        break;
      }
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Fade\":\"%s\"}"), (sysCfg.ws_fade) ? MQTT_STATUS_ON : MQTT_STATUS_OFF);
  }
  else if (!strcmp(type,"SPEED")) {  // 1 - fast, 5 - slow
    if ((data_len > 0) && (payload > 0) && (payload <= 5)) {
      sysCfg.ws_speed = payload;
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Speed\":%d}"), sysCfg.ws_speed);
  }
  else if (!strcmp(type,"WIDTH")) {
    if ((data_len > 0) && (payload >= 0) && (payload <= 4)) {
      sysCfg.ws_width = payload;
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Width\":%d}"), sysCfg.ws_width);
  }
  else if (!strcmp(type,"WAKEUP")) {
    if ((data_len > 0) && (payload > 0) && (payload < 3601)) {
      sysCfg.ws_wakeup = payload;
      if (sysCfg.ws_scheme == 1) sysCfg.ws_scheme = 0;
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"WakeUp\":%d}"), sysCfg.ws_wakeup);
  }
  else if (!strcmp(type,"SCHEME")) {
    if ((data_len > 0) && (payload >= 0) && (payload <= 9)) {
      sysCfg.ws_scheme = payload;
      if (sysCfg.ws_scheme == 1) ws2812_resetWakupState();
      power = 1;
      ws2812_resetStripTimer();
    }
    snprintf_P(svalue, ssvalue, PSTR("{\"Scheme\":%d}"), sysCfg.ws_scheme);
  }
  else {
    serviced = false;  // Unknown command
  }
#endif

  return serviced;
}

#endif  // USE_DSSERIAL
