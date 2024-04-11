#include "Player.h"
#include "../Utility/PadInput.h"
#include "../Utility/ResourceManager.h"


Player::Player()
{
	location = { 40,200 };
	erea = { 120,60 };
	vector = { 0,0 };

	for (int i = 0; i < 4; i++) {
		stageHitFlg[1][i] = false;
	}
}

Player::~Player() 
{
	
}

void Player::Update(GameMain* main)
{
	if (stageHitFlg[1][bottom] != true) {
		vector.y += 1;
		if (vector.y > 16) {
			vector.y = 16;
		}
	}
	else {
		vector.y = 0;
	}

	Move();

	location.x += vector.x;
	location.y += vector.y;

	for (int i = 0; i < 4; i++){
		stageHitFlg[1][i] = false;
	}


}

void Player::Draw()const
{
	DrawBox(location.x, location.y,location.x + erea.width, location.y + erea.height,0xff0000, FALSE);

	for (int i = 0; i < 4; i++){
		DrawFormatString(20 + i * 20, 0, 0xff0000, "%d", stageHitFlg[0][i]);
		DrawFormatString(20 + i * 20, 40, 0xff0000, "%d", stageHitFlg[1][i]);
	}
	
	DrawFormatString(20 , 80, 0xff0000, "%f", location.x);
	DrawFormatString(20 , 100, 0xff0000, "%f", location.y);
	//DrawBox(location.x - (erea.width / 2), location.y - (erea.height / 2),
	//	location.x - (erea.width / 2) + 10, location.y + (erea.height / 2),
	//	0x00ffff, TRUE);
}

void Player::Move()
{
	//�W�����v
	if (PadInput::OnButton(XINPUT_BUTTON_A) && stageHitFlg[1][bottom]) {
		vector.y = -20;
	}

	//���E�ړ�
	if (PadInput::TipLeftLStick(STICKL_X) > 0.2) {
		vector.x = 0.5;
	}
	else if (PadInput::TipLeftLStick(STICKL_X) < -0.2) {
		vector.x = -0.5;
	}
	else {
		vector.x = 0;
	}
}

bool Player::CheckCollision(Stage* stage)
{
	Location tmpl = location;
	Erea tmpe = erea;

	if (stage->GetStageType() != 0) {

		erea.height = 1;
		erea.width = tmpe.width - 10;

		//�v���C���[�̏㑤
		//location.y -= tmpe.height / 2;
		if (stage->HitBox(this) && !stageHitFlg[1][top]) {
			stageHitFlg[0][top] = true;
			stageHitFlg[1][top] = true;
		}
		else {
			stageHitFlg[0][top] = false;
		}

		//�v���C���[�̉���
		location.y += tmpe.height;
		if (stage->HitBox(this) && !stageHitFlg[1][bottom]) {
			stageHitFlg[0][bottom] = true;
			stageHitFlg[1][bottom] = true;
		}
		else {
			stageHitFlg[0][bottom] = false;
		}

		//���P�[�V�����A������߂�
		location.y = tmpl.y;
		erea.height = tmpe.height;
		//���܂�h�~(�㉺)
		if (stageHitFlg[0][bottom]) {//���̖��܂�h�~
			float t = stage->GetLocation().y - (location.y + erea.height);
			if (t != 0) {
				location.y += t;
			}
		}


		

		//���E�G���A�̐ݒ�
		erea.height = tmpe.height - 10;
		erea.width = 1;

		//�v���C���[�̍���
		//location.x -= tmpe.width / 2;
		if (stage->HitBox(this) && !stageHitFlg[1][left]) {
			stageHitFlg[0][left] = true;
			stageHitFlg[1][left] = true;

		}
		else {
			stageHitFlg[0][left] = false;
		}

		//�v���C���[�̉E��
		location.x += tmpe.width;
		if (stage->HitBox(this) && !stageHitFlg[1][right]) {
			stageHitFlg[0][right] = true;
			stageHitFlg[1][right] = true;
		}
		else {
			stageHitFlg[0][right] = false;
		}


		
		//���ɖ߂�
		location.x = tmpl.x;
		erea.height = tmpe.height;
		erea.width = tmpe.width;

		////���܂�h�~
		//if (stageHitFlg[0][bottom]) {//���̖��܂�h�~
		//	float t = stage->GetLocation().y - (location.y + erea.height);
		//	if (t != 0) {
		//		location.y += t;
		//	}
		//}


	}
	return 0;
}
