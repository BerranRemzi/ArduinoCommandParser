#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>
#include <stdbool.h>

#ifdef ARDUINO
#include "Arduino.h"
#endif // !ARDUINO

enum {
  FUNCTION,
  ADDR_LOW,
  ADDR_HIGH,
  DATA_SIZE,
  DATA_1,
  DATA_2,
  DATA_3,
  DATA_4
};

#define END_OF_COMMANDS 0xFF

typedef struct {
    uint8_t command;
    void(*function)(uint8_t * data);
}CommandRxList_t;

const uint8_t error[] = {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void Command(uint8_t command, uint8_t * data);
void Command_Init(CommandRxList_t * _input, uint8_t _commandCount);
bool Command_IsReady(uint8_t * data);
uint16_t Command_Address(uint8_t * data);
uint8_t GetPacketSize(uint8_t * _input);
void Command_Compute(uint8_t * _input);
uint16_t Command_GetAddress(uint8_t * _input);
uint8_t Command_GetByte(uint8_t * _input);
bool IsDataCorrect(uint8_t * _input, const uint8_t _count);

#endif // !COMMAND_H
