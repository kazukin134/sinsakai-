#pragma once

#include <memory>
#include "GameMain.h"
#include "GameOver.h"
#include "Player.h"
#include "Title.h"
#include "Rule.h"
#include "Door.h"
#include "Clear.h"
#include "Stage.h"

class CGameMain;
class CGameOver;
class CTitle;
class CRule;
class CDoor;
class CClear;

class CScene
{

public:
	CScene();
	~CScene();

	void Draw();
	void Update();
	void Main();

	float bgmflag;
	int scene;

	//std::unique_ptr<CGameMain> GameMain;
	//std::unique_ptr<CGameOver> GameOver;
	//std::unique_ptr<CTitle> Title();
	//std::unique_ptr<CRule> Rule;
	//std::unique_ptr<CDoor> Door;
	//std::unique_ptr<CClear> Clear;

	static CGameOver *GameOver;
	static CGameMain *GameMain;
	static CTitle *Title;
	static CRule *Rule;
	static CDoor *Door;
	static CClear *Clear;
	static CScene *Scene;
};