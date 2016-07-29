#include "Wall.h"
#include "Player.h"
#include "GameMain.h"
#include "Stage.h"

CWall::CWall() :wall("res/png/obake02.png", 512, 512)
{
	x = -2500.0;
	start_y = 64;
	y = 0;//-Window::HEIGHT / 2 + start_y;
	width = 300;
	height = 500;
	velocity_x = 0;
	velocity_y = 0;
	scroll_x = x;
	stage_x = x;
	speed = 3.2f;
	screenspeed = 1.5f;
	movecount = 1;
	disp_x = x - screenspeed * movecount;
}

CWall::~CWall(){}

void CWall::Move()
{
	movecount++;

	if (scroll_x > 0)
	{
		scroll_x += x;
		scroll_x += velocity_x;
	}

	velocity_x = speed;

	if (scroll_x < 0)
	{
		x += velocity_x;
	}

	disp_x = x - screenspeed * movecount;
}

void CWall::Update()
{
	Move();
}

void CWall::Draw()
{
	wall.DrawTextureBox(disp_x, y - 150, width, height - 150, 127, 0, 357, 402, Color(1, 1, 1, 0.7f));
}

