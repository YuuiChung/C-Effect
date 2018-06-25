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

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	hIn = GetStdHandle(STD_INPUT_HANDLE); // ��ȡ��׼�����豸���
	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE ;
	// ��������ɫ���ı���ɫ�ǻ�ɫ
	SetConsoleTextAttribute(hOut, att);
	clearScreen(); // ����


	while(1) {
		ReadConsoleInput(hIn, &inputRecord, 1, &res);

		if (inputRecord.EventType == MOUSE_EVENT) {
			if (inputRecord.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK){
				break; // ˫������˳�ѭ��
			}

			pos = inputRecord.Event.MouseEvent.dwMousePosition;
			DispMousePos(pos);
			if (inputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
				FillConsoleOutputCharacter(hOut, ch, 1, pos, NULL);
			}
		}
		else{ // �����¼�
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

// �ڵ�40����ʾ���λ��
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
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // �ָ�ԭ��������
	SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // �ָ�ԭ���Ĺ��λ��
}

