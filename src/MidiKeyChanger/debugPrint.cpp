#include "debugPrint.h"
#include <string.h>

/**
 * デバッグ用シリアルポート初期化
 * */
SoftwareSerial _serial(DEBUG_PORT_RX, DEBUG_PORT_TX);

void DebugPrint::init() {
    // _serial = SoftwareSerial(DEBUG_PORT_RX,DEBUG_PORT_TX);
    _serial.begin(DEBUG_PORT_BAUDRATE);
}

void DebugPrint::startupMessage() {
    _serial.println(PUT_VERSION);
    _serial.println("developer   : simone");
    _serial.println("twitter     : @fxsimone");
}

void DebugPrint::print(const char *message) {
    _serial.print(message);
}

void DebugPrint::print(String message) {
    _serial.print(message);
}

void DebugPrint::println(const char *message) {
    _serial.println(message);
}

void DebugPrint::println(String message) {
    _serial.println(message);
}

// void DebugPrint::cmpStr(const char *str1, const char *str2, char *buf){

// }