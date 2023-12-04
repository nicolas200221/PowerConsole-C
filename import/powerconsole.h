#ifndef powerconsole_h
#define powerconsole_h

#ifdef _WIN32
#include <Windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include "defsys.h"
#include "colors.h"

#define CLSCR "\033[2J\033[H"
#define INVERT "\033[7m"
#define RESET "\033[m"

void ClearScr();
void Invert();
void Reset();
void SetForegroundColor(int color);
void SetBackgroundColor(int color);
void SetColor(int foregroundColor, int backgroundColor);
void MoveCursor(int x, int y);
#ifdef _WIN32
void GetCursorPosition(int (*array)[2]);
#else
void GetCursorPosition(int (*array)[2]);
#endif

#endif