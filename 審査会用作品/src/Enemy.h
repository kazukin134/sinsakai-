#pragma once
#define _USE_MATH_DEFINES
#include "Object.h"
#include "Collision.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

class CEnemy : public  Object 
{
	Texture enemy01;
	float alpha; //�G�̃A���t�@�l

public:
	CEnemy();
	~CEnemy();
	void Draw();
	void Update();
	void Move();

	float startscroll;		//�X�N���[�����邽�߂̏���
	float enemy2;			//2�̖ڂ̓G��x���W

	static const int enmeynumber = 9;
	Eigen::Vector2f enemy[enmeynumber];
	float angle;
	float wave;
	float angle_y;
};
