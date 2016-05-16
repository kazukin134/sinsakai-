#include "Audio.h"

Audio::Audio()
{
	Init();
}

Audio::~Audio()
{
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void Audio::Init()
{
	alcMakeContextCurrent(context);

}

Media::Media(const std::string  file)
{
	Wav wav = Wav(file);
	Buffer(wav);
	Source();
}

Media::~Media()
{
	alDeleteSources(1, &source_id);
	alDeleteBuffers(1, &buffer_id);
	alcMakeContextCurrent(nullptr);


}

void  Media::Buffer(Wav wavfile)
{
	alGenBuffers(1, &buffer_id);

	duration_sec_ = wavfile.time();

	alBufferData(buffer_id,
		wavfile.isStereo() ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
		wavfile.data(),
		wavfile.size(),
		wavfile.sampleRate());
}

void Media::Source()
{
	alGenSources(1, &source_id);
	alSourcei(source_id, AL_BUFFER, buffer_id);

	ALfloat gain_value = 0.5;
	alSourcef(source_id, AL_GAIN, gain_value);
}

void Media::Play()
{
	alSourcePlay(source_id);
}

void Media::Stop()
{
	alSourceStop(source_id);
};

void Media::Pause()
{
	alSourcePause(source_id);
};

void Media::Gain(const float value)
{
	alSourcef(source_id, AL_GAIN, value);
};

void Media::Looping(const bool value)
{
	alSourcei(source_id, AL_LOOPING, value ? true : false);
};

bool Media::IsPlaying()
{
	ALint state;
	alGetSourcei(source_id, AL_SOURCE_STATE, &state);
	return state == AL_PLAYING;
};

float Media::CurrentTime()
{
	ALfloat current_time_sce;
	alGetSourcef(source_id, AL_SEC_OFFSET, &current_time_sce);
	return current_time_sce;
};

float Media::Duration()
{
	return duration_sec_;
};
