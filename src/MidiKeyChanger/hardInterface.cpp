#include "hardInterface.h"
MIDI_CREATE_DEFAULT_INSTANCE();


PinMonitor *HardInterFace::_pinMon[PIN_MONITOR::MONITOR_SIZE] = {
	new PinMonitor(PIN_LED)
};

PinMonitor::PinMonitor(int pinNo){
	_pinNo = pinNo;
	_onCount = 0;
	_offCount = 0;
	_state = PINSTATE::OFF;
	_monState = PINMON_STATE::NONE;
}

bool HardInterFace::getMidi(Common::LPMIDIDATAS pData)
{
	bool ret = MIDI.read();
	if (ret) {
		pData->_channel = MIDI.getChannel();
		pData->_midiType = MIDI.getType();
		pData->_dataByte1 = MIDI.getData1();
		pData->_dataByte2 = MIDI.getData2();
	}
	return ret;
}

void HardInterFace::sendMidi(const Common::LPMIDIDATAS data)
{
	MIDI.send(data->_midiType,
		data->_dataByte1,
		data->_dataByte2,
		data->_channel
	);
}

void HardInterFace::timerFuncPinMonitor(){
	for(int i = 0;i < PIN_MONITOR::MONITOR_SIZE; i++){
		switch(_pinMon[i]->_monState){
			case PINMON_STATE::UNSET:
				pinChange(_pinMon[i]);
				break;

			case PINMON_STATE::SET:
				if(_pinMon[i]->_state !=(PINSTATE)digitalRead(_pinMon[i]->_pinNo)){
					_pinMon[i]->_monState = PINMON_STATE::UNSET;
				}
				break;

			case PINMON_STATE::NONE:
			default:
				_pinMon[i]->_monState = PINMON_STATE::SET;
				_pinMon[i]->_onCount = 0;
				_pinMon[i]->_offCount = 0;
				_pinMon[i]->_state = (PINSTATE)digitalRead(_pinMon[i]->_pinNo);
				break;
		}
	}
}

void HardInterFace::initMidi(int ch)
{
	MIDI.begin(ch);
}

void HardInterFace::initPinMode(){
	// inputPin();
	outputPin();
	g_pTimerState.timerSet(CHATTERING_SPAN,
	HardInterFace::timerFuncPinMonitor,
	CHATTERING_FLAG);
}

void HardInterFace::ledFlash(PINSTATE light){
	digitalWrite(PIN_LED, light);
}

void HardInterFace::inputPin(){
	pinMode(PIN_NEXT,INPUT);	
	pinMode(PIN_PREV,INPUT);
}

void HardInterFace::outputPin(){
	pinMode(PIN_LED,OUTPUT);
	digitalWrite(PIN_LED,PINSTATE::OFF);
}


void HardInterFace::pinChange(PinMonitor *pin){
	if(digitalRead(pin->_pinNo) == PINSTATE::ON){
		pin->_onCount++;
	}else if(digitalRead(pin->_pinNo) == PINSTATE::OFF){
		pin->_offCount++;
	}

	if(pin->_offCount >= CHATTERING_COUNT || pin->_onCount >= CHATTERING_COUNT)
	{
		pin->_monState = PINMON_STATE::SET;
		pin->_onCount = 0;
		pin->_offCount = 0;
		if(pin->_offCount >= CHATTERING_COUNT){
			pin->_state = PINSTATE::OFF;
		}else{
			pin->_state = PINSTATE::ON;
		}
	}
}
