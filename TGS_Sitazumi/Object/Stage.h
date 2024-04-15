#pragma once
#include "BoxCollider.h"
#include "ColorData.h"

//ColorData�i�[�p
static int color_data[6]
{
	0,
	WHITE,
	0,
	RED,
	GREEN,
	BLUE
};

//�f�o�b�O�\���p�F���
static int text_color[6]
{
	0xffffff,
	0x000000,
	0x000000,
	0x00ffff,
	0xff00ff,
	0xffff00
};

class Stage :
	public BoxCollider, public ColorData
{
private:
	int type;					//���̎��(0=�� 1=�D 2=�� 3=�� 4=�� 5=�� 6=�� 7=��)
	bool inv_flg;				//�����`�悵�Ȃ������f
	bool debug_flg;				//���̎�ނ�\�����邩
	int swap_flg;				//�F�̌������o����u���b�N���ǂ���
public:
	Stage(float _x, float _y, float _width, float _height, int _type);
	~Stage();
	void Update();
	void Draw()const;

	//��ނ��擾(0=�� 1=�D 2=�� 3=�� 4=�� 5=�� 6=�� 7=��)
	int GetStageCollisionType();
	//��ނ�ݒ�
	void SetStageType(int _type);
	//��ނ��擾
	int GetStageType() { return type; }
	//���̎�ނ�\������
	void SetDebugFlg() { debug_flg = true; }
};

