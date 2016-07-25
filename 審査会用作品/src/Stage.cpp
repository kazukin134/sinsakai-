#include "Stage.h"
#include "Collision.h"
#include "Player.h"
#include "Wall.h"
#include "GameMain.h"
#include "Scene.h"


CStage::CStage():
floor("res/png/yuka.png",1024,128),
stage("res/png/d0159655_162422320.png",512,512),
door("res/png/door/door111.png",256,256),
drawfall("res/png/22008C.png",1024,1024),
standardbgm("res/wav/standard.wav"),
wallbgm("res/wav/wall.wav")
{
	y = -240;
	width = 80;
	height = 100;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = 0.0f;
	stage_x = 0.0f;
	startX = 600;
	speed = 3.2;
	fallx = 0;
	seflag = 0;
	goalposition = 3300;
	fallx = stage_x - scrollX + startX;
}

CStage::~CStage()
{
}

void CStage::Scroll(bool is_scroll, float &scrollX, float speed)
{

	if (is_scroll == true)
	{
		velocity_x = speed;

			scrollX += velocity_x;
	}

}

void CStage::FallTrap()
{
	fallx = stage_x - scrollX + startX;
	fall[0] = fallx ;
	fall[1] = fallx + 700;
	fall[2] = fallx + 3000;
	fall[3] = fallx + 1200;
	fall[4] = fallx + 1500;

	for (int i = 0; i < fall_number; i++)
	{
		if (CGameMain::Player->x > fall[i] + 50)
		{
			CGameMain::Player->fallcollisionflag = 0;
		}
	}
}


void CStage::Update()
{
	if (CGameMain::Player->is_over == false)
	{
		if (!standardbgm.IsPlaying())
		{
			standardbgm.Gain(0.5f);
			standardbgm.Looping(true);
			standardbgm.Play();
		}

		if (CGameMain::Player->hitstate == CPlayer::HITSTATE::HIT || CGameMain::Player->is_fall == true)
		{
			Scroll(false, scrollX, speed);
		}
		else
		{
			Scroll(true, scrollX, speed);
		}
		FallTrap();
	}else
		if (CGameMain::Player->is_over == true)
		{
			standardbgm.Looping(false);
			standardbgm.Stop();
		}

}

void CStage::Draw()
{
	if (CGameMain::Wall->disp_x + 300 > -400)
	{
		standardbgm.Stop();
		if (wallbgm.IsPlaying() == false)
		{
			wallbgm.Play();
			wallbgm.Gain(0.05);
			wallbgm.Looping(true);
		}
	}
	if (CGameMain::Player->is_clear == true && wallbgm.IsPlaying())
	{
		wallbgm.Stop();
	}else
		if (CGameMain::Player->is_over == true && wallbgm.IsPlaying())
		{
			wallbgm.Stop();
		}
	stage.DrawTextureBox(-320, y, 800, 500, 0 + scrollX, 0, 560, 373, Color(1, 1, 1,1));
	floor.DrawTextureBox(-320, -240, 800, 100, 0 + scrollX, 0, 1024, 128, Color(1, 1, 1,1));
	door.DrawTextureBox(goalposition - scrollX, y + 64, 100, 150, 0, 0, 86, 226, Color(1, 1, 1, 1));
	for (int i = 0; i < fall_number; i++)
	{			
		drawfall.DrawTextureBox(fall[i], y, width, height, 113, 400, 778, 431, Color(1, 1, 1,1));
	}
}

