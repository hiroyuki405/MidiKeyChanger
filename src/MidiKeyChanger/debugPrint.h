#pragma once
// #include "arduino.h"
#include <SoftwareSerial.h>

#define DEBUG_PORT_RX 11
#define DEBUG_PORT_TX 12
#define DEBUG_PORT_BAUDRATE 4800
#define VERSION "1.0.0.0"
#define PUT_VERSION "Ver. " VERSION

class DebugPrint {
public:
    static void init();
    // static void cmpStr(const char *str1, const char *str2, char *buf);
    static void print(const char * message);
    static void println(const char * message);
    static void print(String message);
    static void println(String message);
    static void startupMessage();

};