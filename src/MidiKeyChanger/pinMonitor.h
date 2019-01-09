#pragma once
// #include "hardInterface.h"
#include "common.h"

enum EventChangeState {
    NONE,
    PUSH_START,
    PUSH_KEEP,
    PUSH_RELEASE,
};

class PinMonitor {
public:
    PinMonitor();
    void setPinMonitor(int pinNo, Common::PIN_KIND kind);
    int _onCount; //スイッチONになっている状態
    int _offCount; //スイッチOFFになっている状態
    int _pinNo; //ピンアサイン
    enum Common::PINSTATE _state; //ピンのHIGH、LOW
    enum Common::PINMON_STATE _monState; //チャタリング除去用のスイッチ状態
    enum Common::PIN_KIND _kind; //ピンの種類
    enum EventChangeState _eventChangeState; //イベント発生時の状態
};