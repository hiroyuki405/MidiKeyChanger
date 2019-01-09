#include "pinMonitor.h"
using namespace Common;

/**
 * 入力ピン監視の設定
 * */
void PinMonitor::setPinMonitor(int pinNo, enum PIN_KIND kind) {
    _pinNo = pinNo;
    _onCount = 0;
    _offCount = 0;
    _state = PINSTATE::OFF;
    _monState = PINMON_STATE::NONE;
    _kind = kind;
    _eventChangeState = EventChangeState::NONE;
}