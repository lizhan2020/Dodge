#pragma once
#include "Windowsize.h"
class Game
{
public:

	static const int stockstone = 5;//石を生成用のボードの大きさ
	static int boat_positionx, boat_positiony;//船の位置情報
	static int nowpath;//通じる道1の位置
	static int nowpath2;//通じる道2の位置
	static bool board[window_height - 2][boardwidth];//ゲームボード
	static bool stone_stock[stockstone][boardwidth];//石の生成ボード
	static void Draw_Boat(int boat_positionx,int boat_positiony);//船を描く
	static void gotoxy(int x, int y);//WinAPI、カーソルを指定される位置に移動
	static void Move_Board();//毎フレイムの画面変化
	static void Creat_Stone();//石を生成
	void input_keyboard();//入力の処理
	bool Touch_Stone();//船が石に当たるかないの判断
	static void Delete_Boat(int boat_positionx, int boat_positiony);//船を消す
	static void Game_Turn_Round();//次のランドに移動
	Game();
	~Game();
private:
	static const int boat_size = 3;//船の大きさ


};

