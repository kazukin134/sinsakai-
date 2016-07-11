#include "Enemy.h"
#include "Collision.h"
#include "Stage.h"
#include "Player.h"
#include "GameMain.h"


CEnemy::CEnemy() : enemy01("res/png/obake.png",512,512)
{
	x = 500.0;
	startY = 0;
	y =  -240;
	width = 50;
	height = 50;
	velocity_x = 0;
	velocity_y = 0;
	scrollX = x;
	stage_x = this->x;
	speed = 3.2;
	startscroll = 0;
	enemy2 = this->x + 600;
	angle = 0.0;
	angle_y = 0.0;
	alpha = 1.0f;
}

CEnemy::~CEnemy(){}

void CEnemy::Move()
{
	static int count;
	wave = 0;
	count++;
	alpha -= std::sin(count / 12)/8;
	if (alpha <= 0.1f)
	{
		alpha = 0.1f;
	}

	enemy[0] = Eigen::Vector2f(x + 100,y + 100);
	enemy[1] = Eigen::Vector2f(x + 400,y + 200);
	enemy[2] = Eigen::Vector2f(x + 600,y + 100);
	enemy[3] = Eigen::Vector2f(x + 1000,y + 100);
	enemy[4] = Eigen::Vector2f(x + 1800,y + 100);
	enemy[5] = Eigen::Vector2f(x + 2000,y + 200);
	enemy[6] = Eigen::Vector2f(x + 2200,y + 200);
	enemy[7] = Eigen::Vector2f(x + 2400,y + 100);
	enemy[8] = Eigen::Vector2f(x + 2600, y + 200);

	if (!(CGameMain::Player->hitstate == CPlayer::HITSTATE::HIT) && !(CGameMain::Player->is_fall == true))
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
	//Collision();
	Move();
}

void CEnemy::Draw()
{
	for (int i = 0; i < enmeynumber; i++)
	{
		enemy01.DrawTextureBox(enemy[i].x(), enemy[i].y(), width, height, 31, 0, 314, 403, Color(1, 1, 1, alpha));
	}
}
