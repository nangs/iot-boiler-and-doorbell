# iot-boiler-and-doorbell

manage boiler zones activation and notify doorbell ring

## prerequisites

- esp8266 nodemcu
- opto coupled relays board
- sdcard breakout board

## setup

- sdcard `CS->D0 CLK->D5 MISO->D6 MOSI->D7`
- connect through serial
- type `CLTR+C` to stop wifi searching then type `?` to get commands table
- set wifi ssid and pwd through commands then type `reconnect` to test wifi conn

```
COMMANDS TABLE
------------------------------------------------------------------------
set wifi ssid <ssid>           | Set WiFi access point id
set wifi pwd <pwd>             | Set WiFi access point pwd
reconnect                      | Reconnect WiFi

reconnect
processing cmd [reconnect]
readed ssid [labwlan] from eeprom
Trying connecting SSID:[labwlan]
Connecting WiFi ( press CTRL+C to stop )
.You're connected to the network
SSID: labwlan
BSSID: B0:4E:26:C4:F:56
signal strength (RSSI): -64
IP Address: 10.10.3.11
MAC address: DC:4F:22:1C:2E:E2
Type ? for commands
```
