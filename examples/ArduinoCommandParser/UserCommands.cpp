#include "UserCommands.h"
#include "Command.h"

void UserCommand_Error(uint8_t * _input) {

}

void UserCommand_Login(uint8_t * _input) {

}

void UserCommand_Read(uint8_t * _input) {

}

void UserCommand_Write(uint8_t * _input) {

}

void UserCommand_ReadActuator(uint8_t * _input) {

}

void UserCommand_WriteActuator(uint8_t * _input) {
  //Command_GetAddress(_input);
  digitalWrite(LED_BUILTIN, _input[DATA_1]);
}

void UserCommand_ReadSensor(uint8_t * _input) {

}

void UserCommand_RunFunction(uint8_t * _input) {

}
