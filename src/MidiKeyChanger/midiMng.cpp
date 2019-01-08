
#include "midiMng.h"


void MidiMng::initMidiCh(){
	HardInterFace::initMidi(MIDI_CH);	
}


void MidiMng::midiMonitor()
{
	
		// HardInterFace::ledFlash(PINSTATE::ON);
	bool ret = HardInterFace::getMidi(&_midiDatas);
	if (ret) {
		Serial.print("CommingMidi");
		HardInterFace::sendMidi(&_midiDatas);
		HardInterFace::ledFlash(PINSTATE::ON);
	}else{
		HardInterFace::ledFlash(PINSTATE::OFF);
	}
}
