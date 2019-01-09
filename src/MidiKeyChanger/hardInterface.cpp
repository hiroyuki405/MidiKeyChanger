#include "hardInterface.h"
MIDI_CREATE_DEFAULT_INSTANCE();
// MIDI_CREATE_INSTANCE(HardwareSerial,Serial, midiUSBPC);
using namespace Common;
HardInterFace g_hardInterFace;
extern State g_state;
extern TimerState g_timerState;
extern MidiMng g_midiMng;

/**
 * ���̓s���Ď��N���X�@�R���X�g���N�^
 * */
PinMonitor::PinMonitor() {
}

/**
 * �R�[���o�b�N�֐����Z�b�g
 * */
void HardInterFace::setFunction(int pinNo, Common::PIN_KIND kind) {
    g_hardInterFace._pinMon[_pinMonSize].setPinMonitor(pinNo, kind);
    _pinMonSize++;
}

bool HardInterFace::getMidi(LPMIDIDATAS pData) {
    bool ret = MIDI.read();
    if (ret) {
        pData->_channel = MIDI.getChannel();
        pData->_midiType = MIDI.getType();
        pData->_dataByte1 = MIDI.getData1();
        pData->_dataByte2 = MIDI.getData2();
    }
    return ret;
}

void HardInterFace::sendMidi(const LPMIDIDATAS data) {
    MIDI.send(data->_midiType,
            data->_dataByte1,
            data->_dataByte2,
            data->_channel
            );
}

/**
 * �s�����͂��`���^�����O���������ĊĎ�����
 * */
void HardInterFace::timerFuncPinMonitor() {
    for (int i = 0; i < g_hardInterFace._pinMonSize; i++) {
        PinMonitor *pin = &g_hardInterFace._pinMon[i];
        switch (pin->_monState) {
            case Common::PINMON_STATE::UNSET: //�s���̓��͂��s����ȏ��
                // DebugPrint::println(String("UNSET:"+ String(g_hardInterFace._pinMon[i]._pinNo) ));
                pin->_eventChangeState = EventChangeState::NONE;
                pinChange(pin);
                break;

            case Common::PINMON_STATE::SET: //�s���̓��͂����肵�Ă�����
                // DebugPrint::println(String("SET:"+ String(g_hardInterFace._pinMon[i]._pinNo) + 
                // "   _state=" + String(pin->_state) + "   now:" +
                // checkDigitalRead(digitalRead(pin->_pinNo)))
                // );

                if (pin->_state == PINSTATE::ON) {
                    pin->_eventChangeState = EventChangeState::PUSH_KEEP;
                } else {
                    pin->_eventChangeState = EventChangeState::NONE;
                }
                if (pin->_state != checkDigitalRead(digitalRead(pin->_pinNo))) {
                    pin->_monState = Common::PINMON_STATE::UNSET;
                } else {
                    g_state.pinPushEvent(pin);
                }

                break;

            case Common::PINMON_STATE::NONE: //���̓s�������l
            default:
                // DebugPrint::println(String("NONE:"+ String(pin->_pinNo) ));
                pin->_monState = Common::PINMON_STATE::SET;
                pin->_onCount = 0;
                pin->_offCount = 0;
                // g_hardInterFace._pinMon[i]._state = (Common::PINSTATE)digitalRead(g_hardInterFace._pinMon[i]._pinNo);
                pin->_state = PINSTATE::OFF;
                break;
        }
    }
}

enum PINSTATE HardInterFace::checkDigitalRead(int read) {
    enum PINSTATE ret;
    if ((PINSTATE) read == PINSTATE::ON) {
        // DebugPrint::println("ON");
        ret = PINSTATE::ON;
    } else {
        ret = PINSTATE::OFF;
    }
    return ret;
}

void HardInterFace::initMidi(int ch) {
    MIDI.begin(ch);
}

void HardInterFace::initPinMode() {
    inputPin();
    outputPin();
    initOutput();
    setFunction(PIN_NO_NEXT, PIN_KIND::PIN_NEXT);
    setFunction(PIN_NO_PREV, PIN_KIND::PIN_PREV);
    // g_timerState.timerSet(CHATTERING_SPAN,
    // g_hardInterFace.timerFuncPinMonitor,
    // CHATTERING_FLAG);
    DebugPrint::println("Hardware Initialized");
}

void HardInterFace::initOutput() {
    g_hardInterFace._segmentIndex = (SEGMENT) 0;
}

/**
 * LED�������E�_��������B
 * */
void HardInterFace::ledFlash(int light) {
    digitalWrite(PIN_LED, light);
}

void HardInterFace::inputPin() {
    pinMode(PIN_NO_NEXT, INPUT);
    pinMode(PIN_NO_PREV, INPUT);
}

void HardInterFace::outputPin() {
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, PINSTATE::OFF);
}

void HardInterFace::segmentInit() {
    for (int i = 0; i < SEG_CHAR::MAX; i++) {
        switch ((SEG_CHAR) i) {
            case SEG_A:

                g_hardInterFace._segChar[i]._segChar = SEGMENT_A;
                break;
            case SEG_B:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_B;
                break;
            case SEG_C:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_C;
                break;
            case SEG_D:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_D;
                break;
            case SEG_E:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_E;
                break;
            case SEG_F:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_F;
                break;
            case SEG_G:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_G;
                break;
            case SEG_ZERO:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_ZERO;
                break;
            case SEG_ONE:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_ONE;
                break;
            case SEG_TWO:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_TWO;
                break;
            case SEG_THREE:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_THREE;
                break;
            case SEG_FOUR:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_FOUR;
                break;
            case SEG_FIVE:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_FIVE;
                break;
            case SEG_SIX:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_SIX;
                break;
            case SEG_SEVEN:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_SEVEN;
                break;
            case SEG_EIGHT:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_EIGHT;
                break;
            case SEG_NINE:
                g_hardInterFace._segChar[i]._segChar = SEGMENT_NINE;
                break;
        }
    }
}

/**
 * �`���^�����O��������
 * */
void HardInterFace::pinChange(PinMonitor *pin) {
    if (checkDigitalRead(digitalRead(pin->_pinNo)) == PINSTATE::ON) {
        pin->_onCount++;
    } else if (checkDigitalRead(digitalRead(pin->_pinNo)) == PINSTATE::OFF) {
        pin->_offCount++;
    }

    //���͂����������Ă���s�����͂𔽉f
    if (pin->_offCount >= CHATTERING_COUNT || pin->_onCount >= CHATTERING_COUNT) {
        // DebugPrint::println(String(pin->_pinNo));
        if (pin->_offCount >= CHATTERING_COUNT) {
            pin->_state = PINSTATE::OFF;
            pin->_eventChangeState = EventChangeState::PUSH_RELEASE;

        } else {
            pin->_state = PINSTATE::ON;
            pin->_eventChangeState = EventChangeState::PUSH_START;
        }
        pin->_monState = PINMON_STATE::SET;
        pin->_onCount = 0;
        pin->_offCount = 0;
        g_state.pinPushEvent(pin);
    }

    // 	DebugPrint::println(String("  PIN NO " + String(pin->_pinNo) +
    // "   OnCount: " +String(pin->_onCount) + 
    // "   OffCount :" + String(pin->_offCount) + "  _state :" + String(pin->_state)));
}
