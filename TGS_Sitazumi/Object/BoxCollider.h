#pragma once
#include "dxlib.h"
#include"../Utility/common.h"

//���S���W
struct Location
{
	float x;	//������W(x)
	float y;	//������W(y)
};

//�͈�
struct Erea
{
	float height;	//����
	float width;	//��
};

class BoxCollider
{
protected:
	Location location;			//���S���W
	Location local_location;	//��ʏ�ł̍��W
	Erea erea;					//�͈�
public:

	//�����蔻�� (0,0 = �������Ă��Ȃ� ����ȊO = ����̒��S���W)
	bool HitBox(BoxCollider* bCollider);

	//������W�̎擾
	Location GetLocation()const;

	//���S���W�̎擾
	Location GetCenterLocation()const;

	//���[�J�����W�̎擾
	Location GetLocalLocation()const;

	//���a�̎擾
	Erea GetErea()const;

	//�I�u�W�F�N�g�̃��[���h���W���X�N���[�����W�ɕϊ�����
	void SetScreenPosition(Location _world_to_screen);
};