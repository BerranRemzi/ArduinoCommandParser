#include "Command.h"




uint32_t buttonState;             // the current reading from the input pin
uint32_t lastButtonState = 0;   // the previous reading from the input pin
uint32_t lastDebounceTime = 0;  // the last time the output pin was toggled
uint32_t debounceDelay = 2;    // the debounce time; increase if the output flickers
uint32_t previousMillis = 0;
uint32_t previousAvailable = 0;
uint8_t bytesToRead = 0;

CommandRxList_t * pCommandList;
uint8_t commandCount = 0;

void Command(uint8_t command, uint8_t * data) {
  for (int i = 0; i < commandCount; i++) {
    if (command == pCommandList[i].command) {
      pCommandList[i].function(data);
    }
  }
}

void Command_Init(CommandRxList_t * _input, uint8_t _commandCount) {
  pCommandList = _input;
  commandCount = _commandCount;
  Serial.setTimeout(2);
}
uint16_t Command_Address(uint8_t * data) {
  return 0;
}

bool Command_IsReady(uint8_t * data) {
  return 0;
}

void Command_Compute(uint8_t * _input) {
  if (Serial.available()) {
    uint8_t count = Serial.readBytes(_input, 64);
    bool dataCorrect = IsDataCorrect(_input, count);

    if (dataCorrect == true) {
      Command(_input[FUNCTION], _input);
    }
  }
}
uint16_t Command_GetFunction(uint8_t * _input) {
  return _input[FUNCTION];
}

uint16_t Command_GetAddress(uint8_t * _input) {
  return _input[1] | (_input[1] << 8);
}

bool IsDataCorrect(uint8_t * _input, const uint8_t _count) {
  bool isCorrect = false;
  if (_count == 8) {
    if (_input[DATA_SIZE] == 1 && _input[DATA_2] == 0x00 && _input[DATA_3] == 0x00 && _input[DATA_4] == 0x00) {
      isCorrect = true;
    }
    if (_input[DATA_SIZE] == 2 && _input[DATA_3] == 0x00 && _input[DATA_4] == 0x00) {
      isCorrect = true;
    }
    if (_input[DATA_SIZE] == 3 && _input[DATA_4] == 0x00) {
      isCorrect = true;
    }
    if (_input[DATA_SIZE] == 4) {
      isCorrect = true;
    }
  }
  if (_count > 8) {
    if (_input[DATA_SIZE] == _count) {
      isCorrect = true;
    }
  }
  return isCorrect;
}
