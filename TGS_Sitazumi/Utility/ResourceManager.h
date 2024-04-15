#pragma once
#include"DxLib.h"

#define IMAGE_NUM 1	//�摜�̐�
#define DIV_IMAGE_NUM 1	//�����摜�̐�
#define SOUND_NUM 1	//���ʉ��̐�

#define DIV_IMAGE_MAX 13	//�����摜�̍ő啪����

//�g�p����摜�̃p�X�ꗗ
static char image_filepath[IMAGE_NUM][256] =
{
	"Resource/Image/Sigma.png"
};

//�g�p���镪���摜�̃p�X�ꗗ
static char div_image_filepath[DIV_IMAGE_NUM][256] =
{

};

//�g�p���鉹���̃p�X�ꗗ
static char sound_filepath[SOUND_NUM][256] =
{

};

class ResourceManager
{
private:
	static int image_data[IMAGE_NUM];							//�摜�i�[�p
	static int div_image_data[DIV_IMAGE_NUM][DIV_IMAGE_MAX];	//�����摜�i�[�p
	static int sound_data[SOUND_NUM];							//�����i�[�p
public:

	//�e�f�[�^�Ǎ��imain�ň��Ăԁj
	static void LoadResource();	

	//�e�f�[�^�폜�imain�ň��Ăԁj
	static void DeleteResource();

	//�摜�Ăяo��
	static int GetGraph(int _num);

	//�����摜�Ăяo��
	static int GetDivGraph(int _num1, int _num2);	

	//�����Đ��J�n
	static void StartSound(int _num);				

	//�����Đ��I��
	static void StopSound(int _num);				
};
