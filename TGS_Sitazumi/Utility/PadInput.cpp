#include "PadInput.h"

char PadInput::NowKey[BUTTONS];
char PadInput::OldKey[BUTTONS];
XINPUT_STATE PadInput::Input;
Stick PadInput::Rstick;
Stick PadInput::Lstick;

void PadInput::UpdateKey()
{
	// ���̓L�[�擾
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
	for (int i = 0; i < BUTTONS; i++)
	{
		OldKey[i] = NowKey[i];
		NowKey[i] = Input.Buttons[i];
	}

	//���X�e�B�b�N
	Lstick.ThumbX = Input.ThumbLX;
	Lstick.ThumbY = Input.ThumbLY;
}

bool PadInput::OnButton(int button)
{
	bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
	return ret;
}

bool PadInput::OnPressed(int button)
{
	bool ret = (NowKey[button] == 1);
	return ret;
}

bool PadInput::OnRelease(int button)
{
	bool ret = (NowKey[button] == 0 && OldKey[button] == 1);
	return ret;
}

float PadInput::TipLeftLStick(short StickL)
{
	if (StickL == STICKL_X)
	{
		float ratioL_X = Input.ThumbLX / MAXL_X;

		//���X�e�B�b�N�̉������ő�l���P�Ƃ�������
		return ratioL_X;
	}
	else if (StickL == STICKL_Y)
	{
		float ratioL_Y = Input.ThumbLY / MAXL_Y;

		//���X�e�B�b�N�̏c���l�̍ő�l���P�Ƃ�������
		return ratioL_Y;
	}

	return 0;
}