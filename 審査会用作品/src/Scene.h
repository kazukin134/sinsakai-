#pragma once

#include "GameMain.h"
#include "GameOver.h"
#include "Player.h"
#include "Title.h"
#include "Rule.h"
#include "Door.h"
#include "Clear.h"
#include "Stage.h"
#include "Prologue.h"

class CGameMain;
class CGameOver;
class CTitle;
class CRule;
class CDoor;
class CClear;
class CPrologue;

class CScene
{
public:
	CScene();
	~CScene();

	void Draw();
	void Update();
	void Main();

	
	float bgmflag;
	//CGameMain *GameMain;
	//CGameOver *GameOver;
	//CTitle *Title;
	//CRule *Rule;
	//CClear *Clear;
	//CPrologue *Prologue;
	//CDoor *Door;

	int scene;
	static CGameOver *GameOver;
	static CGameMain *GameMain;
	static CTitle *Title;
	static CRule *Rule;
	static CDoor *Door;
	static CClear *Clear;
	static CPrologue *Prologue;
	static CScene *Scene;
};