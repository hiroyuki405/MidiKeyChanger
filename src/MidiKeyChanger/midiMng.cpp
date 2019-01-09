
#include "midiMng.h"
MidiMng g_midiMng;
extern HardInterFace g_hardInterFace;
extern State g_state;

using namespace Common;
using namespace MIDI_NAMESPACE;

void MidiMng::initMidiCh() {
    g_hardInterFace.initMidi(MIDI_CH);
    String str = String("set MIDI CH : " + String(MIDI_CH));
    DebugPrint::println(str);
    midiBankClear();
    DebugPrint::println(String("lowest: " + String(NOTE_NUMBER::NOTE_Cd2) +
            "max" + String(NOTE_NUMBER::NOTE_MAX) + "   Center" + String(_centerC)
            ));
}

/**
 * MIDIキーチェンジャーのキーバンクをリセット
 * */
void MidiMng::midiBankClear() {
    _midiBankChIndex = 0;
    _midiBankSizeIndex = 0;
    _centerC = (NOTE_NUMBER) DEFAULT_C;
    for (int x = 0; x < MIDI_BANK_CH; x++) {
        for (int y = 0; y < MIDI_BANK_SIZE; y++) {
            g_midiMng._note[x][y] = _centerC;
        }
    }
}

void MidiMng::keyChange() {
    bool ret = g_hardInterFace.getMidi(&g_midiMng._midiDatas);
    // if (ret){
    // 	if((g_midiMng._midiDatas._midiType == MidiType::NoteOn ||
    // 			g_midiMng._midiDatas._midiType == MidiType::NoteOff) ){

    // 	// DebugPrint::println("s");

    // 		// DebugPrint::print("Before : " + String(getNote(&g_midiMng._midiDatas)) +
    // 		// 	"   KEY:" +String(g_midiMng._note[_midiBankChIndex][_midiBankSizeIndex]));

    // 		int buf =(int)g_midiMng._note[_midiBankChIndex][_midiBankSizeIndex] -_centerC ;

    // 		DataByte key = (DataByte)((int)getNote(&g_midiMng._midiDatas) + buf);
    // 		g_midiMng._midiDatas._dataByte1 = key;

    // 		// DebugPrint::println("   After : " + String(getNote(&g_midiMng._midiDatas)));
    // 	}
    // 	// g_hardInterFace.sendMidi(&g_midiMng._midiDatas);
    // 	// g_hardInterFace.ledFlash(LOW);
    // }	
}

void MidiMng::midiMonitor() {
    switch (g_state._state) {
        case STATE::INIT:
            break;
        case STATE::PLAY:
            keyChange();

            break;
        case STATE::KEY_ADD:
            stateKeyAdd();
            break;
    }
    // HardInterFace::ledFlash(PINSTATE::ON);
    // bool ret =  g_hardInterFace.getMidi(&g_midiMng._midiDatas);
    // if (ret) {
    // 	// DebugPrint::println("s");
    // 	g_hardInterFace.sendMidi(&g_midiMng._midiDatas);
    // 	g_hardInterFace.ledFlash(HIGH);
    // }else{
    // 	g_hardInterFace.ledFlash(LOW);
    // }
}

void MidiMng::stateKeyAdd() {
    bool ret = g_hardInterFace.getMidi(&g_midiMng._midiDatas);
    if (ret) {
        if (g_midiMng._midiDatas._midiType == MidiType::NoteOn) {
            g_midiMng._note[_midiBankChIndex][_midiBankSizeIndex] =
                    getNote(&g_midiMng._midiDatas);
            DebugPrint::print(String("MIDI_BANK[") + String(_midiBankChIndex) + "]" +
                    String("[") + String(_midiBankSizeIndex) + "]"
                    );
            DebugPrint::println(String("  SetKey=" + String(g_midiMng._note[_midiBankChIndex][_midiBankSizeIndex])));
        }
    }
}

/**
 * MIDIメッセージからノートを特定する。
 * */
enum NOTE_NUMBER MidiMng::getNote(LPMIDIDATAS pMidiData) {
    return (NOTE_NUMBER) pMidiData->_dataByte1;
}

void MidiMng::midiChNext() {
    _midiBankChIndex = Calc::incrementLing(_midiBankChIndex, MIDI_BANK_CH);
}

void MidiMng::midiChPrev() {
    _midiBankChIndex = Calc::decrementLing(_midiBankChIndex, MIDI_BANK_CH);
}

void MidiMng::midiBankNext() {
    _midiBankSizeIndex = Calc::incrementLing(_midiBankSizeIndex, MIDI_BANK_SIZE);
    DebugPrint::print("next");
    DebugPrint::println(String(_midiBankSizeIndex));
}

void MidiMng::midiBankPrev() {
    _midiBankSizeIndex = Calc::decrementLing(_midiBankSizeIndex, MIDI_BANK_SIZE);
    DebugPrint::print("prev");
    DebugPrint::println(String(_midiBankSizeIndex));
}

