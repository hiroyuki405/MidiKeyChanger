#include "state.h"
using namespace Common;

State g_state;
extern MidiMng g_midiMng;

void State::init(){
    g_state._state = STATE::PLAY;
}

void State::pinPushEvent(PinMonitor *pinMonitor){
    // DebugPrint::println(String("push! " + String(pinMonitor->_pinNo)));
    switch(g_state._state){
        case STATE::PLAY: //通常動作モード
            statePlay(pinMonitor);
        break;
        case STATE::KEY_ADD: //調追加モード
            stateKeyAdd(pinMonitor);
        break;
    }
}



    // if(pinMonitor->_state == PINSTATE::ON){
    //     // DebugPrint::println("On!");
    // }

    // if(pinMonitor->_kind != Common::PIN_KIND::PIN_PREV){
    //     return;
    // }


    //長押しでKEY_ADD(調追加)モードに移行する。
    // if(g_state._pushToKeyAddCount >= PLAY_TO_KEYADD_TIME){
    //     g_state._state = STATE::KEY_ADD;
    //     g_state._pushToKeyAddCount = 0;
    //     g_state._pushLongKeep = TRUE;
    //     DebugPrint::println("Mode to KEY_ADD");
    // }

void State::resetStateCount(){
    _pushToKeyAddCount = 0;
    _keyAddCountToPush = 0;
}

/**
 * PLAY状態でPIN入力を受けた時の処理
 * */
void State::statePlay(PinMonitor *pinMonitor){
    
    // DebugPrint::print(String("PinNo :" + String(pinMonitor->_pinNo)));
    switch(pinMonitor->_eventChangeState){
        case EventChangeState::PUSH_KEEP:
            statePlayAddKeep(pinMonitor);
            break;
        case EventChangeState::PUSH_RELEASE:
            statePlayAddRelease(pinMonitor);
            // DebugPrint::println(String("PinNo :" + String(pinMonitor->_pinNo) + "  PUSH_RELEASE"));
        break;
        case EventChangeState::PUSH_START:
            resetStateCount();
            stateKeyAddStart(pinMonitor);
            // DebugPrint::println(String("PinNo :" + String(pinMonitor->_pinNo) + "  PUSH_START"));
            break;
        case EventChangeState::NONE:
            // DebugPrint::println("  NONE");
            break;
    }
}

void State::stateKeyAdd(PinMonitor *pinMonitor){
    switch(pinMonitor->_eventChangeState){
        case EventChangeState::PUSH_KEEP:
            stateKeyAddKeep(pinMonitor);
            break;
        case EventChangeState::PUSH_RELEASE:
            stateKeyAddRelease(pinMonitor);
            // DebugPrint::println(String("PinNo :" + String(pinMonitor->_pinNo) + "  PUSH_RELEASE"));
        break;
        case EventChangeState::PUSH_START:
            resetStateCount();
            stateKeyAddStart(pinMonitor);
            // DebugPrint::println(String("PinNo :" + String(pinMonitor->_pinNo) + "  PUSH_START"));
            break;
        case EventChangeState::NONE:
            // DebugPrint::println("  NONE");
            break;
    }
}

void State::stateKeyAddRelease(PinMonitor *pinMonitor){
    //状態遷移後のPREVボタンおしっぱ対策
    bool keep = (g_state._pushLongKeepKeyAdd && 
        pinMonitor->_kind == PIN_KIND::PIN_PREV);

    // DebugPrint::println(String(
    //      "KEEPFLAG:" + String(g_state._pushLongKeep) +
    //     "    KIND:" + String(pinMonitor->_kind == PIN_KIND::PIN_PREV) +
    //     "    State:" + String(pinMonitor->_state == PINSTATE::OFF) +
    //     "    keepflag:" + String(keep)
    //  ));

    if(keep){
        // DebugPrint::println("LongkeepReset KEY ADD");
        g_state._pushLongKeepKeyAdd = FALSE;
    }
}

void State::stateKeyAddKeep(PinMonitor *pinMonitor){
    if(g_state._pushLongKeepKeyAdd){
        return;
    }

    //PREVボタン長押しでPLAYモードに遷移
    if(pinMonitor->_kind == PIN_KIND::PIN_PREV){
        g_state._keyAddCountToPush++;
    }

    if(g_state._keyAddCountToPush >= PLAY_TO_KEYADD_TIME){
        g_state._state = STATE::PLAY;
        g_state._keyAddCountToPush= 0;
        g_state._pushLongKeep = TRUE;
        DebugPrint::println("Move to PLAY");
    }
}


void State::statePlayAddRelease(PinMonitor *pinMonitor){
    //状態遷移後のPREVボタンおしっぱ対策
    bool keep = (g_state._pushLongKeep && 
        pinMonitor->_kind == PIN_KIND::PIN_PREV);

    // DebugPrint::println(String(
    //      "KEEPFLAG:" + String(g_state._pushLongKeep) +
    //     "    KIND:" + String(pinMonitor->_kind == PIN_KIND::PIN_PREV) +
    //     "    State:" + String(pinMonitor->_state == PINSTATE::OFF) +
    //     "    keepflag:" + String(keep)
    //  ));

    if(keep){
        // DebugPrint::println("LongkeepReset StatePlayAddRelease");
        g_state._pushLongKeep = FALSE;
    }
}

void State::statePlayAddKeep(PinMonitor *pinMonitor){
    if(g_state._pushLongKeep){
        return;
    }

    //PREVボタン長押しでKEY ADDモードに遷移
    if(pinMonitor->_kind == PIN_KIND::PIN_PREV){
        g_state._pushToKeyAddCount++;
    }

    if(g_state._pushToKeyAddCount >= PLAY_TO_KEYADD_TIME){
        g_state._state = STATE::KEY_ADD;
        g_state._pushToKeyAddCount = 0;
        g_state._pushLongKeepKeyAdd = TRUE;
        
        DebugPrint::println("Move to KEY ADD");
    }
}

void State::stateKeyAddStart(PinMonitor *pinMonitor){
    switch(pinMonitor->_kind){
        case PIN_KIND::PIN_PREV:
            g_midiMng.midiBankPrev();
        break;
        case PIN_KIND::PIN_NEXT:
            g_midiMng.midiBankNext();
        break;
    }
}