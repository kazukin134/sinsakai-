#include "Distance.h"
#include "Player.h"
#include "GameMain.h"
#include "Wall.h"

CDistance::CDistance()
:goal("res/door/door111.png",256,256),
playerdistance("res/png/hasiru.png",512,512),
walldistance("res/png/obake02.png",512,512)
{
	x = -400.0;
	y = 200.0;
	width = 550;
	height = 40;

}



void CDistance::Update()
{
	
}

void CDistance::Draw()
{
	DrawFillBox(x, y, width, height, Color(1, 0.5, 0,1));
	goal.DrawTextureBox(130, y - 5, 50, 50, 0, 0, 86, 226, Color(1, 1, 1,1));
	playerdistance.DrawTextureBox(CGameMain::Player->x / 10 - 200, y, 40, 40, 126, 13, 356, 408, Color(1, 1, 1,1));
	walldistance.DrawTextureBox(CGameMain::Wall->x / 10 - 100, y, 40, 40, 127, 0, 357, 402, Color(1, 1, 1,1));
	

}

