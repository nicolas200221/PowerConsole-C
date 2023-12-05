#include <stdio.h>
#include "../import/powerconsole.h"

void ClearScr(){
    printf(CLSCR);
}
void Invert(){
    printf(INVERT);
}
void Reset(){
    printf(RESET);
}

void SetForegroundColor(int color){
    printf("\033[%dm", color - 10);
}
void SetBackgroundColor(int color){
    printf("\033[%dm", color);
}
void SetColor(int foregroundColor, int backgroundColor){
    printf("\033[%d;%dm", foregroundColor - 10, backgroundColor);
}
void MoveCursor(int x, int y){
    printf("\033[%d;%dH", y+1, x+1);
}
#ifdef _WIN32
void GetCursorPosition(int (*array)[2]){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *array[0] = csbi.dwCursorPosition.X;
    *array[1] = csbi.dwCursorPosition.Y;
}
#else
void GetCursorPosition(int (*array)[2]){
    struct termios original;
    struct termios raw;
    tcgetattr(STDIN_FILENO, &original);
    cfmakeraw(&raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    printf("\033[6n");
    scanf("\033[%d;%dR", array[0], array[1]);
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}
#endif