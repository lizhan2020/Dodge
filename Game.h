#pragma once
#include "Windowsize.h"
class Game
{
public:

	static const int stockstone = 5;//�΂𐶐��p�̃{�[�h�̑傫��
	static int boat_positionx, boat_positiony;//�D�̈ʒu���
	static int nowpath;//�ʂ��铹1�̈ʒu
	static int nowpath2;//�ʂ��铹2�̈ʒu
	static bool board[window_height - 2][boardwidth];//�Q�[���{�[�h
	static bool stone_stock[stockstone][boardwidth];//�΂̐����{�[�h
	static void Draw_Boat(int boat_positionx,int boat_positiony);//�D��`��
	static void gotoxy(int x, int y);//WinAPI�A�J�[�\�����w�肳���ʒu�Ɉړ�
	static void Move_Board();//���t���C���̉�ʕω�
	static void Creat_Stone();//�΂𐶐�
	void input_keyboard();//���͂̏���
	bool Touch_Stone();//�D���΂ɓ����邩�Ȃ��̔��f
	static void Delete_Boat(int boat_positionx, int boat_positiony);//�D������
	static void Game_Turn_Round();//���̃����h�Ɉړ�
	Game();
	~Game();
private:
	static const int boat_size = 3;//�D�̑傫��


};

