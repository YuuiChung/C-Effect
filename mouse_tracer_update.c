#include <stdio.h>
#include <windows.h>
#include <conio.h>

extern HANDLE handle_in;
extern HANDLE handle_out;
CONSOLE_SCREEN_BUFFER_INFO csbi;         //定义窗口缓冲区信息结构体

void DisplayMousePosition(COORD pos);    //显示鼠标所在位置

void gotoxy(int x, int y);   //将光标移到坐标为(x,y)的位置

void mouse_tracer_update();

void mouse_tracer_update()
{
    // handle_in = GetStdHandle(STD_INPUT_HANDLE);       //获得标准输入设备句柄
    // handle_out = GetStdHandle(STD_OUTPUT_HANDLE);     //获得标准输出设备句柄
     INPUT_RECORD inputRec;       //定义输入事件结构体
     DWORD res;       //用于存储读取记录
     COORD pos;       //用于存储鼠标当前位置
     COORD size = {80, 25};   //窗口缓冲区大小
     GetConsoleScreenBufferInfo(handle_out, &csbi);   //获得窗口缓冲区信息
     SetConsoleScreenBufferSize(handle_out, size);    //设置窗口缓冲区大小
     for (;;)
     {
         ReadConsoleInput(handle_in, &inputRec, 1, &res);       //读取输入事件
         pos = inputRec.Event.MouseEvent.dwMousePosition;     //获得当前鼠标位置
         gotoxy(0, 24);   //在第25行显示鼠标位置
         DisplayMousePosition(pos);       //显示鼠标位置
         //printf("\ninputRec.EventTyp: %d\n", inputRec.EventType);
         //printf("\ninputRec.Event.MouseEvent.dwEventFlags: %ld\n", inputRec.Event.MouseEvent.dwEventFlags);
         if(inputRec.EventType == MOUSE_EVENT)     //如果当前为鼠标事件
         {
              gotoxy(pos.X, pos.Y);
                            //双击退出
              if (inputRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
              {
                  //printf("\nbreak\n");
                  break;
              }
              //单击鼠标左键，输出字符A
              else if (inputRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
               {
                 putchar( 'A');
               }
              //单击鼠标右键，输出字符B
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
     COORD dis = {0, 24};         //在第24行显示鼠标位置
     WORD att = FOREGROUND_GREEN | FOREGROUND_INTENSITY;  //文本属性
     GetConsoleScreenBufferInfo(handle_out, &csbi);   //获得窗口缓冲区信息
     printf("X = %3d, Y = %3d", (  int)pos.X, ( int)pos.Y);
     FillConsoleOutputAttribute(handle_out, att, 16, dis, NULL);   //填充文本属性
     return;
}

void gotoxy(int x,  int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(handle_out, pos);
}
