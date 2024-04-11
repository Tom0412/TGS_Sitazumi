#include "Stage.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define DOWN 0	//�������x�p
#define UP 1	//������x�p
#define RIGHT 2	//�E�����x�p
#define LEFT 3	//�������x�p

Stage::Stage(float _x, float _y, float _width, float _height, int _type)
{
	location.x = _x;
	location.y = _y;
	erea.height = _height;
	erea.width = _width;
	type = _type;
	inv_flg = false;
	for (int i = 0; i < 4; i++)
	{
		end_flg[i] = false;
	}
	draw_rad[UP] = 0;
	draw_rad[LEFT] = 0.75 * M_PI * 2;
	draw_rad[RIGHT] = 0.25 * M_PI * 2;
	draw_rad[DOWN] = 0.5 * M_PI * 2;
	debug_flg = false;
}

Stage::~Stage()
{

}

void Stage::Update()
{
	if (inv_flg == false) {
		draw_location[UP] = { local_location.x + (erea.width / 2),local_location.y + (erea.height / 2) };
		draw_location[DOWN] = { local_location.x + (erea.width / 2),local_location.y - (erea.height / 2) + erea.height };
		draw_location[LEFT] = { local_location.x + (erea.width / 2),local_location.y + (erea.height / 2) };
		draw_location[RIGHT] = { local_location.x - (erea.width / 2) + erea.width,local_location.y + (erea.height / 2) };
	}
}

void Stage::Draw()const
{
	//Edit�ł̕\��
	if (debug_flg == true)
	{
		switch (type)
		{
			//��
		case 0:
			DrawFormatStringF(local_location.x, local_location.y, 0xffffff, "%d", type);
			break;
			//�n��(��)
		case 1:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xffffff, true);
			DrawFormatStringF(local_location.x, local_location.y, 0x000000, "%d", type);
			break;
			//�n��(�D)
		case 2:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xaaaaaa, true);
			DrawFormatStringF(local_location.x, local_location.y, 0x000000, "%d", type);
			break;
			//�F�n��:��
		case 3:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xff0000, true);
			DrawFormatStringF(local_location.x, local_location.y, 0x00ffff, "%d", type);
			break;
			//�F�n��:��
		case 4:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0x0000ff, true);
			DrawFormatStringF(local_location.x, local_location.y, 0xffff00, "%d", type);
			break;
			//�F�n��:��
		case 5:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0x00ff00, true);
			DrawFormatStringF(local_location.x, local_location.y, 0xff00ff, "%d", type);
			break;
			//��
		case 6:
			DrawStringF(local_location.x, local_location.y, "��", 0xff0000);
			break;
			//��
		case 7:
			DrawStringF(local_location.x, local_location.y, "��", 0x0000ff);
			break;
			//��
		case 8:
			DrawStringF(local_location.x, local_location.y, "��", 0x00ff00);
			break;
			//��
		default:
			DrawFormatStringF(local_location.x, local_location.y, 0xff0000, "%d", type);
			break;
		}
	}
	//�Q�[�����C���ł̕\���i�}�b�v�`�b�v�j
	else
	{
		if (inv_flg == false)
		{
			//DrawGraph(local_location.x, local_location.y, stage_img[draw_type], true);
			switch (type)
			{
				//��
			case 0:
				break;
				//�n��(��)
			case 1:
				DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xffffff, true);
				break;
				//�n��(�D)
			case 2:
				DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xaaaaaa, true);
				break;
				//�F�n��:��
			case 3:
				DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xff0000, true);
				break;
				//�F�n��:��
			case 4:
				DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0x0000ff, true);
				break;
				//�F�n��:��
			case 5:
				DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0x00ff00, true);
				break;
				//��
			case 6:
				DrawStringF(local_location.x, local_location.y, "��", 0xff0000);
				break;
				//��
			case 7:
				DrawStringF(local_location.x, local_location.y, "��", 0x0000ff);
				break;
				//��
			case 8:
				DrawStringF(local_location.x, local_location.y, "��", 0x00ff00);
				break;
				//��
			default:
				break;
			}
			DrawGraphF(local_location.x, local_location.y, stage_img[0], true);
			for (int i = 0; i < 4; i++)
			{
				if (end_flg[i] == true)
				{
#ifdef _DEBUG
					DrawFormatStringF(local_location.x, local_location.y, 0x00ffff, "%d", i);
#endif
					DrawRotaGraphF(draw_location[i].x, draw_location[i].y, 1, draw_rad[i], stage_img[1], true);
				}
			}
		}
	}
}
int Stage::GetStageCollisionType()
{
	int col_type = 0;
	if (type <= 4)
	{
		col_type = type;
	}
	else
	{
		col_type = 0;
	}
	return col_type;
}

void Stage::SetDrawType(int up_type, int left_type, int right_type, int down_type)
{
	//��̃u���b�N�̃^�C�v�������ƈႤ����ʒ[�ȊO�Ȃ�
	if (type != up_type && up_type != -1)
	{
		end_flg[UP] = true;
	}
	//���̃u���b�N�̃^�C�v�������ƈႤ����ʒ[�ȊO�Ȃ�
	if (type != left_type && left_type != -1)
	{
		end_flg[LEFT] = true;
	}
	//�E�̃u���b�N�̃^�C�v�������ƈႤ����ʒ[�ȊO�Ȃ�
	if (type != right_type && right_type != -1)
	{
		end_flg[RIGHT] = true;
	}
	//���̃u���b�N�̃^�C�v�������ƈႤ����ʒ[�ȊO�Ȃ�
	if (type != down_type && down_type != -1)
	{
		end_flg[DOWN] = true;
	}

}