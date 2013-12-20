
#pragma once

#include "NNConfig.h"
#include "NNSound.h"
#include "Library/FMOD/inc/fmod.hpp"
#include "Library/FMOD/inc/fmod_errors.h"

/* */
/* NNAudioSystem
/* ���� ����� ����ϴ� �̱��� Ŭ����/* */
/* Application
/* �����ӿ�ũ�� �ٽ� Ŭ����
/* �������� ������ �������� �����ϰ�
/* ���� ������ ���� ��Ȱ�� �Ѵ�.
/* */
/* */

class NNAudioSystem
{
public:
	static NNAudioSystem* GetInstance();
	static void ReleaseInstance();

	void Play( NNSound* sound );
	void Pause( NNSound* sound );
	void Stop( NNSound* sound );
	void Reset( NNSound* sound );

	void SetVolume( NNSound* sound, float volume );
	void SetPan( NNSound* sound, float pan );
	void SetFrequency( NNSound* sound, float frequency );

	bool IsPlay( NNSound* sound );

	FMOD::System* GetSystem() { return m_System; }

private:
	FMOD::System* m_System;
	FMOD::ChannelGroup* m_ChannelGroup;

	static NNAudioSystem* m_pInstance;

	NNAudioSystem();
	~NNAudioSystem();
};