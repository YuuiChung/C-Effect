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
            printf("\n�������ļ���(����ȫ·����)��");
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

    printf("��������ñ������ʽ�������֡�\n");
    printf("\n�ü��±��༭���ף�Ȼ��ͨ�������ļ�����������\n");
    printf("�����ļ������Դ���Ҳ���Բο����˵�\n");
    printf("\n���ڿ��������������ٰ��س��������֣�\n");
    printf("1 ����ָ������music1\n");
    printf("2 ����ָ������music2\n");
    printf("3 ͨ�������ļ�����������\n");
    printf("0 �˳�\n");

    printf("��ѡ��");

    return getch();
}
