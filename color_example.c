#include <stdio.h>
#include <conio.h>
#include "consoleapi.h"

extern void clrScreen(void);

void color_example(){
    Color bColor, fColor;
    char bIntensity, fIntensity;

    setColor(BLACK, 0, WHITE, 1);
    printf("下面演示底不加亮，字不加亮，按任意键继续\n");
    getch();
    clrScreen();
    moveCursorTo(0, 0);
    bIntensity = 0;
    fIntensity = 0;
    for(bColor = BLACK; bColor <= YELLOW; bColor++){
        for(fColor = BLACK; fColor <= YELLOW; fColor++){
            setColor(bColor, bIntensity, fColor, fIntensity);
            printf("    HELLO    \n");
        }
    }

    setColor(BLACK, 0, WHITE, 1);
    printf("下面演示底加亮，字不加亮，按任意键继续\n");
    getch();
    clrScreen();
    moveCursorTo(0, 0);
    bIntensity = 1;
    fIntensity = 0;
    for(bColor = BLACK; bColor <= YELLOW; bColor++){
        for(fColor = BLACK; fColor <= YELLOW; fColor++){
            setColor(bColor, bIntensity, fColor, fIntensity);
            printf("    HELLO    \n");
        }
    }


    setColor(BLACK, 0, WHITE, 1);
    printf("下面演示底加亮，字加亮，按任意键继续\n");
    getch();
    clrScreen();
    moveCursorTo(0, 0);
    bIntensity = 1;
    fIntensity = 1;
    for(bColor = BLACK; bColor <= YELLOW; bColor++){
        for(fColor = BLACK; fColor <= YELLOW; fColor++){
            setColor(bColor, bIntensity, fColor, fIntensity);
            printf("    HELLO    \n");
        }
    }


    setColor(BLACK, 0, WHITE, 1);
    printf("下面演示底不加亮，字加亮，按任意键继续\n");
    getch();
    clrScreen();
    moveCursorTo(0, 0);
    bIntensity = 0;
    fIntensity = 1;
    for(bColor = BLACK; bColor <= YELLOW; bColor++){
        for(fColor = BLACK; fColor <= YELLOW; fColor++){
            setColor(bColor, bIntensity, fColor, fIntensity);
            printf("    HELLO    \n");
        }
    }
    getch();
    setColor(BLACK, 0, WHITE, 1);
}
