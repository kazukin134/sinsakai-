#pragma once

#include <GLFW/glfw3.h>
#include <cstdlib>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#define _USE_MATH_DEFINES

#include "wav.hpp"
#include <vector>
#include <list>

class Audio
{
	
	

	ALCdevice* device = alcOpenDevice(nullptr);

	ALCcontext* context = alcCreateContext(device, nullptr);
	

	ALuint buffer_id;

	ALuint source_id;


public:

	Audio(const std::string  file);

	~Audio();

	void Buffer(Wav wavfile);

	void Source();

	void Play();

	
};
