#include "Scene.h" 

CTitle *CScene::Title;
CGameMain *CScene::GameMain;
CGameOver *CScene::GameOver;
CRule *CScene::Rule;
CDoor *CScene::Door;
CClear *CScene::Clear;
CPrologue * CScene::Prologue;

CScene::CScene()
{
	
	Title = new CTitle();
	GameMain = new CGameMain();
	GameOver = new CGameOver();
	Rule = new CRule();
	Door = new CDoor();
	Clear = new CClear();
	Prologue = new CPrologue();
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
	delete Prologue;
}

void CScene::Update()
{

			  switch (scene)
			  {
			  case 0:
			  
						GameMain->Update();
						if (CGameMain::Player->over == 1)
						{														
							scene = 1;

						}
						if (CGameMain::Player->clearflag == 1)
						{
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

						if (CGameMain::Player->over == 0)
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
			  case 6:
			  {
						Prologue->Update();
						
			  }
				  break;
		}
		
}

void CScene::Draw()
{
	

		//app_env->setupDraw();
		switch (scene)
		{
		case 0:
				  GameMain->Draw();

			break;
		case 1:
		{
				  GameOver->Draw();
		}
			break;
		case 2:
		{
				  Title->Draw();
		}
			break;
		case 3:
		{
				  Rule->Draw();
		}
			break;
		case 4:
		{
				  Door->Draw();
		}
			break;
		case 5:
		{
				  Clear->Draw();
		}
			break;
		case 6:
		{

				  Prologue->Draw();
		}
			break;
		}

		// ‰æ–ÊXV
		//app_env->update();
}

void CScene::Main()
{
	Update();
	Draw();
}