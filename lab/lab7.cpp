#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#define MAX_BULLETS 5

char ch;
char tmp;
int i;
bool sh = 0;
int x = 38;
int y = 20;
int numscore = 0;

void gotoxy(int, int);
void setcursor(bool);
void setcolor(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void erase_shoot(int, int);
void shoot(int, int);
void shootcon(int, int, bool);
void star(int, int);
void score(int);
char control(char);
char cursor(int, int);

struct Bullet
{
    bool active = false;
    int x = 0, y = 0;
} bullets[MAX_BULLETS];

int main()
{
    setcursor(0);
    draw_ship(x, y);
    int s1, s2, j;
    srand(time(NULL));
    score(numscore);
    for (j = 0; j < 20; j++)
    {
        s1 = rand() % 60 + 10;
        s2 = rand() % 4 + 2;
        star(s1, s2);
    }
    do
    {
        if (_kbhit())
        {

            ch = _getch();
            control(ch);
            fflush(stdin);
        }
        for (int i = 0; i < 5; i++)
        {
            if (bullets[i].active == true)
            {
                erase_shoot(bullets[i].x, bullets[i].y);
                if (bullets[i].y > 1)
                {
                    if (cursor(bullets[i].x, bullets[i].y - 1) == '*')
                    {
                        Beep(1020, 100);
                        erase_shoot(bullets[i].x, bullets[i].y - 1);
                        numscore++;
                        score(numscore);
                        s1 = rand() % 60 + 10;
                        s2 = rand() % 4 + 2;
                        star(s1, s2);
                        bullets[i].active = false;
                    }
                    else
                    {
                        shoot(bullets[i].x, --bullets[i].y);
                    }
                }
                else
                {
                    bullets[i].active = false;
                }
            }
        }
        if (tmp == 'a' && x > 0) // a
        {
            erase_ship(x, y);
            draw_ship(--x, y);
        }
        if (tmp == 'd' && x < 73) // d
        {
            erase_ship(x, y);
            draw_ship(++x, y);
        }
        Sleep(50);
    } while (ch != 'x');
    return 0;
}

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
    printf("0");
}

void star(int x, int y)
{
    setcolor(2, 0);
    gotoxy(x, y);
    printf("*");
}

char control(char ch)
{
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
    {
        for (int i = 0; i < 5; i++)
        {
            if (bullets[i].active == false)
            {
                bullets[i].active = true;
                bullets[i].x = x + 3;
                bullets[i].y = y - 1;
                break;
            }
        }
    }
    break;
    default:
        break;
    }
    return 0;
}

char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (
        !ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

        return '\0';
    else
        return buf[0];
}

void score(int x)
{
	setcolor(2, 0);
    gotoxy(69,0);
    printf("score = %d", numscore);
}
