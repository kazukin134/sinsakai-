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

	float stage_x;		//�}�b�vx���W
	float stage_y;		//�}�b�vy���W
	float start_x;		//�ŏ���x���W
	float start_y;		//�ŏ���y���W

	float scroll_x;		//�X�N���[��
	float speed = 3;		//���x
	float velocity_x;	//x���x
	float velocity_y;	//y���x
	const float margin = 64;  //����
	float fall;			//���Ƃ����ɓ����������ɗ����鋗��
	bool hitfear;		//�G�ɓ����������̋��|�Q�[�W�̃t���O
	float choice_game;  //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�Q�[���{��)
	float choice_title; //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�^�C�g��)
	float choice_rule;  //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (���[��)
	float choice_end;   //�I�����Ă��邱�Ƃ�������悤�ɍ��ɓ����� (�I��)
	float disp_x;			//�\������x���W
	float movecount;		//�X�N���[���̂��߂̃J�E���g

	//Eigen::Vector2i window_size = Eigen::Vector2i(window_width, window_height);//window�̃T�C�Y������悤�ɂ���

};