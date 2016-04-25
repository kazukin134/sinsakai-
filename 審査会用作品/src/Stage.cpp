#include "Stage.h"
#include "Collision.h"
#include "Player.h"
#include "Wall.h"
#include "GameMain.h"
#include "Scene.h"



CStage::CStage():
floor("res/raw/yuka.raw",1024,128),
stage("res/raw/d0159655_162422320.raw",512,512),
door("res/raw/door/door111.raw",256,256),
drawfall("res/raw/22008C.raw",1024,1024)
//standardbgm("res/standard.wav"),
//wallbgm("res/wall.wav")
{
	//x = 0.0;
	y = -240;
	width = 80;
	height = 100;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = 0.0f;
	stageX = 0.0f;
	startX = 600;
	speed = 4;
	fallx = 0;
	seflag = 0;
	
}


CStage::~CStage()
{
}


void CStage::Scroll(bool is_scroll, float &scrollX, float speed)
{

	if (is_scroll == true)
	{
		velocity_x = speed;

		//if (scrollX > 0)
		//{
			scrollX += velocity_x;
		//}

		//if (scrollX <= 0)
		//{
		//	x += velocity_x;
		//	scrollX += x;
		//}
	}


	//if (!(CGameMain::Player->hitflag == 1))
	//{

	//	velocity_x = speed;



	//	if (scrollX > 0)
	//	{
	//		scrollX += velocity_x;
	//	}

	//	if (scrollX <= 0)
	//	{
	//		x += velocity_x;
	//		scrollX += x;
	//	}
	//}
}

void CStage::FallTrap()
{
	fallx = stageX - scrollX + startX;
	fall[0] = fallx ;
	fall[1] = fallx + 700;
	fall[2] = fallx + 3000;
	fall[3] = fallx + 1200;
	fall[4] = fallx + 1500;
	//fall[5] = fallx + 3600;

	for (int i = 0; i < 6; i++)
	{
		if (CGameMain::Player->x > fall[i] + 50)
		{
			CGameMain::Player->fallcollisionflag = 0;
		}
	}
	//if (CGameMain::Player->x > fall[1] + 50 || CGameMain::Player->x > fall[2] + 50 || CGameMain::Player->x > fall[3] + 50 ||
	//	CGameMain::Player->x > fall[4] + 50 || CGameMain::Player->x > fall[5] + 50 || CGameMain::Player->x > fall[6] + 50 ||
	//	CGameMain::Player->x > fall[0] + 50)
	//{

	//}


}


void CStage::Update()
{

	
	//if (CGameMain::Player->over == 0)
	//if (!standardbgm.isPlaying())
	//{
	//	standardbgm.gain(0.05f);
	//	standardbgm.looping(true);
	//	standardbgm.play();

		
//	}
//	if (CGameMain::Wall->disp_x + 300 > -400)
//	{
		
		//standardbgm.looping(false);
		//standardbgm.stop();
		//if (!wallbgm.isPlaying())
		//{
		//	
		//	wallbgm.gain(0.05f);
		//	//wallbgm.looping(true);
		//	wallbgm.play();
		//	
		//}
		
//	}
//	if (CGameMain::Player->over ==1)
//	{
//		wallbgm.stop();
//	}

	
		
	//if (CScene::Scene->clearflag == 1){
		//wallbgm.looping(false);
		
	//}
	//{

	//}
		
	
	if (CGameMain::Player->hitflag == 1||CGameMain::Player->fallflag == 1)
	{
		Scroll(false, scrollX, speed);
	}
	else
	{
		Scroll(true, scrollX, speed);

	}

	FallTrap();
}

void CStage::Draw()
{
	

	//if (CGameMain::Wall->disp_x + 300 > -400)
	//{
	//	standardbgm.stop();
	//	if (!wallbgm.isPlaying())
	//	{

	//		wallbgm.play();
	//		wallbgm.gain(0.05);
	//		wallbgm.looping(true);
	//	}
	//}
	//if (CGameMain::Player->clearflag == 1 && wallbgm.isPlaying())
	//{
	//	wallbgm.stop();
	//}
	stage.DrawTextureBox(-320, y, 800, 500, 0 + scrollX, 0, 560, 373, Color(1, 1, 1,1));
	floor.DrawTextureBox(-320, -240, 800, 100, 0 + scrollX, 0, 1024, 128, Color(1, 1, 1,1));
	door.DrawTextureBox(4000 - scrollX, y + 64, 100, 150, 0, 0, 86, 226, Color(1, 1, 1,1));
	//DrawFillBox(-320, -240 , 800, 62, Color(0.5, 0.5, 1,1));
	
	for (int i = 0; i < 6; i++)
	{
			
		drawfall.DrawTextureBox(fall[i], y, width, height, 113, 400, 778, 431, Color(1, 1, 1,1));
		//drawFillBox(fall[i], y, width, height, Color(0, 1, 1));
	}
}

