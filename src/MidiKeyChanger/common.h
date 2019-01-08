// common.h
#pragma once
#include "arduino.h"
#include "limits.h"
#include <MIDI.h>

#include "midi_Defs.h"
#include "midi_Settings.h"
#include "midi_Message.h"

#define ULLONG unsigned long long
#define ULONG unsigned long
#define TRUE (1==1)
#define FALSE (1!=1)
#define LOOP_INTERVAL_US 5 
#define NULL_PTR_CEHCK(ptr) (ptr==NULL)
namespace Common {

	static ULONG  ULONG_AddValue(ULONG *value, ULONG add);
	typedef struct MidiDatas {
		
		MIDI_NAMESPACE::MidiType _midiType;
		MIDI_NAMESPACE::DataByte _dataByte1;
		MIDI_NAMESPACE::DataByte _dataByte2;
		MIDI_NAMESPACE::Channel  _channel;
	}MIDIDATAS, *LPMIDIDATAS;
}
