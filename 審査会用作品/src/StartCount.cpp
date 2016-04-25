#include "StartCount.h"


StartCount::StartCount():
number("res/raw/sumi-11.raw",600,359),
startlogo("res/raw/Start.raw",153,80)
{
	count = 0;
	time = 0;
}

void StartCount::Update()
{
	count++;
	time = count / 60;
}

void StartCount::Draw()
{
	if (time == 2)
	{
		number.DrawTextureBox(-100, -100, 200, 200, 0, 0, 100, 180, Color(0, 0, 1, 1));
	}else
		if (time == 1)
		{
			number.DrawTextureBox(-100, -100, 200, 200, 120, 0, 100, 180, Color(1, 0, 0, 1));
		}else
			if (time == 0)
			{
				number.DrawTextureBox(-100, -100, 200, 200, 240, 0, 100, 180, Color(0, 1, 0, 1));
			}
			else
				if (time == 3)
				{
					startlogo.DrawTextureBox(-100, -100, 200, 200, 0, 0, 153, 80, Color(1, 0, 0, 1));
				}
}