#pragma once

#include <GLFW/glfw3.h>
#include <cstdlib>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>


#define _USE_MATH_DEFINES

#include "wav.hpp"
#include <vector>
#include <list>

static bool isfirst = false;

// OpenAL�̏������ƌ�n�����s
//2��Ă΂Ȃ��ł�������
class Audio
{
	ALCdevice* device;
	ALCcontext* context;

public:

	Audio();
	~Audio();
	void Init();
};

//���̍Đ�����
class Media
{
	ALuint buffer_id;
	ALuint source_id;
	float  duration_sec_;

public:
	//Media(){};

	//���̓ǂݍ���
	//���������ɉ��̃t�@�C����������������
	Media(const std::string  file);

	//���̌㏈��
	~Media();

	//�o�b�t�@�̏���
	void Buffer(const Wav &wavfile);

	//�\�[�X�̏���
	void Source();

	//���̍Đ�
	void Play();

	//���̒�~
	void Stop();

	//���̈ꎞ��~
	void Pause();

	//���̃{�����[���̕ύX(0.0f�`1.0f)
	void Gain(const float value);

	//���̃��[�v���邩�ǂ���
	void Looping(const bool value);

	//����������Ă��邩�ǂ���
	bool IsPlaying();

	// �Đ��ʒu(�b)
	float CurrentTime();

	// �Đ�����(�b)
	float Duration();

};
