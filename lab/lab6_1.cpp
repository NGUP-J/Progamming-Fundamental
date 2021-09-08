#define _CRT_NO_WARNNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <stdbool.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 12);
	printf("<-0->");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(0, 0);
	printf("     ");
}
void draw_bullet(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("  !  ");
}
void erase_bullet(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(0, 0);
	printf("     ");
}
struct Bullet
{
	bool active = false;
	int x = 0, y = 0;
};
int main()
{
	setcursor(0);
	char ch = ' ';
	int x = 57, y = 25;
	int d = 0;
	Bullet bullets[5];
	draw_ship(x, y);
	do {
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') { d = -1; }
			if (ch == 'd') { d = 1; }
			if (ch == 's') { d = 0; }
			if (ch == ' ')
			{
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].active == false)
					{
						bullets[i].active = true;
						bullets[i].x = x;
						bullets[i].y = y;
						break;
					}
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (bullets[i].active)
			{
				erase_bullet(bullets[i].x, bullets[i].y);
				if (bullets[i].y > 0)
				{
					draw_bullet(bullets[i].x, --bullets[i].y);
				}
				else
				{
					bullets[i].active = false;
				}
			}
		}
		if (d == -1 && x > 0) { erase_ship(x, y); draw_ship(--x, y); }
		if (d == 1 && x < 115) { erase_ship(x, y); draw_ship(++x, y); }
		if (d == 0) { erase_ship(x, y); draw_ship(x, y); }
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
