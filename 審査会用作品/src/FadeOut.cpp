#include "FadeOut.h"

	FadeInOrOut::FadeInOrOut() :
		fade_out("res/png/FadeOut.png", 256, 256)
	{
		alphain = 1.0f;
		alphaout = 0.0f;
		//alpha = 1.0f;
	}

	FadeInOrOut::~FadeInOrOut(){}

	void FadeInOrOut::FadeIn(float change_speed, bool& is_fade_in)
	{

		if (is_fade_in == false)
		{
			//alphain = 1.0f;
			return;
		}

		if (alphain <= 0)
		{
			is_fade_in = false;
			return;
		}
		alphain -= change_speed;

		fade_out.DrawTextureBox(-window_width / 2, -window_height / 2, window_width , window_height , 0, 0, 256, 256, Color(1, 1, 1, alphain));
	}

	void FadeInOrOut::FadeOut(float change_speed, bool& is_fade_out)
	{
		if (is_fade_out == false)
		{
			//alphaout = 0.0f;
			return;
		}

		if (alphaout >= 1)
		{
			is_fade_out = false;
			return;
		}

		alphaout += change_speed;

		fade_out.DrawTextureBox(-window_width / 2, -window_height / 2, window_width, window_height, 0, 0, 256, 256, Color(1, 1, 1, alphaout));
	}
