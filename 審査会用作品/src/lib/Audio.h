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


class Audio
{
	ALCdevice* device;
	ALCcontext* context;

public:

	Audio();
	~Audio();
	void Init();
};

class Media
{
	ALuint buffer_id;
	ALuint source_id;

	float  duration_sec_;

public:
	Media(){};
	Media(const std::string  file);
	~Media();

	void Buffer(Wav wavfile);

	void Source();

	void Play();

	void Stop();

	void Pause();

	void Gain(const float value);

	void Looping(const bool value);

	bool IsPlaying();

	float CurrentTime();

	float Duration();

};
