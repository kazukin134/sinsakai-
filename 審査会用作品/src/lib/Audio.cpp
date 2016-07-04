#include "Audio.h"

Audio::Audio()
{
	device = alcOpenDevice(nullptr);
	context = alcCreateContext(device, nullptr);
	Init();
}

Audio::~Audio()
{
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

//一回だけ呼んで欲しい
void Audio::Init()
{
	//２回以上は通らないようにした。
	if (isfirst)return;
	alcMakeContextCurrent(context);
	isfirst = true;
}
//音の読み込み
//初期化時に音のファイル名を引数を書く
Media::Media(const std::string  file)
{
	Wav wav = Wav(file);
	Buffer(wav);
	Source();
}

//後処理
Media::~Media()
{
	alDeleteBuffers(1, &buffer_id);
	alSourcei(source_id, AL_BUFFER, 0);
	alDeleteSources(1, &source_id);
}

//バッファの処理
void  Media::Buffer(const Wav &wavfile)
{
	alGenBuffers(1, &buffer_id);

	duration_sec_ = wavfile.time();

	alBufferData(buffer_id,
		wavfile.isStereo() ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
		wavfile.data(),
		wavfile.size(),
		wavfile.sampleRate());
}

//ソースの処理
void Media::Source()
{
	alGenSources(1, &source_id);
	alSourcei(source_id, AL_BUFFER, buffer_id);
}

//音の再生
void Media::Play()
{
	alSourcePlay(source_id);
}

//音の停止
void Media::Stop()
{
	alSourceStop(source_id);
};

//音の一時停止
void Media::Pause()
{
	alSourcePause(source_id);
};

//音のボリュームの変更(0.0f～1.0f)
void Media::Gain(const float value)
{
	float volume = 0.0f;
	volume = value;

	if (volume > 1)
	{
		volume = 1.0f;
	}
	else
		if (volume < 0.0f)
		{
			volume = 0.0f;
		}

	alSourcef(source_id, AL_GAIN, volume);
};

//音のループするかどうか
void Media::Looping(const bool value)
{
	alSourcei(source_id, AL_LOOPING, value);
};

//音が今流れているかどうか
bool Media::IsPlaying()
{
	ALint state;
	alGetSourcei(source_id, AL_SOURCE_STATE, &state);
	return state == AL_PLAYING;
};

// 再生位置(秒)
float Media::CurrentTime()
{
	ALfloat current_time_sce;
	alGetSourcef(source_id, AL_SEC_OFFSET, &current_time_sce);
	return current_time_sce;
};

// 再生時間(秒)
float Media::Duration()
{
	return duration_sec_;
};
