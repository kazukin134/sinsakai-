#pragma once

#include "Object.h"
#include "Collision.h"
#include "lib\DrawBox.h"

class CFear : public Object{

public:
	CFear();
	~CFear();

	void Draw();
	void Update();
	void Gauge();

	float feargauge;	//現在のゲージの量

private:

	const float gaugemax = 150;		//恐怖ゲージの最大値
	float gaugeup;		//増えるゲージの量
	float cooltime;		//当たった後に減るゲージの量
	float fearflag;		//ゲージが増えるかどうかのフラグ
};