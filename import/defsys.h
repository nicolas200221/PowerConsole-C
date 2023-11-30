#ifndef defsys_h
#define defsys_h
#ifdef _WIN32

#include <Windows.h>

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0X0004

void EnableAnsi(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleOut;
    GetConsoleMode(handleOut, &consoleOut);
    consoleOut |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handleOut, consoleOut);
}

#endif
#endif