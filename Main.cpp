#include <iostream>
#include <windows.h>
#include "Setting.h"
#include "Game.h"


using namespace std;
int main()
{

		int i = 0;//�������h�̃t���C���̐��𐔂���
		int pass = 1;//�����h��
		int pausetime = 256;//�t���C���Ԃ̎���ms
		bool gameoversign = 0;//�Q�[���I�[�o�[�̃T�C��
		int score=0;//�_��
		Setting set;
		Game game;
		//�J�n��ʂ�`��
		set.Init();
		set.Draw_Map();
		score = 0;
		while (true) {
			//�����h�������������m�F
			if (i++ * pausetime > 50000) {
				set.Draw_Map();
				pass++;
				pausetime /=2;
				set.Next_Round(pass);
				game.Game_Turn_Round();
			}
			//�L�[�{�[�h�̓��͂ƃQ�[���̗���
			game.input_keyboard();

			game.Creat_Stone();
			game.Move_Board();
			if (!game.Touch_Stone()) {
				
				gameoversign = 1;
				while(getchar()!='\n');
				set.Game_Over(pass,score);
				getchar();
				break;
			}
			score++;
			Sleep(pausetime / 4);
			game.input_keyboard();
			Sleep(pausetime / 4);
			game.input_keyboard();
			Sleep(pausetime / 4);
			game.input_keyboard();
			Sleep(pausetime / 4);
			game.input_keyboard();
		}

}