#include "Config.h"

//--------------------------------------

#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

#include <EEPROM.h>

#include "WiFiUtil.h"
#include "EEUtil.h"
#include "SerialOS.h"
#include "Util.h"
#include "SDUtil.h"

//=============================================================
// SETUP
//=============================================================

void setup()
{
  pinMode(SD_CARD_CSPIN, OUTPUT);
  digitalWrite(SD_CARD_CSPIN, HIGH);

  Serial.println("Setup serial");
  Serial.begin(SERIAL_SPEED);
  //  Serial.swap(); // use D8(TX) - D7(RX)

  while (Serial.available())
    Serial.read();

  SDInit();

  Serial.println("SD CARD CONTENTS:");
  SDList();

  EEInit();

  reconnectWifi();
}

//=============================================================
// LOOP
//=============================================================

void loop()
{
  if (Serial.available())
  {
    auto c = (char)Serial.read();
    if ((int)c != 255)
    {
      if (c == '?' && serialInput.length() == 0)
        printSyntaxHelp();
      else if (c == '\r')
        processSerialCmd();
      else if (c == 8) // backspace
        serialInput.remove(serialInput.length() - 1);
      else
        serialInput.concat(c);
    }
  }

  if (server.status() == CLOSED)
    return;
}
