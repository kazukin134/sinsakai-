#include "GameMain.h"
#include "Stage.h"
#include "Player.h"
#include "Object.h"
#include "Door.h"
#include "Enemy.h"
#include "Wall.h"
#include "Distance.h"
#include "Fear.h"
#include "StartCount.h"

CPlayer *CGameMain::Player;
CDoor *CGameMain::Door;
CEnemy *CGameMain::Enemy;
CStage *CGameMain::Stage;
CWall *CGameMain::Wall;
CDistance *CGameMain::Distance;
CFear *CGameMain::Fear;
StartCount * CGameMain::startcount;


CGameMain::CGameMain()
{

	Player = new CPlayer();
	Door = new CDoor();
	Enemy = new CEnemy();
	Stage = new CStage();
	Wall = new CWall();
	Distance = new CDistance();
	Fear = new CFear();
	startcount = new StartCount();
}

CGameMain::~CGameMain()
{
	delete Player;
	delete Door;
	delete Enemy;
	delete Stage;
	delete Wall;
	delete Distance;
	delete Fear;
	delete startcount;
}

void CGameMain::Draw()
{
	



	//Door.Draw();
	Stage->Draw();
	Player->Draw();
	Enemy->Draw();
	Wall->Draw();
	Distance->Draw();
	Fear->Draw();
	startcount->Draw();
}

void CGameMain::Update()
{
	if (IsPressKey(GLFW_KEY_1) == false)
	{
		startcount->Update();
		if (startcount->GetTime() > 3){
			Stage->Update();
			Player->Update();
			Enemy->Update();
			Wall->Update();
			Distance->Update();
			Fear->Update();
		}
	}
}

