#include <stdio.h>
#include <conio.h>
#include "consoleapi.h"


extern void cursor_example();
extern void screen_example();
extern void color_example();
extern void color_stripe();
extern void color_matrix();
extern void mouse_tracer();
extern void music_example();
extern void game_marrie();
extern void mouse_tracer_update();

char showHelp();

//#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

void myCls(HANDLE);
HANDLE handle_in;
HANDLE handle_out;

void clrScreen(void)//清除屏幕
{
    //handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    myCls(handle_out);
    return;
}
void myCls(HANDLE hConsole)
{
    COORD coordScreen={0,0};//设置清屏后光标返回的屏幕左上角坐标
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;//保存缓冲区信息
    DWORD dwConSize;//当前缓冲区可容纳的字符数
    bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息
    //PERR(bSuccess,"GetConsoleScreenBufferInfo");
    dwConSize=csbi.dwSize.X * csbi.dwSize.Y;//缓冲区容纳字符数目
    //用空格填充缓冲区
    bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
    //PERR(bSuccess,"FillConsoleOutputCharacter");
    bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息
    //PERR(bSuccess,"ConsoleScreenBufferInfo");
    //填充缓冲区属性
    bSuccess=FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
    //PERR(bSuccess,"FillConsoleOutputAttribute");
    //光标返回屏幕左上角坐标
    bSuccess=SetConsoleCursorPosition(hConsole,coordScreen);
    //PERR(bSuccess,"SetConsoleCursorPosition");
    return;
}



int main(){
    char choice = 0;
    int ret = 0;
    handle_in = GetStdHandle(STD_INPUT_HANDLE);       //获得标准输入设备句柄
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);     //获得标准输出设备句柄
    while(1){
        choice = showHelp();

        switch(choice){
        case '1':
            cursor_example();
            break;
        case '2':
            screen_example();
            break;
        case '3':
            color_example();
            break;
        case '4':
            color_stripe();
            break;
        case '5':
            color_matrix();
            break;
        case '6':
            mouse_tracer_update();//mouse_tracer();
            //clearScreen();
            break;
        case '7':
            music_example();
            break;
        case '8':
            game_marrie();
            break;
        case '0':
            ret = MessageBox(NULL, "确定退出本程序!", "退出确认窗口", MB_YESNO);
            if (ret == IDYES) return 0;
            else break;
        }

        fflush(stdin);
    }

    return 0;
}

char showHelp(){
    char ch;
    int col = 3;
    int i = 0;

    setColor(BLACK, 0, GREEN, 1);
    setConsoleWindowSize(80, 45);
    //clearScreclrscren();
    clrScreen();
   // system("cls");

    moveCursorTo(0, 0);
    printf("===============================================================================\n");
    printf("===============================================================================\n");
    for (i = 0; i< 14; i++){
        printf("==========                                                           ==========\n");
    }
    printf("===============================================================================\n");
    printf("===============================================================================\n");

    moveCursorTo(12, col++);
    printf("程序功能列表如下：");
    moveCursorTo(12, col++);
    printf("1 - 光标操作");
    moveCursorTo(12, col++);
    printf("2 - 屏幕操作");
    moveCursorTo(12, col++);
    printf("3 - 颜色设置");
    moveCursorTo(12, col++);
    printf("4 - 颜色条带");
    moveCursorTo(12, col++);
    printf("5 - 颜色矩阵");
    moveCursorTo(12, col++);
    printf("6 - 跟踪鼠标");
    moveCursorTo(12, col++);
    printf("7 - 播放音乐");
    moveCursorTo(12, col++);
    printf("8 - Game Marrie");
    moveCursorTo(12, col++);
    printf("0 - 退出本程序");

    moveCursorTo(12, ++col);
    printf("请输入选项：");

    ch = getch();
    //clearScreen();
    //system("cls");
    clrScreen();
    moveCursorTo(0, 0);

    return ch;
}
