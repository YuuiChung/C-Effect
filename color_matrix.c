#include <stdio.h>
#include <conio.h>
#include "consoleapi.h"

void showMenu(void);
void regularColor(void);
void randomColor(void);
extern void clrScreen(void);

int fColor[16];
int bColor[16];

void color_matrix(){
	int i;
	char ch;

	for (i = 0; i < 16; i++){
		fColor[i] = i;
		bColor[i] = i;
	}

	showMenu();
	while(1){
		ch = getch();
		if (ch == '1'){
			regularColor();
			getch();
		}
		else if (ch == '2'){
			randomColor();
			getch();
		}
		else{
			clrScreen();//clearScreen();
			break;
		}

        setColor(BLACK, 0, GREEN, 1); //刷新缓冲区，使字迹可见
		clrScreen();//clearScreen();
		showMenu();
	}

}
//---------------------------------------------------------------------------
void showMenu()
{
	moveCursorTo(20, 10);
	printf("1 - Regular Color Array");
	moveCursorTo(20, 11);
	printf("2 - Random Color Array");
	moveCursorTo(20, 12);
	printf("0 - Quit");
}

void regularColor(){
	int x, y;
	int l = 8, t = 5;
	for (y = 0; y < 16; y++){
		moveCursorTo(l - 3, y + t);
		SetColor(fColor[15], bColor[0]);
		printf("%d", y);
		for (x = 0; x < 16; x++){
			moveCursorTo(x * 4 + l, y + t);
			SetColor(fColor[y], bColor[x]);
			printf("AAA");
			if (y == 15){
				moveCursorTo(x * 4 + l, 17 + t);
				SetColor(fColor[15], bColor[0]);
				printf("%d", x);
			}
		}
	}
}

void randomColor(void){
	int x, y;
	int l = 8, t = 5;
	char str[4] = {"135"};
	rand();
	for (y = 0; y < 16; y++){
		for (x = 0; x < 16; x++){
			str[0] = getRandomInt(32, 127);
			str[1] = getRandomInt(32, 127);
			str[2] = getRandomInt(32, 127);
			moveCursorTo(x * 4 + l, y + t);
			SetColor(fColor[getRandomInt(0, 15)], bColor[getRandomInt(0, 15)]);
			printf("%c", str[0]);
			moveCursorTo(x * 4 + l + 1, y + t);
			SetColor(fColor[getRandomInt(0, 15)], bColor[getRandomInt(0, 15)]);
			printf("%c", str[1]);
			moveCursorTo(x * 4 + l + 2, y + t);
			SetColor(fColor[getRandomInt(0, 15)], bColor[getRandomInt(0, 15)]);
			printf("%c", str[2]);
		}
	}
}

