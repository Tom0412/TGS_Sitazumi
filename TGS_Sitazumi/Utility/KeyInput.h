#pragma once
#include"DxLib.h"

#define KEY_MAX 256
#define MOUSE_MAX 256

//�}�E�X�J�[�\��
struct CURSOR
{
	int x;	//�����l
	int y;	//�c���l
};

//�L�[����
class KeyInput
{
private:
	static int NowKey[KEY_MAX];		//����̓��̓L�[
	static int OldKey[KEY_MAX];		//�O��̓��̓L�[
	static int NowMouse[MOUSE_MAX]; //����̓��̓}�E�X�{�^��
	static int OldMouse[MOUSE_MAX]; //�O��̓��̓}�E�X�{�^��
	static CURSOR Cursor; //�J�[�\��
public:
	//�p�b�h���̍X�V
	static void UpdateKey();

	//�{�^�����������u��
	static bool OnKey(int key);

	//�{�^�����������u��
	static bool OnPresed(int key);

	//�{�^�����������u��
	static bool OnRelease(int key);

	//�}�E�X�{�^���������ꂽ�u��
	static bool OnMouse(int mouse);

	//�}�E�X�{�^���������Ă��
	static bool OnPressedMouse(int mouse);

	//�}�E�X�{�^���𗣂����u��
	static bool OnReleaseMouse(int mouse);

	//�}�E�X�J�[�\���̈ʒu��Ԃ�
	static CURSOR GetMouseCursor();
};

