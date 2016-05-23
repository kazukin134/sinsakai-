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
	

	float fallcollisionflag;	//���Ƃ����̉���Player���������Ă����痎���Ȃ��悤�ɂ���t���O
	float movedistance;		//Player���^�񒆂ɂ��邽�߂̕␳����
	float fallflag;			//���Ƃ����ɓ����������̃t���O
	float wallhitflag;		//��납�炭��G�̃t���O
	float hittime;			//�G�ɓ������ăX�N���[�����~�܂��Ă��鎞��
	int hitcount;			//�G�ɓ����������ɓ����J�E���g
	//float hitlost;			//���Ƃ����̃t���O
	float over;				//�Q�[���I�[�o�[�ɂ����t���O
	
	float clearflag;  //�S�[���ɂ��ǂ蒅�������̃t���O
private:
	float invincibilitytime; //�G�ɓ���������̖��G����
	float angle;
	
};