#include <stdio.h>
#include "import/powerconsole.h"

int main(void){
    #ifdef _WIN32
    EnableAnsi();
    #endif
    //SetForegroundColor(BLACK);
    //SetBackgroundColor(WHITE);
    //Invert();
    SetColor(RED, BYELLOW);
    MoveCursor(10, 12);
    printf("bella");
    Reset();
    int array[2] = {0};
    GetCursorPosition(&array);
    getchar();
    printf("x: %d\ny: %d", array[0], array[1]);
    getchar();
    ClearScr();
    return 0;
}