#include "Windowsize.h"
#include<vector>
#include "Game.h"
#include "Setting.h"
#include<conio.h>
#include <Windows.h>
#include<iostream>


using namespace std;

int Game::boat_positionx = boardwidth / 2;
int Game::boat_positiony = 0;
int Game::nowpath = boardwidth / 2;
int Game::nowpath2 = boardwidth / 2;
bool Game::board[window_height - 2][boardwidth] = { 0 };
bool Game::stone_stock[stockstone][boardwidth] = { 0 };


Game::Game()
{


}


Game::~Game()
{
}
void Game::input_keyboard()
{
	char ch;
	//�L�[�{�[�h����̓��͂𔻒f���A�D�̈ʒu��ς��
	if (_kbhit()) {
		ch = _getch();
		Delete_Boat(boat_positionx, boat_positiony);
		switch (ch) {
			

		case 'a':
		case 'A':
			if(boat_positionx>0)
				boat_positionx--;
			Draw_Boat(boat_positionx, boat_positiony);
			break;
		case 'd':
		case 'D':
			if (boat_positionx < boardwidth-1)
				boat_positionx++;
			Draw_Boat(boat_positionx, boat_positiony);
			break;
		case 'w':
		case 'W':
			if(boat_positiony>0)
				boat_positiony--;
			Draw_Boat(boat_positionx, boat_positiony);
			break;
		case 's':
		case 'S':
			if (boat_positiony < window_height-3)
				boat_positiony++;
			Draw_Boat(boat_positionx, boat_positiony);
			break;
			
		}
		

	}
}

void Game::Draw_Boat(int boat_positionx,int boat_positiony)
{
	int i;
	for (i = 0; i < boat_size; i++) {
		gotoxy(boat_positionx+1, boat_positiony+i+1);
		cout << "*";
	}
}
void Game::gotoxy(int x, int y)
{
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Game::Move_Board()
{
	
	int i, j;
	//�{�[�h����Ɉ�s�ňړ����A��ԉ��̍s�𐶐������V���Ȑ΂�ς��
	for (i = 0; i < window_height - 3; i++)
		for (j = 0; j < boardwidth; j++)
			board[i][j] = board[i + 1][j];
	for (j = 0; j < boardwidth; j++)
		board[window_height - 3][j] = stone_stock[0][j];
	//�D������
	Delete_Boat(boat_positionx, boat_positiony);
	//��ʂ̕\���A��ԉ��ɐV�����̃{�[�h���e��`���ɂ���āA��ʂ���Ɉړ�
	gotoxy(0, window_height - 1);
	cout << "#";
	for (j = 0; j < boardwidth; j++)
		if (stone_stock[0][j])
			cout << "@";
		else
			cout << " ";
	cout << "#" << endl;
	cout << "#";
	for (j = 0; j < window_width-2; j++)
		cout << " ";
	cout << "#";
	Draw_Boat(boat_positionx, boat_positiony);

}
void Game::Creat_Stone()
{
	int i, j;
	//����̃p�[�X��������āA���񃉃��_���ɍ����E�܂��͕s���ɂ���
	nowpath += rand() % 3 - 1;
	nowpath2 += rand() % 3 - 1;
	if (nowpath < 1)
		nowpath += 2;
	else if (nowpath > boardwidth - 1)
		nowpath -= 2;
	if (nowpath2 < 1)
		nowpath2 += 2;
	else if (nowpath2 > boardwidth - 1)
		nowpath2 -= 2;
	for (i = 0; i < stockstone-1; i++) 
		for (j = 0; j < boardwidth; j++)
			stone_stock[i][j] = stone_stock[i + 1][j];
	for (j = 0; j < boardwidth; j++)
		stone_stock[stockstone - 1][j] = rand() % 2;
	i = nowpath + rand() % 2 - 2;
//�����̉���5��4�����p�[�X�̑���
	for (j = i; j < i + 5; j++) 
		if (j >= 0 && j <= boardwidth)
			stone_stock[stockstone - 1][j] = 0;
	i = nowpath2 + rand() % 2 - 2;
	for (j = i; j < i + 4; j++)
		if (j >= 0 && j <= boardwidth)
			stone_stock[stockstone - 1][j] = 0;
}
bool Game::Touch_Stone()
{
	//�{�[�g�̈ꕔ��΂ɓ���������@���^�[���@0
	int i;
	for (i = 0; i < boat_size; i++) {
		if (board[boat_positiony+i][boat_positionx])
			return 0;
	}
	return 1;
}

void Game::Delete_Boat(int boat_positionx, int boat_positiony)
{
	//�ړ��̑O�̃{�[�g�S������
	int i;
	for (i = 0; i < boat_size; i++) {
		gotoxy(boat_positionx + 1, boat_positiony + i + 1);
		cout << " ";
	}
}
void Game::Game_Turn_Round()
{
	int i, j;
	//�����h���`�F���W���邽�߁A�{�[�g�̈ʒu�A�p�[�X�̈ʒu�ƃ{�[�h���ŏI�̏�Ԃɖ߂�
	boat_positionx = boardwidth / 2;
	boat_positiony = 0;
	nowpath = boardwidth / 2;
	nowpath2 = boardwidth / 2;
	for (j = 0; j < boardwidth; j++) {
		for (i = 0; i < window_height - 2; i++)
			board[i][j] = 0;
		for(i=0;i< stockstone;i++)
			stone_stock[i][j] =  0 ;
	}
}