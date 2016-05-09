#pragma once

#include <GLFW/glfw3.h>
#include <cstdlib>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <thread>
#include "wav.hpp"
#include <vector>

class Audio
{
	
	ALCdevice* device = alcOpenDevice(nullptr);

	ALCcontext* context = alcCreateContext(device, nullptr);

	Wav wav1 = Wav("res/wav/éÙÇ¢ÇÃçsï˚.wav");

	float time = wav1.time();

	const size_t pcm_freq = time;

	ALuint buffer_id[5];

	ALuint source_id[5];


public:

	Audio();

	~Audio();

	void Buffer();

	void Source();

	void Play();

	
};
