#include <stdio.h>
#include "import\powerconsole.h"

int main(void){
    #ifdef _WIN32
    EnableAnsi();
    #endif
    //SetForegroundColor(BLACK);
    //SetBackgroundColor(WHITE);
    //Invert();
    SetColor(RED, BYELLOW);
    MoveCursor(10, 10);
    printf("bella");
    Reset();
    getchar();
    ClearScr();
    return 0;
}