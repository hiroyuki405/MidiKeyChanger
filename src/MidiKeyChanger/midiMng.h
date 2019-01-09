// midiMng.h
#pragma once
#include "arduino.h"
#include "common.h"
#include "customMIDI.h"
#include "hardInterface.h"
#include "State.h"

#define MIDI_CH MIDI_CHANNEL_OMNI

#define MIDI_BANK_CH 16
#define MIDI_BANK_SIZE 9
#define DEFAULT_C 60

class MidiMng {
public:
    void initMidiCh();
    void midiMonitor();
    void midiBankNext();
    void midiBankPrev();
    void midiChNext();
    void midiChPrev();

private:
    MIDIDATAS _midiDatas;
    enum Common::NOTE_NUMBER _note[MIDI_BANK_CH][MIDI_BANK_SIZE];
    void midiBankClear();
    int _midiBankChIndex;
    int _midiBankSizeIndex;
    void keyChange();
    Common::NOTE_NUMBER _centerC;
    void stateKeyAdd();
    enum Common::NOTE_NUMBER getNote(LPMIDIDATAS pMidiData);
};

