#include <stdio.h>
#include <windows.h>
#include <conio.h>

extern HANDLE handle_in;
extern HANDLE handle_out;
CONSOLE_SCREEN_BUFFER_INFO csbi;         //���崰�ڻ�������Ϣ�ṹ��

void DisplayMousePosition(COORD pos);    //��ʾ�������λ��

void gotoxy(int x, int y);   //������Ƶ�����Ϊ(x,y)��λ��

void mouse_tracer_update();

void mouse_tracer_update()
{
    // handle_in = GetStdHandle(STD_INPUT_HANDLE);       //��ñ�׼�����豸���
    // handle_out = GetStdHandle(STD_OUTPUT_HANDLE);     //��ñ�׼����豸���
     INPUT_RECORD inputRec;       //���������¼��ṹ��
     DWORD res;       //���ڴ洢��ȡ��¼
     COORD pos;       //���ڴ洢��굱ǰλ��
     COORD size = {80, 25};   //���ڻ�������С
     GetConsoleScreenBufferInfo(handle_out, &csbi);   //��ô��ڻ�������Ϣ
     SetConsoleScreenBufferSize(handle_out, size);    //���ô��ڻ�������С
     for (;;)
     {
         ReadConsoleInput(handle_in, &inputRec, 1, &res);       //��ȡ�����¼�
         pos = inputRec.Event.MouseEvent.dwMousePosition;     //��õ�ǰ���λ��
         gotoxy(0, 24);   //�ڵ�25����ʾ���λ��
         DisplayMousePosition(pos);       //��ʾ���λ��
         //printf("\ninputRec.EventTyp: %d\n", inputRec.EventType);
         //printf("\ninputRec.Event.MouseEvent.dwEventFlags: %ld\n", inputRec.Event.MouseEvent.dwEventFlags);
         if(inputRec.EventType == MOUSE_EVENT)     //�����ǰΪ����¼�
         {
              gotoxy(pos.X, pos.Y);
                            //˫���˳�
              if (inputRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
              {
                  //printf("\nbreak\n");
                  break;
              }
              //����������������ַ�A
              else if (inputRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
               {
                 putchar( 'A');
               }
              //��������Ҽ�������ַ�B
               else if (inputRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
              {
                 putchar( 'B');
              }

        }
    }
    moveCursorTo(0,0);
    //CloseHandle(handle_out);
    //CloseHandle(handle_in);
    return ;
}

void DisplayMousePosition(COORD pos)
{
     COORD dis = {0, 24};         //�ڵ�24����ʾ���λ��
     WORD att = FOREGROUND_GREEN | FOREGROUND_INTENSITY;  //�ı�����
     GetConsoleScreenBufferInfo(handle_out, &csbi);   //��ô��ڻ�������Ϣ
     printf("X = %3d, Y = %3d", (  int)pos.X, ( int)pos.Y);
     FillConsoleOutputAttribute(handle_out, att, 16, dis, NULL);   //����ı�����
     return;
}

void gotoxy(int x,  int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(handle_out, pos);
}
