#include "Enemy.h"
#include "Collision.h"
#include "Stage.h"
#include "Player.h"
#include "GameMain.h"


CEnemy::CEnemy() : enemy01("res/raw/obake.raw",512,512)
{

	x = 500.0;
	startY = 0;//150;
	y =  -240;
	width = 50;
	height = 50;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = x;
	stageX = this->x;
	speed = 4;
	hitflag = 0;
	startscroll = 0;
	enemy2 = this->x + 600;
	angle = 0.0;
	angle_y = 0.0;
}

CEnemy::~CEnemy()
{
	
}

void CEnemy::Collision()
{

}

void CEnemy::Move()
{

	//angle_y = angle;
	wave = 0;//std::sin(angle_y) * 25.0;
	//angle_y += 0.04f;


	
	enemy[0].x() = x + 100;
	//enemy[1].x() = x + 100;
	enemy[2].x() = x + 400;
	enemy[3].x() = x + 600;
	enemy[4].x() = x + 1000;
//	enemy[5].x() = x + 1200;
	enemy[6].x() = x + 3100;
	//enemy[7].x() = x + 1600;
	enemy[8].x() = x + 1800;
	//enemy[9].x() = x  + 3500;
	enemy[10].x() = x + 2000;
	enemy[11].x() = x + 2200;
	enemy[12].x() = x + 2400;
	enemy[13].x() = x + 2600;
	//enemy[14].x() = x + 2800;
	//enemy[15].x() = x + 3800;

	enemy[0].y() = y + 100;
	//enemy[1].y() = y + 150;
	enemy[2].y() = y + 150;
	enemy[3].y() = y + 100;
	enemy[4].y() = y + 100;
	//enemy[5].y() = y + 150;
	enemy[6].y() = y + 150;
	//enemy[7].y() = y + 100;
	enemy[8].y() = y + 100;
	//enemy[9].y() = y + 150;
	enemy[10].y() = y + 150;
	enemy[11].y() = y + 150;
	enemy[12].y() = y + 100;
	enemy[13].y() = y + 150;
	//enemy[14].y() = y + 150;
	//enemy[15].y() = y + 150;
	

	if (!(CGameMain::Player->hitflag == 1)&&!(CGameMain::Player->fallflag == 1))
	{

		if (startscroll == 0)
		{  
			scrollX += x;
			scrollX -= velocity_x;
			startscroll = 1;
		}


		velocity_x = speed;

		if (scrollX > 0)
		{
			x -= velocity_x;

		}
	}

}

void CEnemy::Update()
{
	Collision();
	Move();

}

void CEnemy::Draw()
{

	for (int i = 0; i < 15; i++)
	{
		//if (CGameMain::Player->hitflag == 0)
			enemy01.DrawTextureBox(enemy[i].x(), enemy[i].y(), width, height, 31, 0, 314, 403, Color(1, 1, 1,0.5f));
	}
}
