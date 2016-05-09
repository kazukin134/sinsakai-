#include "Audio.h"

Audio::Audio()
{
	//device = alcOpenDevice(nullptr);
	//context = alcCreateContext(device, nullptr);
	alcMakeContextCurrent(context);
	alGenBuffers(1, &buffer_id[0]);

}

Audio::~Audio()
{
	alDeleteSources(1, &source_id[0]);
	alDeleteBuffers(1, &buffer_id[0]);
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);

}

void  Audio::Buffer()
{
	alBufferData(buffer_id[0],
		AL_FORMAT_MONO16,
		wav1.data(),
		wav1.size(),
		wav1.sampleRate() * 2);
}

void Audio::Source()
{
	alGenSources(5, &source_id[0]);
	alSourcei(source_id[0], AL_BUFFER, buffer_id[0]);

	ALfloat gain_value1 = 0.5;
	alSourcef(source_id[0], AL_GAIN, gain_value1);
}
void Audio::Play()
{
	alSourcePlay(source_id[0]);
}