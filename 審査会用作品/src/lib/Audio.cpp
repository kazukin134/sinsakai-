#include "Audio.h"

Audio::Audio(const std::string  file )
{
	Wav wav = Wav(file);
	alcMakeContextCurrent(context);
	Buffer(wav);
}

Audio::~Audio()
{
	alDeleteSources(1, &source_id);
	alDeleteBuffers(1, &buffer_id);
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);

}

void  Audio::Buffer(Wav wavfile)
{
	alGenBuffers(1, &buffer_id);

	alBufferData(buffer_id,
		AL_FORMAT_MONO16,
		wavfile.data(),
		wavfile.size(),
		wavfile.sampleRate() * 2);
}

void Audio::Source()
{
	alGenSources(1, &source_id);
	alSourcei(source_id, AL_BUFFER, buffer_id);

	ALfloat gain_value = 0.5;
	alSourcef(source_id, AL_GAIN, gain_value);
}
void Audio::Play()
{
	alSourcePlay(source_id);
}