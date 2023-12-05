#include "../import/defsys.h"

void EnableAnsi(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleOut;
    GetConsoleMode(handleOut, &consoleOut);
    consoleOut |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handleOut, consoleOut);
}