#include <stdio.h>
#include <conio.h>
#include "consoleapi.h"

#define REN 1
#define SQUARE 31
#define TRAP  ' '
#define BOTTOM_LINE 20
#define UP 'u'

int last_col = 0, last_row = 0;

void showBottomLine(char arr[], int num)
{
    int i = 0;
    setColor(BLACK, 0, YELLOW, 1);
    moveCursorTo(0, BOTTOM_LINE);
    for(i = 0; i < num-1; i++)
    {
        putchar(arr[i]);
    }
}

void showPeople(int col, int row)
{
    setColor(BLACK, 0, RED, 1);
    moveCursorTo(col, row);
    putchar(REN);
}

void moveBottomLine(char arr[], int num)
{
    int i = 0;

    for(i = 0; i < num-1; i++)
    {
        arr[i] = arr[i+1];
    }

    if(getRandomInt(0,10) == 0)
    {
        arr[num-1] = TRAP;
    }
    else
    {
        arr[num-1] = SQUARE;
    }
}

void game_marrie()
{
    const int N = 80;
    char bottom_line[N];
    char choice = 0;
    int i = 0;
    int row = BOTTOM_LINE - 1,  col = 10;

    for(i = 0; i < N; i++)
    {
        bottom_line[i] = SQUARE;
        if(getRandomInt(0,10) == 0)
        {
            bottom_line[i] = TRAP;
        }
    }

    while(1)
    {
        hideCursor();
        showBottomLine(bottom_line, N);
        clearCharAt(last_col, last_row);
        showPeople(col, row);
        if(bottom_line[col] == TRAP && row == BOTTOM_LINE)
        {
            playMusic("music1.txt");
            MessageBox(NULL, "µô¿ÓÀïÀ²£¡", "Game Over", MB_OK);
            return;
        }

        // move People
        Sleep(100);
        choice = getch();
        fflush(stdin);
        last_row = row;
        last_col = col;
        moveBottomLine(bottom_line, N);

        if(row == BOTTOM_LINE - 1)
        {
            if(bottom_line[col] == TRAP)
            {
                if(choice != UP)
                {
                    row = row + 1;
                }
            }
            else if(choice == UP)
            {
                row = row - 1;
            }
        }
        if(row == BOTTOM_LINE - 2)
        {
            if(choice != UP)
            {
                row = row + 1;
            }
        }
    }
}
