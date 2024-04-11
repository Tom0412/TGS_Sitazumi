#pragma once
#include"DxLib.h"

#define IMAGE_NUM 1	//�摜�̐�
#define DIV_IMAGE_NUM 4	//�����摜�̐�
#define SOUND_NUM 1	//���ʉ��̐�

#define DIV_IMAGE_MAX 13	//�����摜�̍ő啪����

//�g�p����摜�̃p�X�ꗗ
static char image_filepath[IMAGE_NUM][256] =
{

};

//�g�p���镪���摜�̃p�X�ꗗ
static char div_image_filepath[DIV_IMAGE_NUM][256] =
{
	"images/player_red.png",
	"images/player_blue.png",
	"images/player_orange.png",
	"images/player_green.png"
};

//�g�p���鉹���̃p�X�ꗗ
static char sound_filepath[SOUND_NUM][256] =
{

};

class ResourceManager
{
private:
	static int image_data[IMAGE_NUM];
	static int div_image_data[DIV_IMAGE_NUM][DIV_IMAGE_MAX];
	static int sound_data[SOUND_NUM];
public:
	static void LoadResource()
	{
		for (int i = 0; i < IMAGE_NUM; i++)
		{
			image_data[i] = LoadSoundMem(image_filepath[i]);
		}

		//���������̐��l���Ⴄ�ꍇfor�ł͑Ώ��o���Ȃ��̂ŁA�P�P��DivGraph���Ăяo��(�����Ȃ�for��)
		for (int i = 0; i < DIV_IMAGE_NUM; i++)
		{
			LoadDivGraph(div_image_filepath[i], 12, 5, 3, 34, 34, div_image_data[i]);
		}

		for (int i = 0; i < SOUND_NUM; i++)
		{
			sound_data[i] = LoadSoundMem(sound_filepath[i]);
		}
	}
	static void DeleteResource()
	{
		for (int i = 0; i < IMAGE_NUM; i++)
		{
			DeleteGraph(image_data[i]);
		}

		for (int i = 0; i < DIV_IMAGE_NUM; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				DeleteGraph(div_image_data[i][j]);
			}
		}

		for (int i = 0; i < SOUND_NUM; i++)
		{
			DeleteSoundMem(sound_data[i]);
		}
	}
	static int GetGraph(int _num)
	{
		return image_data[_num];
	}
	static int GetDivGraph(int _num1, int _num2)
	{
		return div_image_data[_num1][_num2];
	}
	static void StartSound(int _num)
	{
		PlaySoundMem(sound_data[_num], DX_PLAYTYPE_BACK);
	}
	static void StopSound(int _num)
	{
		// �w�肳�ꂽ�T�E���h���~����
		StopSoundMem(sound_data[_num]);
	}
};
