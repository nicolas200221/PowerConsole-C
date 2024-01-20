#include "../import/defsys.h"

#ifdef _WIN32
void EnableAnsi(HANDLE* stdOut, DWORD* outputMode){
    *outputMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(*stdOut, *outputMode);
}
void DisableAnsi(HANDLE* stdOut, DWORD* outputMode){
    *outputMode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(*stdOut, *outputMode);
}
#endif
