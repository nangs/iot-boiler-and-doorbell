#ifndef _UTIL_H_
#define _UTIL_H_

// uncomment follow to disable debug
#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTHEX(x) Serial.print(x, HEX)
#define DEBUG_PRINTF(x, args...) Serial.printf(x, args)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTF(x, args...)
#define DEBUG_PRINTHEX(x)
#define DEBUG_PRINTLN(x)
#endif

#endif