#include <iostream>
#include <windows.h>
#include "Setting.h"
#include "Game.h"


using namespace std;
int main()
{

		int i = 0;//毎ランドのフレイムの数を数える
		int pass = 1;//ランド数
		int pausetime = 256;//フレイム間の時間ms
		bool gameoversign = 0;//ゲームオーバーのサイン
		int score=0;//点数
		Setting set;
		Game game;
		//開始画面を描く
		set.Init();
		set.Draw_Map();
		score = 0;
		while (true) {
			//ランドが完成したか確認
			if (i++ * pausetime > 50000) {
				set.Draw_Map();
				pass++;
				pausetime /=2;
				set.Next_Round(pass);
				game.Game_Turn_Round();
			}
			//キーボードの入力とゲームの流れ
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