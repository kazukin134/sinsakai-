#include "FadeOut.h"

	FadeInOrOut::FadeInOrOut() :
		fade_out("res/png/FadeOut.png", 256, 256)
	{
		alpha = 1.0f;
	}

	FadeInOrOut::~FadeInOrOut()
	{

	}

	void FadeInOrOut::FadeIn(float change_speed)
	{
		if (alphain <= 0)return;

		alphain -= change_speed;

		fade_out.DrawTextureBox(-window_width / 2, -window_height / 2, window_width , window_height , 0, 0, 256, 256, Color(1, 1, 1, alphain));
	}

	void FadeInOrOut::FadeOut(float change_speed)
	{
		if (alphaout <= 1)return;

		alphaout += change_speed;

		fade_out.DrawTextureBox(-window_width / 2, -window_height / 2, window_width, window_height, 0, 0, 256, 256, Color(1, 1, 1, alphaout));
	}
