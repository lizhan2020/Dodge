#pragma once
class Setting
{
public:
	//The window size

	Setting();
	~Setting();
	static void Init();//�J�n��ʁA�J�[�\��������
	static void Draw_Map();//�Q�[����ʂ�`��
	static void gotoxy(int x, int y);//WinAPI�A�J�[�\�����w�肳���ʒu�Ɉړ�
	void Game_Over(int pass, int score);// �Q�[���I���̏���\��
	void Next_Round(int pass);//���̃����h�Ɉړ�

};

