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

	float invincibilitytime; //�G�ɓ���������̖��G����
	float angle; //�摜�̉�]�p

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
	
	enum class JUMPSTATE //�W�����v�̏��
	{
		NORMAL,
		JUNP
	};

	 enum class HITSTATE //�������Ă��邩�̏��
	{
		NORMAL,
		HIT,
		INVINCIBLE
	};

	JUMPSTATE jumpstate;
	HITSTATE hitstate;

	float palyer_alpha;		//�v���C���[�̃A���t�@�l
	float force;			//�W�����v�̃p���[
	float movedistance;		//Player���^�񒆂ɂ��邽�߂̕␳����
	float hittime;			//�G�ɓ������ăX�N���[�����~�܂��Ă��鎞��
	int hitcount;			//�G�ɓ����������ɓ����J�E���g
	bool is_over;			//�Q�[���I�[�o�[�ɂ����t���O
	bool is_clear;			//�S�[���ɂ��ǂ蒅�������̃t���O
	bool fallcollisionflag;	//���Ƃ����̉���Player���������Ă����痎���Ȃ��悤�ɂ���t���O
	bool is_fall;			//���Ƃ����ɓ����������̃t���O
	bool wallenemyhitflag;	//��납�炭��G�̃t���O
	bool is_hit_enemy;		//�G�ɓ������Ă��邩�̔���
	
};