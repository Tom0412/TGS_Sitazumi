#pragma once
#include"DxLib.h"

#define BUTTONS 16
#define STICKL_X 1		
#define STICKL_Y 2		
#define MAXL_X 32767.f  //���X�e�B�b�NX���̍ő�l(float�^)
#define MAXL_Y 32767.f  //���X�e�B�b�NY���̍ő�l(float�^)

//�X�e�B�b�N
struct Stick
{
	short ThumbX;	//�����l
	short ThumbY;	//�c���l
};

class PadInput
{
private:
	static char NowKey[BUTTONS]; //����̓��̓L�[
	static char OldKey[BUTTONS]; //�O��̓��̓L�[
	static XINPUT_STATE Input; //�p�b�h
	static Stick Rstick; //�E�X�e�B�b�N
	static Stick Lstick; //���X�e�B�b�N
	
public:
	//�p�b�h���̍X�V
	static void UpdateKey();

	//�{�^���������ꂽ�u��
	static bool OnButton(int button);

	//�{�^���������Ă��
	static bool OnPressed(int button);

	//�{�^���𗣂����u��
	static bool OnRelease(int button);

	//�X�e�B�b�N�̌X������
	static float TipLeftLStick(short StickL);
};