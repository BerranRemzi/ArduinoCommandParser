#include "Command.h"
#include "UserCommands.h"

enum COMMANDS {
  ERROR,
  LOGIN,
  READ,
  WRITE,
  READ_ACTUATOR,
  WRITE_ACTUATOR,
  READ_SENSOR,
  RUN_FUNCTION,
  END_OF_FUNCTIONS
};

CommandRxList_t CommandList[] =
{
  { ERROR,           UserCommand_Error        },
  { LOGIN,           UserCommand_Login        },
  { READ,            UserCommand_Read         },
  { WRITE,           UserCommand_Write        },
  { READ_ACTUATOR,   UserCommand_ReadActuator },
  { WRITE_ACTUATOR,  UserCommand_WriteActuator},
  { READ_SENSOR,     UserCommand_ReadSensor   },
  { RUN_FUNCTION,    UserCommand_RunFunction  }
};

uint8_t buffer[64];

void setup() {
  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);
  Command_Init(CommandList, END_OF_FUNCTIONS);
}

void loop() {
  Command_Compute(buffer);
}
