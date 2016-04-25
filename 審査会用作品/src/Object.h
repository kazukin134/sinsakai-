#pragma once
#include "Collision.h"
#include "lib\Texture.h"
class Object
{

public:
	float x;			//x���W
	float y;			//y���W
	float width;		//��
	float height;		//����
	float stageX;		//�}�b�vx���W
	float stageY;		//�}�b�vy���W
	float startX;		//�ŏ���x���W
	float startY;		//�ŏ���y���W
	float scrollX;		//�X�N���[��
	float speed;		//���x
	float velocity_x;	//x���x
	float velocity_y;	//y���x
	const float margin = 64;  //����
	float fall;			//���Ƃ����ɓ����������ɗ����鋗��
	float hitflag;		//�����������̃t���O
	float hitfear;		//�G�ɓ����������̋��|�Q�[�W�̃t���O
	float choice_game;  //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�Q�[���{��)
	float choice_title; //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�^�C�g��)
	float choice_rule;  //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (���[��)
	float choice_end;   //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�I��)
	float disp_x;			//�\������x���W
	float movecount;		//�X�N���[���̂��߂̃J�E���g
};