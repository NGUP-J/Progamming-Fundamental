#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
    setcolor(0, 0);
    gotoxy(x, y);
    printf("       ");
}

void erase_shoot(int x, int y)
{
    setcolor(2, 0);
    gotoxy(x, y);
    printf(" ");
}

void shoot(int x, int y)
{
    setcolor(2, 0);
    gotoxy(x, y);
    printf("^");
}

int main()
{
    setcursor(0);
    char ch;
    int x = 38, y = 20;
    char tmp;
    draw_ship(x, y);
    do
    {
        if (_kbhit())
        {

            ch = _getch();
            switch (ch)
            {
            case 'a':
                tmp = 'a';
                break;
            case 'd':
                tmp = 'd';
                break;
            case 's':
                tmp = 's';
                break;
            case ' ':
                tmp = ' ';
                break;
            default:
                break;
            }
            fflush(stdin);
        }
        if (tmp == 'a' && x > 0) // a
        {
            erase_ship(x, y);
            draw_ship(--x, y);
        }
        if (tmp == 'd' && x < 80) // d
        {
            erase_ship(x, y);
            draw_ship(++x, y);
        }
        // shoot
        if (tmp == ' ')
        {
            int i;
            for (i = 0; i < 5; i++)
            {
                if (y > 0)
                {
                    erase_shoot(x, y);
                    shoot(x, --y);
                    Sleep(100);
                }
            }
        }

        Sleep(100);
    } while (ch != 'x');
    return 0;
}
