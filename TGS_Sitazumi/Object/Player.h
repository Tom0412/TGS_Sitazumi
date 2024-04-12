#pragma once
#include "CharaBase.h"
#include "Stage.h"
#include "ColorData.h"

class Player :
	public CharaBase , public ColorData
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
							//0�̍s��1�̃u���b�N�ɓ������Ă��邩
							//1�̍s�̓X�e�[�W�S�̂ɑ΂��Ă̓������Ă��邩

	Location aimLoc; //�Ə��̍��W
	Location aimVec; //�Ə��̕���
	Location lineLoc; //���̏I�[���W
	
public:
	Player();
	~Player();
	void Update(GameMain* main)override;
	void Draw()const override;

	void MoveActor();
	void MoveAim();

	bool CheckCollision(Stage* stage);
};

