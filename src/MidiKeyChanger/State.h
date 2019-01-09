#pragma once
#include "arduino.h"
#include "common.h"
#include "pinMonitor.h"
#include "customMIDI.h"
#include "midiMng.h"

#define LONG_PUSH_MS 1000
#define PLAY_TO_KEYADD_TIME (int)(LONG_PUSH_MS/(CHATTERING_SPAN))

enum STATE {
    INIT, //��������
    PLAY, //�ʏ퓮�쒆
    KEY_ADD, //�L�[�o�^���[�h
    CH_CHANGE, //�`�����l���ύX���[�h
};

class State {
public:
    void init();
    void pinPushEvent(PinMonitor *pinMonitor);
    void timerFunctionPush(const PinMonitor *pinMonitor);
    void timerFunctionPushKeep(const PinMonitor *pinMonitor);
    enum STATE _state;
private:
    void statePlay(PinMonitor *pinMonitor);
    void stateKeyAdd(PinMonitor *pinMonitor);
    int _pushToKeyAddCount;
    int _keyAddCountToPush;
    bool _pushLongKeep;
    bool _pushLongKeepKeyAdd;

private:
    void stateKeyAddRelease(PinMonitor *pinMonitor);
    void stateKeyAddKeep(PinMonitor *pinMonitor);
    void statePlayAddRelease(PinMonitor *pinMonitor);
    void statePlayAddKeep(PinMonitor *pinMonitor);
    void stateKeyAddStart(PinMonitor *pinMonitor);
    void resetStateCount();
};