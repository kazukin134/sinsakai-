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

//��񂾂��Ă�ŗ~����
void Audio::Init()
{
	//�Q��ȏ�͒ʂ�Ȃ��悤�ɂ����B
	if (isfirst)return;
	alcMakeContextCurrent(context);
	isfirst = true;
}
//���̓ǂݍ���
//���������ɉ��̃t�@�C����������������
Media::Media(const std::string  file)
{
	Wav wav = Wav(file);
	Buffer(wav);
	Source();
}

//�㏈��
Media::~Media()
{
	alDeleteBuffers(1, &buffer_id);
	alSourcei(source_id, AL_BUFFER, 0);
	alDeleteSources(1, &source_id);
}

//�o�b�t�@�̏���
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

//�\�[�X�̏���
void Media::Source()
{
	alGenSources(1, &source_id);
	alSourcei(source_id, AL_BUFFER, buffer_id);
}

//���̍Đ�
void Media::Play()
{
	alSourcePlay(source_id);
}

//���̒�~
void Media::Stop()
{
	alSourceStop(source_id);
};

//���̈ꎞ��~
void Media::Pause()
{
	alSourcePause(source_id);
};

//���̃{�����[���̕ύX(0.0f�`1.0f)
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

//���̃��[�v���邩�ǂ���
void Media::Looping(const bool value)
{
	alSourcei(source_id, AL_LOOPING, value);
};

//����������Ă��邩�ǂ���
bool Media::IsPlaying()
{
	ALint state;
	alGetSourcei(source_id, AL_SOURCE_STATE, &state);
	return state == AL_PLAYING;
};

// �Đ��ʒu(�b)
float Media::CurrentTime()
{
	ALfloat current_time_sce;
	alGetSourcef(source_id, AL_SEC_OFFSET, &current_time_sce);
	return current_time_sce;
};

// �Đ�����(�b)
float Media::Duration()
{
	return duration_sec_;
};
