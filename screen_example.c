#include <windows.h>
#include <stdio.h>
#include "consoleapi.h"
#include <conio.h>
extern void clrScreen(void);
void screen_example(){
    int x = 10, y = 10;
    char ch = 3;

    SetConsoleTitle("����̨��Ϸ");

    // ���������д��ڴ�СΪ100X80����λ���ַ�
    setConsoleWindowSize(100, 80);

    printf("fljsahdfljsda;lf\n\t\tsafsad\n\tdsfsda\ndslkhflksda\n");
    printf("������������Ļ");
    getch();
    //clearScreen();
    clrScreen();
    moveCursorTo(0, 0);

    moveCursorTo(0, 1);
    printf("��������ڵ㣨%d��%d������ַ���%c", x, y, ch);
    getch();
    printCharAt(x, y, ch);

    moveCursorTo(0, 2);
    printf("��������ڵ㣨%d��%d������ַ���%c", x, y, ch);
    getch();
    clearCharAt(x, y);
    moveCursorTo(0, 3);
    printf("��������˳�");
    getch();
}
