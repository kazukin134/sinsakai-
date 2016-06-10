#include "Wall.h"
#include "Player.h"
#include "GameMain.h"
#include "Stage.h"

CWall::CWall() :wall("res/raw/obake02.raw", 512, 512)
{
	x = -2500.0;
	startY = 64;
	y = 0;//-Window::HEIGHT / 2 + startY;
	width = 300;
	height = 500;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = x;
	stage_x = x;
	speed = 3.2f;
	screenspeed = 1.5f;
	movecount = 0;
}

CWall::~CWall(){}

void CWall::Move()
{
	movecount++;

	if (scrollX > 0)
	{
		scrollX += x;
		scrollX += velocity_x;
	}

	velocity_x = speed;

	if (scrollX < 0)
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

