#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

using namespace std;

// светлые цвета
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
// темные цвета
#define COLOR__RED     "\x1b[91m"
#define COLOR__GREEN   "\x1b[92m"
#define COLOR__YELLOW  "\x1b[93m"
#define COLOR__BLUE    "\x1b[94m"
#define COLOR__MAGENTA "\x1b[95m"
#define COLOR__CYAN    "\x1b[96m"
//откат цвета
#define COLOR_RESET   "\x1b[0m"
//отчистка консоли
#define cls system("cls");

//функция для отката курсора в начальное положения, дабы исправить мерцание всего масиива
void clear(int x, int y)//установка курсора на позицию  x y
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
	setlocale(0, "");
menu:
	cout << "\t\t\t\t\t\t\t  Меню (beta)\n\n";
	cout << "\t\t\t\t\t\t\tОдин игрок [1]\n";
	cout << "\t\t\t\t\t\t\tДва игрока [2]\n";
	cout << "\t\t\t\t\t\t\tВыход [ESC]\n";
	int menu_selection = _getch();
	if (menu_selection == 49)
	{
		cls;
		cout << "\t\t\t\t\t\t\tЗабыли добавить :(";
		Sleep(1000);
		cls;
		goto menu;
	}
	else if (menu_selection == 50)
	{
		cls;
	story:
		cout << "\n\n\n\n\n\n\n\n";
		cout << "\t\tДвое друзей, Дэниэл и Элисон, зашли в заброшенный дом и как только они оказались внутри, пол обвалился.\n";
		cout << "\t\t  Они поняли, что оказались в каком-то лабиринте, откуда не было видно выхода.\n";
		cout << "\t\t    Дэниэл и Элисон заметили нечто похожее на человека, которое явно было недружелюбным...\n\n\n\n\n";
		cout << "\t\t\t\t\t         Нажмите ПРОБЕЛ, чтобы продолжить";
		short story_start = _getch();
		if (story_start == 32)
		{
			cls;
			goto start;
		}
		else
		{
			cls;
			goto story;
		}
	}
	else if (menu_selection == 27)
	{
		cout << COLOR_CYAN << "\n\n\t\t\t\t\t\t     |!**Выход из программы**!| " << COLOR_RESET;
		Sleep(1000);
		cls;
		return 0;
	}
	else
	{
		cls;
		goto menu;
	}
start:
	clear(0, 0);
	bool door = false;
	int user_stepI = 1;
	int user_stepJ = 1;

	int user2_stepI = 4;
	int user2_stepJ = 6;

	int mob_stepI = 5;
	int mob_stepJ = 9;

	int map[15][15] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,1,3,3,3,1,1,1,3,0,1},
		{1,1,3,1,0,1,1,1,1,0,6,1,3,0,1},
		{1,1,3,0,0,0,8,7,1,0,0,1,3,0,1},
		{1,1,3,1,1,1,3,1,3,9,0,1,1,0,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		{5,0,3,1,0,1,1,1,0,3,1,1,1,0,1},
		{3,0,3,1,0,0,0,0,0,0,0,3,1,3,1},
		{1,0,0,1,1,1,1,0,3,1,0,0,1,3,1},
		{1,3,0,1,3,3,1,3,0,0,0,0,1,3,1},
		{1,0,0,1,3,3,1,1,4,1,1,1,1,1,1},
		{1,0,3,0,0,0,0,3,0,3,3,3,3,3,1},
		{1,0,0,0,3,3,0,0,0,3,3,3,3,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	while (true)
	{
		cout << COLOR_CYAN << "\t\t\t\t\t\t       Игра на выживание" << COLOR_RESET << "\n\n";
		for (int i = 0; i < 15; i++)
		{
			cout << "\t\t\t\t\t\t";
			for (int j = 0; j < 15; j++)
			{
				if (map[i][j] == 2)
				{
					cout << COLOR_GREEN << (char)4 << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 1)
				{
					cout << COLOR__CYAN << '#' << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 3)
				{
					cout << COLOR__RED << '^' << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 4)
				{
					cout << COLOR_YELLOW << '_' << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 5)
				{
					cout << COLOR__GREEN << '|' << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 6)
				{
					cout << COLOR_YELLOW << (char)23 << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 7)
				{
					cout << COLOR_YELLOW << (char)23 << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 8)
				{
					cout << COLOR__MAGENTA << (char)4 << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 9)
				{
					cout << COLOR_RED << (char)1 << COLOR_RESET << ' ';
				}
				else if (map[i][j] == 0)
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}
		int key = _getch();
		switch (key)
		{
			//W
		case 87:
		case 119:
		case 230:
			if (map[user_stepI - 1][user_stepJ] != 1 && map[user_stepI - 1][user_stepJ] != 3 && map[user_stepI - 1][user_stepJ] != 6 && map[user_stepI - 1][user_stepJ] != 8 && map[user_stepI - 1][user_stepJ] != 9)
			{
				map[user_stepI][user_stepJ] = 0;
				map[--user_stepI][user_stepJ] = 2;
			}
			else if (map[user_stepI - 1][user_stepJ] == 3 || map[user_stepI - 1][user_stepJ] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user_stepI - 1][user_stepJ] == 6)
			{
				map[user_stepI][user_stepJ] = 0;
				map[--user_stepI][user_stepJ] = 2;
				door = true;
				cout << COLOR_CYAN << "\t\t\t\t\t\t\       Вы нажали кнопку " << COLOR_RESET << endl;
				Sleep(500);
				cls;
			}
			if (map[mob_stepI][mob_stepJ + 1] != 1 && map[mob_stepI][mob_stepJ + 1] != 2 && map[mob_stepI][mob_stepJ + 1] != 3 && map[mob_stepI][mob_stepJ + 1] != 4 && map[mob_stepI][mob_stepJ + 1] != 5 && map[mob_stepI][mob_stepJ + 1] != 6 && map[mob_stepI][mob_stepJ + 1] != 7 && map[mob_stepI][mob_stepJ + 1] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[mob_stepI][++mob_stepJ] = 9;
			}
			if (map[mob_stepI][mob_stepJ + 1] == 2 || map[mob_stepI][mob_stepJ + 1] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//стрелочка вверх
		case 72:
			if (map[user2_stepI - 1][user2_stepJ] != 1 && map[user2_stepI - 1][user2_stepJ] != 3 && map[user2_stepI - 1][user2_stepJ] != 6 && map[user2_stepI - 1][user2_stepJ] != 2 && map[user2_stepI - 1][user2_stepJ] != 9)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[--user2_stepI][user2_stepJ] = 8;
			}
			else if (map[user2_stepI - 1][user2_stepJ] == 3 || map[user2_stepI - 1][user2_stepJ] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user2_stepI - 1][user2_stepJ] == 6)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[--user2_stepI][user2_stepJ] = 8;
				door = true;
				cout << COLOR_CYAN << "\t\t\t\t\t\t\       Вы нажали кнопку " << COLOR_RESET << endl;
				Sleep(500);
				cls;
			}
			if (map[mob_stepI][mob_stepJ + 1] != 1 && map[mob_stepI][mob_stepJ + 1] != 2 && map[mob_stepI][mob_stepJ + 1] != 3 && map[mob_stepI][mob_stepJ + 1] != 4 && map[mob_stepI][mob_stepJ + 1] != 5 && map[mob_stepI][mob_stepJ + 1] != 6 && map[mob_stepI][mob_stepJ + 1] != 7 && map[mob_stepI][mob_stepJ + 1] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[mob_stepI][++mob_stepJ] = 9;
			}
			if (map[mob_stepI][mob_stepJ + 1] == 2 || map[mob_stepI][mob_stepJ + 1] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//A
		case 97:
		case 65:
		case 228:
			if (map[user_stepI][user_stepJ - 1] != 1 && map[user_stepI][user_stepJ - 1] != 3 && map[user_stepI][user_stepJ - 1] != 5 && map[user_stepI][user_stepJ - 1] != 8 && map[user_stepI][user_stepJ - 1] != 9)
			{
				map[user_stepI][user_stepJ] = 0;
				map[user_stepI][--user_stepJ] = 2;
			}
			else if (map[user_stepI][user_stepJ - 1] == 3 || map[user_stepI][user_stepJ - 1] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if ((map[user_stepI][user_stepJ - 1] == 5))
			{
				cls;
				cout << COLOR_GREEN << "\t\t\t\t\t\t\t    ВЫ ВЫЖИЛИ! " << COLOR_RESET << endl;
				Sleep(5000);
				cls;
				goto start;
			}
			if (map[mob_stepI + 1][mob_stepJ] != 1 && map[mob_stepI + 1][mob_stepJ] != 2 && map[mob_stepI + 1][mob_stepJ] != 3 && map[mob_stepI + 1][mob_stepJ] != 4 && map[mob_stepI + 1][mob_stepJ] != 5 && map[mob_stepI + 1][mob_stepJ] != 6 && map[mob_stepI + 1][mob_stepJ] != 7 && map[mob_stepI + 1][mob_stepJ] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[++mob_stepI][mob_stepJ] = 9;
			}
			if (map[mob_stepI + 1][mob_stepJ] == 2 || map[mob_stepI + 1][mob_stepJ] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//стрелочка влево
		case 75:
			if (map[user2_stepI][user2_stepJ - 1] != 1 && map[user2_stepI][user2_stepJ - 1] != 3 && map[user2_stepI][user2_stepJ - 1] != 5 && map[user2_stepI][user2_stepJ - 1] != 2 && map[user2_stepI][user2_stepJ - 1] != 9)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[user2_stepI][--user2_stepJ] = 8;
			}
			else if (map[user2_stepI][user2_stepJ - 1] == 3 || map[user2_stepI][user2_stepJ - 1] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if ((map[user2_stepI][user2_stepJ - 1] == 5))
			{
				cls;
				cout << COLOR_GREEN << "\t\t\t\t\t\t\t    ВЫ ВЫЖИЛИ! " << COLOR_RESET << endl;
				Sleep(5000);
				cls;
				goto start;
			}
			if (map[mob_stepI + 1][mob_stepJ] != 1 && map[mob_stepI + 1][mob_stepJ] != 2 && map[mob_stepI + 1][mob_stepJ] != 3 && map[mob_stepI + 1][mob_stepJ] != 4 && map[mob_stepI + 1][mob_stepJ] != 5 && map[mob_stepI + 1][mob_stepJ] != 6 && map[mob_stepI + 1][mob_stepJ] != 7 && map[mob_stepI + 1][mob_stepJ] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[++mob_stepI][mob_stepJ] = 9;
			}
			if (map[mob_stepI][mob_stepJ + 1] == 2 || map[mob_stepI][mob_stepJ + 1] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//S
		case 83:
		case 115:
		case 235:
			if (map[user_stepI + 1][user_stepJ] != 1 && map[user_stepI + 1][user_stepJ] != 3 && map[user_stepI + 1][user_stepJ] != 4 && map[user_stepI + 1][user_stepJ] != 8 && map[user_stepI + 1][user_stepJ] != 9)
			{
				map[user_stepI][user_stepJ] = 0;
				map[++user_stepI][user_stepJ] = 2;
			}
			else if (map[user_stepI + 1][user_stepJ] == 3 || map[user_stepI + 1][user_stepJ] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user_stepI + 1][user_stepJ] == 4 && door == false)
			{
				cout << COLOR_YELLOW << "\t\t\t\t\t\t         Дверь " << COLOR_RED << "ЗАПЕРТА!" << COLOR_RESET << endl;
				Sleep(500);
				cls;
			}
			else if (map[user_stepI + 1][user_stepJ] == 4 && door == true)
			{
				map[user_stepI][user_stepJ] = 0;
				map[++user_stepI][user_stepJ] = 2;
			}
			if (map[mob_stepI][mob_stepJ - 1] != 1 && map[mob_stepI][mob_stepJ - 1] != 3 && map[mob_stepI][mob_stepJ - 1] != 2 && map[mob_stepI][mob_stepJ - 1] != 4 && map[mob_stepI][mob_stepJ - 1] != 5 && map[mob_stepI][mob_stepJ - 1] != 6 && map[mob_stepI][mob_stepJ - 1] != 7 && map[mob_stepI][mob_stepJ - 1] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[mob_stepI][--mob_stepJ] = 9;
			}
			if (map[mob_stepI][mob_stepJ - 1] == 2 || map[mob_stepI][mob_stepJ - 1] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			// стрелочка вниз
		case 80:
			if (map[user2_stepI + 1][user2_stepJ] != 1 && map[user2_stepI + 1][user2_stepJ] != 3 && map[user2_stepI + 1][user2_stepJ] != 4 && map[user2_stepI + 1][user2_stepJ] != 2 && map[user2_stepI + 1][user2_stepJ] != 9)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[++user2_stepI][user2_stepJ] = 8;
			}
			else if (map[user2_stepI + 1][user2_stepJ] == 3 || map[user2_stepI + 1][user2_stepJ] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user2_stepI + 1][user2_stepJ] == 4 && door == false)
			{
				cout << COLOR_YELLOW << "\t\t\t\t\t\t         Дверь " << COLOR_RED << "ЗАПЕРТА!" << COLOR_RESET << endl;
				Sleep(500);
				cls;
			}
			else if (map[user2_stepI + 1][user2_stepJ] == 4 && door == true)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[++user2_stepI][user2_stepJ] = 8;
			}
			if (map[mob_stepI][mob_stepJ - 1] != 1 && map[mob_stepI][mob_stepJ - 1] != 3 && map[mob_stepI][mob_stepJ - 1] != 2 && map[mob_stepI][mob_stepJ - 1] != 4 && map[mob_stepI][mob_stepJ - 1] != 5 && map[mob_stepI][mob_stepJ - 1] != 6 && map[mob_stepI][mob_stepJ - 1] != 7 && map[mob_stepI][mob_stepJ - 1] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[mob_stepI][--mob_stepJ] = 9;
			}
			if (map[mob_stepI][mob_stepJ - 1] == 2 || map[mob_stepI][mob_stepJ - 1] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//D
		case 100:
		case 68:
		case 162:
			if (map[user_stepI][user_stepJ + 1] != 1 && map[user_stepI][user_stepJ + 1] != 3 && map[user_stepI][user_stepJ + 1] != 6 && map[user_stepI][user_stepJ + 1] != 7 && map[user_stepI][user_stepJ + 1] != 8 && map[user_stepI][user_stepJ + 1] != 9)
			{
				map[user_stepI][user_stepJ] = 0;
				map[user_stepI][++user_stepJ] = 2;
			}
			else if (map[user_stepI][user_stepJ + 1] == 3 || map[user2_stepI][user2_stepJ + 1] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user_stepI][user_stepJ + 1] == 6)
			{
				map[user_stepI][user_stepJ] = 0;
				map[user_stepI][++user_stepJ] = 2;
				door = true;
				cout << COLOR_CYAN << "\t\t\t\t\t\t\       Вы нажали кнопку " << COLOR_RESET << endl;
				Sleep(500);
				cls;
			}
			else if (map[user_stepI][user_stepJ + 1] == 7)
			{
				map[user_stepI][user_stepJ] = 0;
				map[user_stepI][++user_stepJ] = 2;
				cout << COLOR__RED << "\t\t\t\t\t\t\      Что-то произошло... " << COLOR_RESET << endl;
				Sleep(900);
				map[2][4] = 3;
				cls;
			}
			if (map[mob_stepI - 1][mob_stepJ] != 1 && map[mob_stepI - 1][mob_stepJ] != 2 && map[mob_stepI - 1][mob_stepJ] != 3 && map[mob_stepI - 1][mob_stepJ] != 4 && map[mob_stepI - 1][mob_stepJ] != 5 && map[mob_stepI - 1][mob_stepJ] != 6 && map[mob_stepI - 1][mob_stepJ] != 7 && map[mob_stepI - 1][mob_stepJ] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[--mob_stepI][mob_stepJ] = 9;
			}
			if (map[mob_stepI - 1][mob_stepJ] == 2 || map[mob_stepI - 1][mob_stepJ] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
			//стрелочка вправо
		case 77:
			if (map[user2_stepI][user2_stepJ + 1] != 1 && map[user2_stepI][user2_stepJ + 1] != 3 && map[user2_stepI][user2_stepJ + 1] != 6 && map[user2_stepI][user2_stepJ + 1] != 7 && map[user2_stepI][user2_stepJ + 1] != 2 && map[user2_stepI][user2_stepJ + 1] != 9)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[user2_stepI][++user2_stepJ] = 8;
			}
			else if (map[user2_stepI][user2_stepJ + 1] == 3 || map[user2_stepI][user2_stepJ + 1] == 9)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			else if (map[user2_stepI][user2_stepJ + 1] == 6)
			{
				map[user2_stepI][user2_stepJ] = 0;
				map[user2_stepI][++user2_stepJ] = 8;
				door = true;
				cout << COLOR_CYAN << "\t\t\t\t\t\t\       Вы нажали кнопку " << COLOR_RESET << endl;
				Sleep(500);
				cls;

			}
			else if (map[user2_stepI][user2_stepJ + 1] == 7)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t    Даниэля раздавило стенами" << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
				cls;
			}
			if (map[mob_stepI - 1][mob_stepJ] != 1 && map[mob_stepI - 1][mob_stepJ] != 2 && map[mob_stepI - 1][mob_stepJ] != 3 && map[mob_stepI - 1][mob_stepJ] != 4 && map[mob_stepI - 1][mob_stepJ] != 5 && map[mob_stepI - 1][mob_stepJ] != 6 && map[mob_stepI - 1][mob_stepJ] != 7 && map[mob_stepI - 1][mob_stepJ] != 8)
			{
				map[mob_stepI][mob_stepJ] = 0;
				map[--mob_stepI][mob_stepJ] = 9;
			}
			if (map[mob_stepI - 1][mob_stepJ] == 2 || map[mob_stepI - 1][mob_stepJ] == 8)
			{
				cls;
				cout << COLOR_RED << "\t\t\t\t\t\t\t\    ПОМЕР " << COLOR_RESET << endl;
				Sleep(2000);
				cls;
				goto start;
			}
			break;
		case 27:
			cls;
			goto menu;
			break;
		}
		clear(0, 0);
	}
	return 0;
}