#include <windows.h>
#include <stdio.h>
#include "consoleapi.h"
#include <conio.h>

extern HANDLE handle_in;
extern HANDLE handle_out;

void cursor_example(){
    //COORD pos;
    INPUT_RECORD inputRec;       //���������¼��ṹ��
    DWORD res;       //���ڴ洢��ȡ��¼
    COORD pos;       //���ڴ洢��굱ǰλ��
    POINT p;
    showCursor();
    printf("����������ع��");
    getch();
    hideCursor();

    printf("\n���������ʾ���");
//    getch();
    showCursor();

    printf("\n�뵥�����ƶ����");
    //GetCursorPos(&p);
    for(; ;){
       ReadConsoleInput(handle_in, &inputRec, 1, &res);       //��ȡ�����¼�
       pos = inputRec.Event.MouseEvent.dwMousePosition;     //��õ�ǰ���λ��
       //printf("inputRec.EventType: %d\n", inputRec.EventType);
       if(inputRec.EventType == MOUSE_EVENT){
          printf("\n����ʱ���λ��(%ld, %ld)\n", pos.X, pos.Y);
          printf("\n�ƶ���굽��%ld��%ld������������˳�", pos.X, pos.Y);
          moveCursorTo(pos.X, pos.Y);
          putch(3);
          getch();
          break;
       }
    }

}
