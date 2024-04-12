#pragma once
#define RED 0xff0000
#define GREEN 0x00ff00
#define BLUE 0x0000ff
#define WHITE 0xffffff

class ColorData
{
protected:
	//色情報
	//マクロの4色から入れる
	int color;

public:
	//色の交換
	void ChangeColor(ColorData cd);

	void SetColorData(int c)
	{
		color = c;
	}

	int GetColerData()
	{
		return color;
	}
};

