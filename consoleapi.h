#ifndef CONSOLEAPI_H_INCLUDED
#define CONSOLEAPI_H_INCLUDED

#include <windows.h>
/** 光标操作 ========================================================
*/
extern void hideCursor();                  // 隐藏光标
extern void showCursor();                  // 显示光标
extern void moveCursorTo(int x, int y);    // 移动光标至点（x, y）
extern COORD getMousePosition();           /* 获取光标位置 */

/** 屏幕操作 ========================================================
*/
extern void clearScreen();                             /* 清屏 */
extern void setConsoleWindowSize(int width, int height);   // 设置命令行窗口大小
extern void printCharAt(int pos_x, int pos_y, char ch);   // 在指定坐标位置显示字符
extern void clearCharAt(int pos_x, int pos_y);            // 清楚指定位置字符


/** 颜色操作 ========================================================
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

/** 音乐操作 ========================================================
*/
extern void playMusic(char fileName[]);


/** 其它操作 ========================================================
*/
extern int getRandomInt(int min, int max);        // 获取1个随机数，大小在min和max之间

#endif // CONSOLEAPI_H_INCLUDED
