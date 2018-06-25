#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "consoleapi.h"

char musicShowMenu();

void music_example()
{
    char fileName[50];
    char choice;

    while(1)
    {
        choice = musicShowMenu();

        switch(choice)
        {
        case '1':
            strcpy(fileName,"music1.txt");
            break;
        case '2':
            strcpy(fileName,"music2.txt");
            break;
        case '3':
            printf("\n请输入文件名(包括全路径名)：");
            scanf("%s",fileName);
            break;
        default:
            return;
        }

        playMusic(fileName);

    }
}

char musicShowMenu()
{
    setColor(BLACK, 0, GREEN, 1);
    clearScreen();
    moveCursorTo(0, 0);

    printf("本程序采用编码的形式播放音乐。\n");
    printf("\n用记事本编辑乐谱，然后通过输入文件名播放音乐\n");
    printf("乐谱文件可以自创，也可以参考别人的\n");
    printf("\n现在可以先输入数字再按回车播放音乐：\n");
    printf("1 播放指定音乐music1\n");
    printf("2 播放指定音乐music2\n");
    printf("3 通过程序文件名播放音乐\n");
    printf("0 退出\n");

    printf("请选择：");

    return getch();
}
