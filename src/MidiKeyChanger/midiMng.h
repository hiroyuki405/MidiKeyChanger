// midiMng.h
#pragma once
#include "arduino.h"
#include "hardInterface.h"
#include "common.h"


#define MIDI_CH MIDI_CHANNEL_OMNI

class MidiMng {
public:
	void initMidiCh();
	void midiMonitor();
	
private:
	Common::MIDIDATAS _midiDatas;
	
};
