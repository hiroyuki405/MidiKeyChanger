#include "main.h"


void setup() {
	// g_pMidiMng = new MidiMng();
	// g_pTimerState= new TimerState();
	version();
	g_MidiMng.initMidiCh();
	HardInterFace::initPinMode();
}

void loop() {
	g_MidiMng.midiMonitor();
}

void version(){
	Serial.begin(MY_BAUDRATE);
	Serial.println("Hello!");
	// Serial.println(PUT_VERSION);
}
