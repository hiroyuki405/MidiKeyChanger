
#include "timerParameter.h"
using namespace Common;

TimerParameter::TimerParameter() {
}

void TimerParameter::timerInit(ULONG time, void(*function)(), bool one_loop) {
    _function = function;
    _oneLoop = one_loop;
    _timeSpan = time;
    resetTimer();
}

bool TimerParameter::timerCompareCheck() {
    ULONG now = millis();
    if (now >= _timeLimit + _timeRest && _enabled) {

        if (_oneLoop) {
            resetTimer();
        } else {
            _enabled = FALSE;
        }
        return TRUE;
    }

    return FALSE;
}

void TimerParameter::functionBegin() {
    _function();
}

void TimerParameter::resetTimer() {
    _timeStart = millis();
    _timeLimit = _timeStart;

    _timeRest = Common::Calc::ULONG_AddValue(&_timeLimit, _timeSpan);
    _enabled = TRUE;
}
