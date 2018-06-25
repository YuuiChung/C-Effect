#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "consoleapi.h"

HANDLE hOut;
HANDLE hIn;

void DispMousePos(COORD pos);

void mouse_tracer() {
    INPUT_RECORD inputRecord;
	DWORD res;
	COORD pos = {0, 0};
	char ch = 'A';

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE); // 获取标准输入设备句柄
	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE ;
	// 背景是蓝色，文本颜色是黄色
	SetConsoleTextAttribute(hOut, att);
	clearScreen(); // 清屏


	while(1) {
		ReadConsoleInput(hIn, &inputRecord, 1, &res);

		if (inputRecord.EventType == MOUSE_EVENT) {
			if (inputRecord.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK){
				break; // 双击鼠标退出循环
			}

			pos = inputRecord.Event.MouseEvent.dwMousePosition;
			DispMousePos(pos);
			if (inputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
				FillConsoleOutputCharacter(hOut, ch, 1, pos, NULL);
			}
		}
		else{ // 键盘事件
            putchar('\b');
            ch = inputRecord.Event.KeyEvent.uChar.AsciiChar;
            if(ch == 'c'){
                clearScreen();
            }
		}
	}

	pos.X = pos.Y = 0;
	moveCursorTo(0,0);
}

// 在第40行显示鼠标位置
void DispMousePos(COORD pos) {
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo );
	COORD home = {0, 40};
	WORD att0 = BACKGROUND_INTENSITY ;
	FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, NULL);
	FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, NULL);
	char s[20];
	sprintf(s,"X = %2d, Y = %2d",pos.X, pos.Y);
	SetConsoleTextAttribute(hOut, att0);
	SetConsoleCursorPosition(hOut, home);
	WriteConsole(hOut, s, strlen(s), NULL, NULL);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性
	SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // 恢复原来的光标位置
}

