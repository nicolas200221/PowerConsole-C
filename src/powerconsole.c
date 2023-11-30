#include <stdio.h>
#include "..\import\powerconsole.h"

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