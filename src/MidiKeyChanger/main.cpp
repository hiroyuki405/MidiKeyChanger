#include "main.h"

extern MidiMng g_midiMng;
extern HardInterFace g_hardInterFace;
extern TimerState g_timerState;
extern State g_state;
// SoftwareSerial g_debugSerial(DEBUG_PORT_RX,DEBUG_PORT_TX);

void setup() {
    DebugPrint::init();
    DebugPrint::startupMessage();
    g_midiMng.initMidiCh();
    g_hardInterFace.initPinMode();
    g_timerState.init();
    g_state.init();
    delay(100);
    DebugPrint::println("initialized complete");
}

void loop() {
    g_timerState.timerUpdate();
    g_midiMng.midiMonitor();
}

/**
 * バージョン表記
 * */
void version() {
}
