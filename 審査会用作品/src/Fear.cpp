#include "Player.h"
#include "Collision.h"
#include "GameMain.h"
#include "Enemy.h"
#include "Fear.h"

CFear::CFear()// : player("res/ct.png")
{

	x = -350.0;
	y = 150.0;
	width = 150;
	height = 40;
	feargauge = 0;
	cooltime = 0.0;
	fearflag = 0;
	gaugeup = 0;
}


CFear::~CFear()
{

}

void CFear::Move()
{

}

void CFear::Gauge()
{
	if (CGameMain::Player->hitfear == false)
		fearflag = 0;
	

	if (feargauge <= 0)
	{
		cooltime = 0.0;
		gaugeup = 0;
	}

	if (CGameMain::Player->hitfear == true)
	{

		if (fearflag == 0)
		{	
			gaugeup += 70;
			fearflag = 1;
		}
		
	}

	if (CGameMain::Player->hitstate == CPlayer::HITSTATE::NORMAL)
	{
		cooltime -= 0.5;

	}
	if (feargauge <= gaugemax)
		feargauge = gaugeup + cooltime;
	if (feargauge >= gaugemax)
		feargauge = gaugemax;

	if (feargauge >= 150)
	{
		CGameMain::Player->palyer_alpha -= 0.02f;
	}
//		CGameMain::Player->over = 1;



}

void CFear::Update()
{
	Move();
	Gauge();

}

void CFear::Draw()
{
	DrawFillBox(x, y, width, height, Color(0.5, 0.5, 0.5, 1));
	
	DrawFillBox(x, y, feargauge, height, Color(1, 0, 0, 1));
	
	//DrawBox(x, y, width, height,0.8f, Color(0, 1, 0));
}