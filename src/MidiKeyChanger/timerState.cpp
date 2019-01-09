#include "timerState.h"

TimerState g_timerState;
extern HardInterFace g_hardInterFace;

TimerState::TimerState() {

}

void TimerState::init() {
    if (timerSet(CHATTERING_SPAN, HardInterFace::timerFuncPinMonitor, TRUE)) {
        DebugPrint::println("TimerSet Success");
    } else {
        DebugPrint::println("TimerSet Error");
    }
}

bool TimerState::timerSet(ULONG time, void(*function)(), bool one_loop) {
    if (function == NULL) {
        return FALSE;
    }

    _timerParameter[_timerSize].timerInit(time, function, one_loop);
    _timerSize++;
    return TRUE;
}

void TimerState::timerUpdate() {
    for (int i = 0; i < _timerSize; i++) {
        if (_timerParameter[i].timerCompareCheck()) {
            _timerParameter[i].functionBegin();
        }
    }
}
