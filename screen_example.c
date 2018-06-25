#include <windows.h>
#include <stdio.h>
#include "consoleapi.h"
#include <conio.h>
extern void clrScreen(void);
void screen_example(){
    int x = 10, y = 10;
    char ch = 3;

    SetConsoleTitle("控制台游戏");

    // 设置命令行窗口大小为100X80，单位，字符
    setConsoleWindowSize(100, 80);

    printf("fljsahdfljsda;lf\n\t\tsafsad\n\tdsfsda\ndslkhflksda\n");
    printf("按任意键清除屏幕");
    getch();
    //clearScreen();
    clrScreen();
    moveCursorTo(0, 0);

    moveCursorTo(0, 1);
    printf("按任意键在点（%d，%d）输出字符：%c", x, y, ch);
    getch();
    printCharAt(x, y, ch);

    moveCursorTo(0, 2);
    printf("按任意键在点（%d，%d）清楚字符：%c", x, y, ch);
    getch();
    clearCharAt(x, y);
    moveCursorTo(0, 3);
    printf("按任意键退出");
    getch();
}
