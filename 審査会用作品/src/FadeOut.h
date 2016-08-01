#pragma once
#include "lib/Texture.h"
#include "lib/WindowSize.h"


	class FadeInOrOut
	{
		Texture fade_out;

		WindowSize windowsize;

		int window_width = windowsize.GetWindowWidth();
		int window_height = windowsize.GetWindowHeight();
		float alphain;
		float alphaout;
	public:
		FadeInOrOut();
		~FadeInOrOut();


		void FadeIn(float change_speed,bool& is_fade_in);
		void FadeOut(float change_speed, bool& is_fade_out);


	};
