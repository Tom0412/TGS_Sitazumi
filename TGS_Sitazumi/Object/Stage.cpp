#include "Stage.h"

Stage::Stage(float _x, float _y, float _width, float _height, int _type): inv_flg(false), debug_flg(false)
{
	location.x = _x;
	location.y = _y;
	erea.height = _height;
	erea.width = _width;
	type = _type;	
	color = 0;
	//�F�������ł���X�e�[�W�u���b�N�̐ݒ�
	if (type == 1 || type == 3 || type == 4 || type == 5)
	{
		swap_flg = true;
		SetColorData(color_data[type]);
	}
	//�F�������ł��Ȃ��X�e�[�W�u���b�N�̐ݒ�
	else
	{
		swap_flg = false;
	}
}

Stage::~Stage()
{

}

void Stage::Update()
{
	//���݂̐F���ɉ����ău���b�N�̐F��ς���
}

void Stage::Draw()const
{
	if (inv_flg == false)
	{
		switch (type)
		{
			//��
		case 0:
			break;
			//�n��(���A�ԁA�΁A��)
		case 1:
		case 3:
		case 4:
		case 5:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, color, true);
			break;
			//�n��(�D)
		case 2:
			DrawBoxAA(local_location.x, local_location.y, local_location.x + erea.width, local_location.y + erea.height, 0xaaaaaa, true);
			break;
			break;
			//��
		case 6:
			DrawStringF(local_location.x, local_location.y, "��", 0xff0000);
			break;
			//��
		case 7:
			DrawStringF(local_location.x, local_location.y, "��", 0x00ff00);
			break;
			//��
		case 8:
			DrawStringF(local_location.x, local_location.y, "��", 0x0000ff);
			break;
			//��
		default:
			break;
		}
	}
	//Edit�ł̕\��
	if (debug_flg == true && type < 6)
	{
		DrawFormatStringF(local_location.x, local_location.y, text_color[type], "%d", type);
	}
}
int Stage::GetStageCollisionType()
{
	int col_type = 0;
	if (type <= 5)
	{
		col_type = type;
	}
	return col_type;
}

void Stage::SetStageType(int _type) 
{ 
	type = _type; 
	if (type == 1 || type == 3 || type == 4 || type == 5)
	{
		SetColorData(color_data[type]);
	}
}