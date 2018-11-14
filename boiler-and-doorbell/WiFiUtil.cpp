#include "WiFiUtil.h"
#include "EEUtil.h"
#include "SerialOS.h"

WiFiServer server(WEB_PORT);

//
void reconnectWifi()
{
  if (server.status() != CLOSED)
    server.stop();

  String ssid = "";
  String pass = "";

  readWifiSSID(ssid);
  readWifiPWD(pass);

  Serial.printf("Trying connecting SSID:[%s]\n", ssid.c_str());

  WiFi.begin(ssid.c_str(), pass.c_str());

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true)
      ;
  }

  Serial.println("Connecting WiFi ( press CTRL+C to stop )");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print('.');
    if (Serial.available() && Serial.read() == 3)
    {
      printSyntaxHelp();
      return;
    }
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
  printCurrentNet();
  printWifiData();

  Serial.println("Type ? for commands");
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);

  server.begin();
}

//
void printWifiData()
{
  auto ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  for (int i = 0; i < 6; ++i)
  {
    Serial.print(mac[i], HEX);
    if (i != 5)
      Serial.print(":");
    else
      Serial.println();
  }
}

//
void printCurrentNet()
{
  Serial.printf("SSID: %s\n", WiFi.SSID().c_str());

  auto bssid = WiFi.BSSID();
  Serial.print("BSSID: ");
  for (int i = 0; i < 6; ++i)
  {
    Serial.print(bssid[i], HEX);
    if (i != 5)
      Serial.print(":");
    else
      Serial.println();
  }

  auto rssi = WiFi.RSSI();
  Serial.printf("signal strength (RSSI): %ld\n", rssi);
}