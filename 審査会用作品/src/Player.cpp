#include "Player.h"
#include "Collision.h"
#include "GameMain.h"
#include "Stage.h"
#include "Enemy.h"
#include "Wall.h"


CPlayer::CPlayer()
	:playerdraw("res/raw/dassyu.raw", 512, 512),
	ran("res/raw/gurugu.raw", 512, 512),
	jamp("res/raw/hasiru.raw", 512, 512)
	//jampse("res/jump_2.wav")
{
	palyer_alpha = 1.0f;
	x = 0.0;
	y = -240 + margin;
	width = 50;
	height = 110;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = x;
	stageX = this->x;
	startX = 0;
	speed = 3;
	fallflag = 0;
	fall = 0;
	hitflag = 0;
	fallcollisionflag = 0;
	hitcount = 0;
	movecount = 0;
	wallhitflag = 0;
	hittime = 60;
	movedistance = 0;
	//hitlost = 0;
	over = 0;
	clearflag = 0;
	invincibilitytime = 60;
	angle = 0.0;
	state = STATE::NORMAL;
	force = 0;
}


CPlayer::~CPlayer()
{

}


void CPlayer::Move()
{
	//CGameMain::Enemy->angle_y = CGameMain::Enemy->angle;
	//CGameMain::Enemy->wave = std::sin(CGameMain::Enemy->angle_y) * 25.0;
	//CGameMain::Enemy->angle_y += 0.04;



	if ((hitflag == 0) || (hitflag == 2))
	{
		CGameMain::Stage->Scroll(true,x,speed);

		movecount++;
		//angle -= 0.4f;

		//velocity_x = speed;

		//if (scrollX > 0)
		//{
		//	scrollX += velocity_x;
		//}

		//if (scrollX <= 0)
		//{
		//	x += velocity_x;
		//	scrollX += x;
		//}

		movedistance = movecount * -speed;
	}
	else
		if (hitflag == 1)
	{
		CGameMain::Stage->Scroll(false, x, speed);
	}

	//x = scrollX;

	if (x >= 3000)
	{
		clearflag = 1;
	}

	disp_x = x + movedistance;


	if (fallflag == 1)
	{
		fall = -64;
	}
	if (y < -240 + margin + fall)
	{

		y -= velocity_y;
		if (fallflag == 1)
		{
			CGameMain::Stage->Scroll(false, x, speed);
			//hitflag == 1;
			palyer_alpha -= 0.05f;
		}
	}

	if (palyer_alpha <= 0)
	{
		over = 1;
	}

	if ((hitflag == 0) || (hitflag == 2))
	{

		if (IsPushKey(GLFW_KEY_SPACE) && state != STATE::JUNP)
		{

 			force = 26;
			state = STATE::JUNP;
			//jampse.gain(0.5f);
			//jampse.play();
		}

	}
	velocity_y = -3.5f;


	if (state == STATE::JUNP)
	{
		force--;
		y += force;
		if (!(fallflag == 1))
		{
			if (y <= -240 + margin + 5)
			{
				force = 0;
				velocity_y = 0;
				y -= velocity_y;
				state = STATE::NORMAL;
			}
		}
		else
		{
			force = 0;

			velocity_y = velocity_y / 10;
		}


	}

	y += velocity_y;

	//if (movecount == 1)
	//{
	//	state = STATE::NORMAL;
	//}

}


void CPlayer::Collision()
{


	fallcollisionflag = 0;
	for (int i = 0; i < 6; i++)
	{
		if (Collision::IsHit(x + movedistance, y, width, height,
			CGameMain::Stage->fall[i] + CGameMain::Stage->width, CGameMain::Stage->y,
			CGameMain::Stage->width, CGameMain::Stage->height))
		{
			fallcollisionflag = 1;
		}
		if (Collision::IsHit(x + movedistance, y, width - width, height,
			CGameMain::Stage->fall[i], CGameMain::Stage->y, CGameMain::Stage->width,
			CGameMain::Stage->height) & (fallcollisionflag == 0))
		{
			fallflag = 1;
			state = STATE::JUNP;
		}
	}


	for (int i = 0; i < 15; i++)
	{
		if (hitcount == 0)
			if (Collision::IsHit(x + movedistance, y, width, height,
				CGameMain::Enemy->enemy[i].x(), CGameMain::Enemy->enemy[i].y(), CGameMain::Enemy->width, CGameMain::Enemy->height))
			{
				hitflag = 1;
				//hitlost = 1;
			}
	}


	if (Collision::IsHit(x + movedistance, y, width, height,
		CGameMain::Wall->disp_x, CGameMain::Wall->y, CGameMain::Wall->width / 2, CGameMain::Wall->height))
	{
		over = 1;
	}


	if (hitflag == 1)
	{
		hitfear = 1;
		hitcount++;
		if (hitcount >= hittime)
		{
			hitcount = 0;
			hitflag = 2;
			wallhitflag = 0;
			hitfear = 2;
		}

	}

	if (hitflag == 2)
	{
		hitcount++;
		if (hitcount >= invincibilitytime)
		{
			hitcount = 0;
			hitflag = 0;
		}
	}
	//if (y <= -240)
	//{
	//	over = 1;
	//}
}



void CPlayer::Update()
{
	Move();
	Collision();

}

void CPlayer::Draw()
{

	if (state == STATE::NORMAL)
	{
		if (hitcount == 0 || (hitcount / 2) % 2)
		{
			playerdraw.DrawTextureBox(disp_x, y, 50, 80, 133, 19, 344, 307, Color(1, 1, 1, palyer_alpha));
			ran.DrawTextureBox(disp_x, y - 25, 50, 50, 131, 99, 226, 257, Color(1, 1, 1, palyer_alpha)/*, angle, Vec2f(1, 1), Vec2f(25, 25)*/);
		}
	}
	if (state == STATE::JUNP)
	{
         		jamp.DrawTextureBox(disp_x, y, 50, 110, 126, 13, 356, 408, Color(1, 1, 1, palyer_alpha));
	}

}

