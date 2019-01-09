#pragma once
#include <MIDI.h>

typedef struct MidiDatas {
    midi::MidiType _midiType;
    midi::DataByte _dataByte1;
    midi::DataByte _dataByte2;
    midi::Channel _channel;
} MIDIDATAS, *LPMIDIDATAS;