#pragma once
#define _USE_MATH_DEFINES
#include "Object.h"
#include "Collision.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

class CEnemy : public  Object 
{
	Texture enemy01;
	float alpha; //敵のアルファ値

public:
	CEnemy();
	~CEnemy();
	void Draw();
	void Update();
	void Move();

	float startscroll;		//スクロールするための処理
	float enemy2;			//2体目の敵のx座標

	static const int enmeynumber = 9;
	Eigen::Vector2f enemy[enmeynumber];
	float angle;
	float wave;
	float angle_y;
};
