#ifndef USER_COMMANDS_H
#define USER_COMMANDS_H

#include "Arduino.h"
#include <stdint.h>
//#include "Command.h"

#ifdef __cplusplus
extern "C" {
#endif

void UserCommand_Error        (uint8_t * _input);
void UserCommand_Login        (uint8_t * _input);
void UserCommand_Read         (uint8_t * _input);
void UserCommand_Write        (uint8_t * _input);
void UserCommand_ReadActuator (uint8_t * _input);
void UserCommand_WriteActuator(uint8_t * _input);
void UserCommand_ReadSensor   (uint8_t * _input);
void UserCommand_RunFunction  (uint8_t * _input);

#ifdef __cplusplus
}
#endif


#endif // !USER_COMMANDS_H
