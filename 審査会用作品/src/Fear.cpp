#include "Player.h"
#include "Collision.h"
#include "GameMain.h"
#include "Enemy.h"
#include "Fear.h"

CFear::CFear()
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

CFear::~CFear(){}

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
}

void CFear::Update()
{
	Gauge();
}

void CFear::Draw()
{
	DrawFillBox(x-2.5, y-2.5, width+5, height+5, Color(0, 1, 1, 1));
	DrawFillBox(x, y, width, height, Color(0.5, 0.5, 0.5, 1));
	DrawFillBox(x, y, feargauge, height, Color(1, 0, 0, 1));
}