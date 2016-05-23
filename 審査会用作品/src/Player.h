#pragma once
#include "Object.h"
#include "Collision.h"
#include "lib\Key.h"
#include "lib\Audio.h"

class CPlayer : public Object{

	Texture playerdraw;
	Texture ran;
	Texture jamp;
	Media jampse;

	//Texture player;


public:
	CPlayer();
	~CPlayer();
	//Vec2f pos;
	void Draw();
	void Update();
	void Collision();
	void Move();
	float palyer_alpha;


	float force;
	

	enum class STATE
	{
		NORMAL,
		JUNP

	};

	STATE state;
	

	float fallcollisionflag;	//落とし穴の奥にPlayerが当たっていたら落ちないようにするフラグ
	float movedistance;		//Playerが真ん中にいるための補正距離
	float fallflag;			//落とし穴に当たった時のフラグ
	float wallhitflag;		//後ろからくる敵のフラグ
	float hittime;			//敵に当たってスクロールが止まっている時間
	int hitcount;			//敵に当たった時に動くカウント
	//float hitlost;			//落とし穴のフラグ
	float over;				//ゲームオーバーにいくフラグ
	
	float clearflag;  //ゴールにたどり着いた時のフラグ
private:
	float invincibilitytime; //敵に当たった後の無敵時間
	float angle;
	
};