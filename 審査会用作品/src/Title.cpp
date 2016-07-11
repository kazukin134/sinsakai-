#include "Title.h"


CTitle::CTitle()
:title01("res/png/2480019i.png",1024,512),
titlelogo("res/png/titlelogo01.png",512,128),
start("res/png/suta-to.png",256,128),
rule("res/png/rule.png",512,128),
end("res/png/end.png",256,128),
titlebgm("res/wav/titleb.wav")
{
	x = 0;
	y = 0;
	width = 100;
	height = 50;
	title = SELECTTITLE::GAME;
	choice_game = 0;
	choice_rule = 50;
	selected_game = 0;
	selected_rule = 0;
	selected_end = 0;
	titlecount = 0;
}

CTitle::~CTitle(){}

void CTitle::Update()
{
	if (IsPushKey(GLFW_KEY_DOWN))
	{
		titlecount++;
		if (titlecount > 2)
		{
			titlecount = 0;
		}
	}
	if (IsPushKey(GLFW_KEY_UP))
	{
		titlecount--;
		if (titlecount < 0)
		{
			titlecount = 2;
		}
	}

	if (titlecount == 0)
	{
		title = SELECTTITLE::GAME;
	}else
	if (titlecount == 1)
	{
		title = SELECTTITLE::RULE;
	}
	else
	if (titlecount == 2)
	{
		title = SELECTTITLE::END;
	}

	switch (title)
	{
	case SELECTTITLE::GAME:
	
			  choice_game = 0;
			  choice_rule = 50;
			  choice_end = 50;

			  if (IsPushKey(GLFW_KEY_ENTER))
			  {
				  selected_game = 1;
			  }

		break;

	case SELECTTITLE::RULE:

			  choice_game = 50;
			  choice_rule = 0;
			  choice_end = 50;

			  if (IsPushKey(GLFW_KEY_ENTER))
			  {
				  selected_rule = 1;
			  }
		break;

	case SELECTTITLE::END:

			  choice_game = 50;
			  choice_rule = 50;
			  choice_end = 0;

			  if (IsPushKey(GLFW_KEY_ENTER))
			  {
				  selected_end = 1;
			  }

		break;
	}

	if (selected_rule == 0 && selected_game == 0)
	if (!(titlebgm.IsPlaying()))
	{
		titlebgm.Looping(true);
		titlebgm.Play();
		titlebgm.Gain(0.5f);
	}
	if (selected_rule == 1 || selected_game == 1)
	{
		titlebgm.Stop();
	}

}

void CTitle::Draw()
{
	title01.DrawTextureBox(-320, -240, 800, 500, 0, 45, 620, 350, Color(1, 1, 1,1));
	titlelogo.DrawTextureBox(-150, 120, 300, 80, 0, 0, 330, 80,  Color(1, 1, 1,1));
	DrawFillBox(x + choice_game, y, 100, 60, Color(1, 1, 0,1));
	start.DrawTextureBox(x + choice_game, y, 100, 60, 0, 0, 256, 64, Color(1, 0.4, 0,1));
	DrawFillBox(x + choice_rule, y - 70, 150, 60, Color(0.5, 0, 0,1));
	rule.DrawTextureBox(x + choice_rule, y - 70, 150, 60, 0, 0, 320, 64, Color(0, 0, 1, 1));
	DrawFillBox(x + choice_end, y - 140, 60, 60, Color(0.5, 0, 0.5,1));
	end.DrawTextureBox(x + choice_end, y - 140, 100, 60, 0, 0, 210, 64, Color(0, 1, 0.5, 1));
}
