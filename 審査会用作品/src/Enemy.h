#pragma once
#define _USE_MATH_DEFINES
#include "Object.h"
#include "Collision.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

class CEnemy : public  Object 
{
	Texture enemy01;

public:
	CEnemy();
	~CEnemy();
	//Vec2f pos;
	void Draw();
	void Update();
	void Collision();
	void Move();

	
	float startscroll;		//スクロールするための処理
	float enemy2;			//2体目の敵のx座標


	Eigen::Vector2f enemy[20];
	//float enemy_x[20];
	//float enemy_y[20];
	float angle;
	float wave;
	float angle_y;
private:
	
};
