// main.h
#pragma once
#include "arduino.h"
#include "midiMng.h"
#include "timerState.h"
#include "hardInterface.h"

#define VERSION "1.0.0.0"
// #define PUT_VERSION "WakeUp MidiKeyChanger  "VERSION
#define MY_BAUDRATE 9600

MidiMng g_MidiMng;
TimerState g_TimerState;
void setup();
void loop();
void version();
