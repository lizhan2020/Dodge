#pragma once
class Setting
{
public:
	//The window size

	Setting();
	~Setting();
	static void Init();//開始画面、カーソルを消す
	static void Draw_Map();//ゲーム画面を描く
	static void gotoxy(int x, int y);//WinAPI、カーソルを指定される位置に移動
	void Game_Over(int pass, int score);// ゲーム終了の情報を表示
	void Next_Round(int pass);//次のランドに移動

};

