#include <windows.h>
#include <stdio.h>
#include "consoleapi.h"
#include <conio.h>

extern HANDLE handle_in;
extern HANDLE handle_out;

void cursor_example(){
    //COORD pos;
    INPUT_RECORD inputRec;       //定义输入事件结构体
    DWORD res;       //用于存储读取记录
    COORD pos;       //用于存储鼠标当前位置
    POINT p;
    showCursor();
    printf("按任意键隐藏光标");
    getch();
    hideCursor();

    printf("\n按任意键显示光标");
//    getch();
    showCursor();

    printf("\n请单击或移动鼠标");
    //GetCursorPos(&p);
    for(; ;){
       ReadConsoleInput(handle_in, &inputRec, 1, &res);       //读取输入事件
       pos = inputRec.Event.MouseEvent.dwMousePosition;     //获得当前鼠标位置
       //printf("inputRec.EventType: %d\n", inputRec.EventType);
       if(inputRec.EventType == MOUSE_EVENT){
          printf("\n单击时光标位置(%ld, %ld)\n", pos.X, pos.Y);
          printf("\n移动鼠标到（%ld，%ld），按任意键退出", pos.X, pos.Y);
          moveCursorTo(pos.X, pos.Y);
          putch(3);
          getch();
          break;
       }
    }

}
