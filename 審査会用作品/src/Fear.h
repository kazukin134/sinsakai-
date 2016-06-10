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

	float feargauge;	//���݂̃Q�[�W�̗�

private:

	const float gaugemax = 150;		//���|�Q�[�W�̍ő�l
	float gaugeup;		//������Q�[�W�̗�
	float cooltime;		//����������Ɍ���Q�[�W�̗�
	float fearflag;		//�Q�[�W�������邩�ǂ����̃t���O
};