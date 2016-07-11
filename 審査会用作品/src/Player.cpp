#include "Player.h"
#include "Collision.h"
#include "GameMain.h"
#include "Stage.h"
#include "Enemy.h"
#include "Wall.h"


CPlayer::CPlayer()
	:playerdraw("res/png/dassyu.png", 512, 512),
	ran("res/png/gurugu.png", 512, 512),
	jamp("res/png/hasiru.png", 512, 512),
	jampse("res/wav/jump_2.wav")
{
	palyer_alpha = 1.0f;
	x = 0.0;
	y = -240 + margin;
	width = 50;
	height = 110;
	velocity_y = 0;
	speed = 3.2;
	is_fall = false;
	fall = 0;
	fallcollisionflag = false;
	hitcount = 0;
	movecount = 0;
	wallenemyhitflag = false;
	hittime = 60;
	movedistance = 0;
	is_over = false;
	is_clear = false;
	invincibilitytime = 60;
	angle = 0.0;
	jumpstate = JUMPSTATE::NORMAL;
	hitstate = HITSTATE::NORMAL;
	force = 0;
	is_hit_enemy = false;
}

CPlayer::~CPlayer(){}

void CPlayer::Move()
{
	if (hitstate == HITSTATE::NORMAL || hitstate == HITSTATE::INVINCIBLE)
	{
		CGameMain::Stage->Scroll(true, x, speed);

		movecount++;
		movedistance = movecount * -speed;
	}
	else
		if (hitstate == HITSTATE::HIT)
		{
			CGameMain::Stage->Scroll(false, x, speed);
		}

	if (x >= CGameMain::Stage->getgoalposition())
	{
		is_clear = true;
	}

	disp_x = x + movedistance;

	if (is_fall == true)
	{
		fall = -64;
	}

	if (y < -240 + margin + fall)
	{
		y -= velocity_y;
		if (is_fall == true)
		{
			CGameMain::Stage->Scroll(false, x, speed);
			palyer_alpha -= 0.05f;
		}
	}

	if (palyer_alpha <= 0)
	{
		is_over = true;
	}

}

void CPlayer::Jump()
{
	if (hitstate == HITSTATE::NORMAL || hitstate == HITSTATE::INVINCIBLE)
	{
		if (IsPushKey(GLFW_KEY_SPACE) && jumpstate != JUMPSTATE::JUNP)
		{
			force = 20;
			jumpstate = JUMPSTATE::JUNP;
			jampse.Gain(0.5f);
			jampse.Play();
		}
	}
	velocity_y = -4.0f;

	if (jumpstate == JUMPSTATE::JUNP)
	{
		force -= 0.5f;
		y += force;
		if (!is_fall)
		{
			if (y <= -240 + margin + 5)
			{
				force = 0;
				velocity_y = 0;
				y -= velocity_y;
				jumpstate = JUMPSTATE::NORMAL;
			}
		}
		else
		{
			force = 0;
			velocity_y = velocity_y / 10;
		}
	}
	y += velocity_y;
}

void CPlayer::Collision()
{
	fallcollisionflag = false;
	for (int i = 0; i < 6; i++)
	{
		if (Collision::IsHit(x + movedistance, y, width, height,
			CGameMain::Stage->fall[i] + CGameMain::Stage->width, CGameMain::Stage->y,
			CGameMain::Stage->width, CGameMain::Stage->height))
		{
			fallcollisionflag = true;
		}
		if (Collision::IsHit(x + movedistance, y, width - width, height,
			CGameMain::Stage->fall[i], CGameMain::Stage->y, CGameMain::Stage->width,
			CGameMain::Stage->height) & (fallcollisionflag == false))
		{
			is_fall = true;
			jumpstate = JUMPSTATE::JUNP;
		}
	}

	for (int i = 0; i < CGameMain::Enemy->enmeynumber; i++)
	{
		if (Collision::IsHit(x + movedistance, y, width, height,
			CGameMain::Enemy->enemy[i].x(), CGameMain::Enemy->enemy[i].y(),
			CGameMain::Enemy->width, CGameMain::Enemy->height))
		{
			is_hit_enemy = true;
		}
	}

	if (Collision::IsHit(x + movedistance, y, width, height,
		CGameMain::Wall->disp_x, CGameMain::Wall->y,
		CGameMain::Wall->width / 2, CGameMain::Wall->height))
	{
		is_over = true;
	}

	if (is_hit_enemy && hitstate == HITSTATE::NORMAL)
	{
		hitstate = HITSTATE::HIT;
	}

}

void CPlayer::HitStop()
{
	if (hitstate == HITSTATE::HIT)
	{
		hitfear = true;
		hitcount++;
		if (hitcount >= hittime)
		{
			hitcount = 0;
			hitstate = HITSTATE::INVINCIBLE;
			wallenemyhitflag = false;
			hitfear = false;
		}
	}
}

void CPlayer::Invincible()
{
	if (hitstate == HITSTATE::INVINCIBLE)
	{
		hitcount++;
		if (hitcount >= invincibilitytime)
		{
			hitcount = 0;
			hitstate = HITSTATE::NORMAL;
			is_hit_enemy = false;
		}
	}
}

void CPlayer::Update()
{
	Move();
	Jump();
	Collision();
	HitStop();
	Invincible();
}

void CPlayer::Draw()
{
	angle -= 0.5f;
	if (jumpstate == JUMPSTATE::NORMAL)
	{
		if (hitcount == 0 || (hitcount / 2) % 2)
		{
			playerdraw.DrawTextureBox(disp_x - 20, y, 50, 80, 133, 19, 344, 307, Color(1, 1, 1, palyer_alpha));
			ran.DrawTextureBox(disp_x, y, 50, 50, 131, 99, 226, 257, Color(1, 1, 1, palyer_alpha), angle, Eigen::Vector2f(1, 1), Eigen::Vector2f(25, 25));
		}
	}
	if (jumpstate == JUMPSTATE::JUNP)
	{
		jamp.DrawTextureBox(disp_x - 20, y, 50, 110, 126, 13, 356, 408, Color(1, 1, 1, palyer_alpha));
	}
}