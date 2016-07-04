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

// OpenALの初期化と後始末を代行
//2回呼ばないでください
class Audio
{
	ALCdevice* device;
	ALCcontext* context;

public:

	Audio();
	~Audio();
	void Init();
};

//音の再生部分
class Media
{
	ALuint buffer_id;
	ALuint source_id;
	float  duration_sec_;

public:
	//Media(){};

	//音の読み込み
	//初期化時に音のファイル名を引数を書く
	Media(const std::string  file);

	//音の後処理
	~Media();

	//バッファの処理
	void Buffer(const Wav &wavfile);

	//ソースの処理
	void Source();

	//音の再生
	void Play();

	//音の停止
	void Stop();

	//音の一時停止
	void Pause();

	//音のボリュームの変更(0.0f～1.0f)
	void Gain(const float value);

	//音のループするかどうか
	void Looping(const bool value);

	//音が今流れているかどうか
	bool IsPlaying();

	// 再生位置(秒)
	float CurrentTime();

	// 再生時間(秒)
	float Duration();

};
