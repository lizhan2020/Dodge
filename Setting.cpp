#include "Setting.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Windowsize.h"
using namespace std;
Setting::Setting()
{
}


Setting::~Setting()
{
}

void Setting::gotoxy(int x, int y)
{
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Setting::Init()
{
	//カーソルを消す
	char buffer[32];
	sprintf_s(buffer, "mode con cols=%d lines=%d", window_width, window_height);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursoInfo;
	GetConsoleCursorInfo(handle, &CursoInfo);
	CursoInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursoInfo);
	system(buffer);
	srand((unsigned int)time(0));
	//開始画面を描く
	system("cls");
	gotoxy(8,8);
	cout << "Use key 'W','A','S','D'"<<endl<<endl<<"     to move up left down and right" << endl<<endl;
	cout << "  To forbid the stone from the downside " << endl << endl<<endl;
	cout << "             Enter to start" << endl<<endl<<endl;
	cout << "                        ---Li Zhan";
	getchar();

}
void Setting::Draw_Map()
{
	system("cls");
	int i, j;
	for (j = 0; j < window_width; j++)
		cout << "#";
	cout << endl;
	for (i = 0; i < window_height - 2; i++) {
		for (j = 0; j < window_width; j++) {
			if (j == 0 ||  j == window_width - 1)
				cout << "#";
			else
				cout<<" ";
		}
		cout << endl;
	}
	cout << "#";
	for (j = 0; j < window_width-2; j++)
		cout << " ";
	cout << "#";
}

void Setting::Game_Over(int pass,int score)
{
	system("cls");
	gotoxy(12, 8);
	cout << "You lose the game!" << endl << endl;
	cout << "         You went to the " << pass << " round" << endl << endl;
	cout << "            You got " << score << " score" << endl;

}
void Setting::Next_Round(int pass)
{
	system("cls");
	gotoxy(10, 8);
	cout << "You go to the Round" << pass<< endl << endl;
	while (getchar() != '\n');
}