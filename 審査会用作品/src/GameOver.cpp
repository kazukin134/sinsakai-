#include "GameOver.h"


CGameOver::CGameOver()
	:retry_or_title("res/raw/gameover.raw", 512, 256),
drawover("res/raw/GameOvarBackground.raw",1024,1024),
gameoverlogo("res/raw/gameoverlogo.raw",512,512),
gameoverbgm("res/wav/gameover.wav")
{
	x = 0;
	y = -50;
	width = 100;
	height = 50;
	selected = 0;
	choice = 0;
	choice_game = 0;
	choice_title = 50;
	selected_title = 0;

}

CGameOver::~CGameOver()
{

}



void CGameOver::Choice()
{
	switch (choice)
	{

	case 0:
	{
			  choice_game = 0;
			  choice_title = 50;
			  if (IsPushKey(GLFW_KEY_DOWN) || IsPushKey(GLFW_KEY_UP))
		{

			choice = 1;
		}
			  if (IsPushKey(GLFW_KEY_ENTER))
			  {
				  gameoverbgm.Looping(false);
				  gameoverbgm.Stop();

				  CGameMain::Player->over = 0;
			  }
	}
		break;

	case 1:
	{
			  choice_title = 0;
			  choice_game = 50;
			  if (IsPushKey(GLFW_KEY_UP) || IsPushKey(GLFW_KEY_DOWN))
		{

			choice = 0;
		}
		
			  if (IsPushKey(GLFW_KEY_ENTER))
			  {
				  gameoverbgm.Looping(false);
				  gameoverbgm.Stop();
				  selected_title = 1;
			  }
	}
		break;
	}
	  
}

void CGameOver::Update()
{
	if (!(gameoverbgm.IsPlaying()))
	{
		gameoverbgm.Looping(true);
		gameoverbgm.Play();
		gameoverbgm.Gain(0.05f);

	}

	Choice();
}

void CGameOver::Draw()
{
	drawover.DrawTextureBox(-320, -240, 800, 500, 0, 0, 1024, 1024, Color(1, 1, 1, 1));
	gameoverlogo.DrawTextureBox(-200, 50, 400, 150, 3, 193, 501, 145, Color(1, 1, 1, 1));
	DrawFillBox(x + choice_game, y, width, height, Color(0, 1, 1,1));
	retry_or_title.DrawTextureBox(x + choice_game, y, width, height, 0, 0, 256, 64, Color(1, 0, 1, 1));
	DrawFillBox(x + choice_title, y - 70, width, height, Color(1, 0, 1,1));
	retry_or_title.DrawTextureBox(x + choice_title, y - 70, width, height, 0, 65, 256, 64, Color(0, 1, 1, 1));
}