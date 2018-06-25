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

void clrScreen(void)//�����Ļ
{
    //handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    myCls(handle_out);
    return;
}
void myCls(HANDLE hConsole)
{
    COORD coordScreen={0,0};//�����������귵�ص���Ļ���Ͻ�����
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;//���滺������Ϣ
    DWORD dwConSize;//��ǰ�����������ɵ��ַ���
    bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ
    //PERR(bSuccess,"GetConsoleScreenBufferInfo");
    dwConSize=csbi.dwSize.X * csbi.dwSize.Y;//�����������ַ���Ŀ
    //�ÿո���仺����
    bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
    //PERR(bSuccess,"FillConsoleOutputCharacter");
    bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ
    //PERR(bSuccess,"ConsoleScreenBufferInfo");
    //��仺��������
    bSuccess=FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
    //PERR(bSuccess,"FillConsoleOutputAttribute");
    //��귵����Ļ���Ͻ�����
    bSuccess=SetConsoleCursorPosition(hConsole,coordScreen);
    //PERR(bSuccess,"SetConsoleCursorPosition");
    return;
}



int main(){
    char choice = 0;
    int ret = 0;
    handle_in = GetStdHandle(STD_INPUT_HANDLE);       //��ñ�׼�����豸���
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);     //��ñ�׼����豸���
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
            ret = MessageBox(NULL, "ȷ���˳�������!", "�˳�ȷ�ϴ���", MB_YESNO);
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
    printf("�������б����£�");
    moveCursorTo(12, col++);
    printf("1 - ������");
    moveCursorTo(12, col++);
    printf("2 - ��Ļ����");
    moveCursorTo(12, col++);
    printf("3 - ��ɫ����");
    moveCursorTo(12, col++);
    printf("4 - ��ɫ����");
    moveCursorTo(12, col++);
    printf("5 - ��ɫ����");
    moveCursorTo(12, col++);
    printf("6 - �������");
    moveCursorTo(12, col++);
    printf("7 - ��������");
    moveCursorTo(12, col++);
    printf("8 - Game Marrie");
    moveCursorTo(12, col++);
    printf("0 - �˳�������");

    moveCursorTo(12, ++col);
    printf("������ѡ�");

    ch = getch();
    //clearScreen();
    //system("cls");
    clrScreen();
    moveCursorTo(0, 0);

    return ch;
}
