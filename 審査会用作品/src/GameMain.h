#pragma once
#include "Object.h"
#include "lib\Key.h"

class CPlayer;
class CEnemy;
class CDoor;
class CStage;
class CWall;
class CDistance;
class CFear;
class StartCount;

class CGameMain
{
public:
	CGameMain();
	~CGameMain();
	void Draw();
	void Update();
	

	
	static CEnemy *Enemy;
	static CDoor *Door;
	static CStage *Stage;
	static CPlayer *Player;
	static CWall *Wall;
	static CDistance *Distance;
	static CFear *Fear;
	static StartCount *startcount;
};
