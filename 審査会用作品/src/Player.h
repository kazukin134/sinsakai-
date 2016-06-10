#pragma once
#include "Object.h"
#include "Collision.h"
#include "lib\Key.h"
#include "lib\Audio.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

class CPlayer : public Object{

	Texture playerdraw;
	Texture ran;
	Texture jamp;
	Media jampse;

	float invincibilitytime; //敵に当たった後の無敵時間
	float angle; //画像の回転用

public:
	CPlayer();
	~CPlayer();

	void Draw();
	void Update();
	void Collision();
	void Move();
	void HitStop();
	void Invincible();
	void Jump();
	
	enum class JUMPSTATE //ジャンプの状態
	{
		NORMAL,
		JUNP
	};

	 enum class HITSTATE //当たっているかの状態
	{
		NORMAL,
		HIT,
		INVINCIBLE
	};

	JUMPSTATE jumpstate;
	HITSTATE hitstate;

	float palyer_alpha;		//プレイヤーのアルファ値
	float force;			//ジャンプのパワー
	float movedistance;		//Playerが真ん中にいるための補正距離
	float hittime;			//敵に当たってスクロールが止まっている時間
	int hitcount;			//敵に当たった時に動くカウント
	bool is_over;			//ゲームオーバーにいくフラグ
	bool is_clear;			//ゴールにたどり着いた時のフラグ
	bool fallcollisionflag;	//落とし穴の奥にPlayerが当たっていたら落ちないようにするフラグ
	bool is_fall;			//落とし穴に当たった時のフラグ
	bool wallenemyhitflag;	//後ろからくる敵のフラグ
	bool is_hit_enemy;		//敵に当たっているかの判定
	
};