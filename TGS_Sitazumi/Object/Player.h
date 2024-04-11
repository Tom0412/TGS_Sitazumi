#pragma once
#include "CharaBase.h"
#include "Stage.h"

class Player :
	public CharaBase
{
public:
	enum hitPosition
	{
		top,
		bottom,
		left,
		right
	};
private:
	Location vector; //�x�N�g���A����������L�����x�[�X�Ɉړ�����
	bool stageHitFlg[2][4]; //�㉺���E�ǂ��Ɠ������Ă��邩��z��Ɋi�[ 
	
public:
	Player();
	~Player();
	void Update(GameMain* main)override;
	void Draw()const override;

	void Move();

	bool CheckCollision(Stage* stage);
};

