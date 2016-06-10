#include "Scene.h" 

CTitle *CScene::Title;
CGameMain *CScene::GameMain;
CGameOver *CScene::GameOver;
CRule *CScene::Rule;
CDoor *CScene::Door;
CClear *CScene::Clear;

CScene::CScene()
{
	Title = new CTitle();
	GameMain = new CGameMain();
	GameOver = new CGameOver();
	Rule = new CRule();
	Door = new CDoor();
	Clear = new CClear();
	scene = Scene::TITLE;
	bgmflag = 0;
}

CScene::~CScene()
{
	delete Title;
	delete GameMain;
	delete GameOver;
	delete Rule;
	delete Door;
	delete Clear;
}

enum Scene
{
	title,
	gamemain,
	gameover,
	rule,
	door,
	clear
};

void CScene::Update()
{
	switch (scene)
	{
	case GAMEMAIN:


		GameMain->Update();
		if (CGameMain::Player->is_over == true)
		{
			scene = GAMEOVER;

		}else
		if (CGameMain::Player->is_clear == true)
		{
			delete GameMain;
 			GameMain = new CGameMain();
			scene = CLEAR;
		}


		break;
	case GAMEOVER:
	{
			  bgmflag = 1;
			  GameOver->selected_title = 0;
			  GameOver->Update();

			  if (CGameMain::Player->is_over == 0)
			  {

				  scene = GAMEMAIN;
				  delete GameMain;
				  GameMain = new CGameMain();

			  }
			  if (GameOver->selected_title == 1)
			  {
				  scene = TITLE;
			  }
	}
		break;
	case TITLE:
	{
			  Title->selected_game = 0;
			  Title->Update();
			  if (Title->selected_game == 1)
			  {
				  scene = GAMEMAIN;
				  delete GameMain;
				  GameMain = new CGameMain();
			  }
			  if (Title->selected_rule == 1)
			  {
				  scene = RULE;
			  }

	}
		break;
	case RULE:
	{
			  Title->selected_rule = 0;
			  Rule->Update();

			  if (Rule->rule_draw >= 1)
			  {
				  scene = TITLE;
				  Rule->rule_draw = 0;
			  }
	}
		break;
	case DOOR:
	{
			  Door->Update();


			  if (Door->selected_door == 1)
			  {
				  scene = CLEAR;
			  }
	}
		break;
	case CLEAR:
	{
			  Clear->Update();
			  if (Clear->selected_clear == 1)
			  {

				  scene = TITLE;
			  }
	}
		break;
	}

}

void CScene::Draw()
{
	switch (scene)
	{
	case GAMEMAIN:
		GameMain->Draw();
		break;
	case GAMEOVER:

		GameOver->Draw();
		break;
	case TITLE:
		Title->Draw();
		break;
	case RULE:
		Rule->Draw();
		break;
	case DOOR:
		Door->Draw();
		break;
	case CLEAR:
		Clear->Draw();
		break;
	}
}

void CScene::Main()
{
	Update();
	Draw();
}