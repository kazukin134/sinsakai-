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
	scene = 2;
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
	case 0:


		GameMain->Update();
		if (CGameMain::Player->is_over == true)
		{
			scene = 1;

		}else
		if (CGameMain::Player->is_clear == true)
		{
			//GameMain.reset();

			delete GameMain;
 			GameMain = new CGameMain();
			scene = 4;
		}


		break;
	case 1:
	{

			  bgmflag = 1;

			  GameOver->selected_title = 0;
			  GameOver->Update();

			  if (CGameMain::Player->is_over == 0)
			  {

				  scene = 0;
				  delete GameMain;
				  GameMain = new CGameMain();

			  }
			  if (GameOver->selected_title == 1)
			  {
				  scene = 2;
			  }
			  /*if (bgmflag == 1)
			  {
			  delete GameMain;

			  }*/
	}
		break;
	case 2:
	{
			  Title->selected_game = 0;
			  Title->Update();
			  if (Title->selected_game == 1)
			  {
				  scene = 0;
				  delete GameMain;
				  GameMain = new CGameMain();
			  }
			  if (Title->selected_rule == 1)
			  {
				  scene = 3;
			  }

	}
		break;
	case 3:
	{
			  Title->selected_rule = 0;
			  Rule->Update();

			  if (Rule->rule_draw >= 1)
			  {
				  scene = 2;
				  Rule->rule_draw = 0;
			  }
	}
		break;
	case 4:
	{
			  Door->Update();


			  if (Door->selected_door == 1)
			  {
				  scene = 5;
			  }
	}
		break;
	case 5:
	{
			  Clear->Update();
			  if (Clear->selected_clear == 1)
			  {

				  scene = 2;
			  }
	}
		break;
	}

}

void CScene::Draw()
{
	switch (scene)
	{
	case 0:
		GameMain->Draw();
		break;
	case 1:

		GameOver->Draw();
		break;
	case 2:
		Title->Draw();
		break;
	case 3:
		Rule->Draw();
		break;
	case 4:
		Door->Draw();
		break;
	case 5:
		Clear->Draw();
		break;
	}
}

void CScene::Main()
{
	Update();
	Draw();
}