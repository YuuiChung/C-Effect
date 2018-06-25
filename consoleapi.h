#ifndef CONSOLEAPI_H_INCLUDED
#define CONSOLEAPI_H_INCLUDED

#include <windows.h>
/** ������ ========================================================
*/
extern void hideCursor();                  // ���ع��
extern void showCursor();                  // ��ʾ���
extern void moveCursorTo(int x, int y);    // �ƶ�������㣨x, y��
extern COORD getMousePosition();           /* ��ȡ���λ�� */

/** ��Ļ���� ========================================================
*/
extern void clearScreen();                             /* ���� */
extern void setConsoleWindowSize(int width, int height);   // ���������д��ڴ�С
extern void printCharAt(int pos_x, int pos_y, char ch);   // ��ָ������λ����ʾ�ַ�
extern void clearCharAt(int pos_x, int pos_y);            // ���ָ��λ���ַ�


/** ��ɫ���� ========================================================
*/
typedef enum Color{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    CYAN,
    MAGENTA,
    YELLOW
} Color;

extern void setColor(Color bColor, char bIntensity, Color fColor, char fIntensity);
extern void SetColor(unsigned short bColor,unsigned short fColor);

/** ���ֲ��� ========================================================
*/
extern void playMusic(char fileName[]);


/** �������� ========================================================
*/
extern int getRandomInt(int min, int max);        // ��ȡ1�����������С��min��max֮��

#endif // CONSOLEAPI_H_INCLUDED
