#include "../import/init.h"

#ifdef _WIN32
typedef struct consoleState_s{
    HANDLE stdIn;
    HANDLE stdOut;
    DWORD inputMode;
    DWORD outputMode;
} consoleState_t;

static consoleState_t consoleState;
void InitScr(){
    consoleState.stdIn = GetStdHandle(STD_INPUT_HANDLE);
    consoleState.stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    consoleState.outputMode = GetConsoleMode(consoleState.stdOut, &(consoleState.outputMode));
    consoleState.inputMode = GetConsoleMode(consoleState.stdIn, &(consoleState.inputMode));
    
    EnableAnsi(&consoleState.stdOut, &consoleState.outputMode);
    ClearScr();
}
void EndScr(){
    ClearScr();
    DisableAnsi(&consoleState.stdOut, &consoleState.outputMode);
}
#endif