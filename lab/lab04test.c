#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main()
{
    int x = 30,y = 10;
    char ch;
    gotoxy(x,y);
    printf("<-0-> ");
    while(1)
    {
        ch = getch();
        switch(ch)
        {
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
        }
        system("cls");
        gotoxy(x,y);
        printf("<-0-> ");
    }
}