
#pragma once

#include "NNConfig.h"
#include "NNSound.h"

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
private:
	static NNAudioSystem* m_pInstance;

private:
	NNAudioSystem();
	~NNAudioSystem();

public:
	static NNAudioSystem* GetInstance();
	static void ReleaseInstance();

private:
	NNSound* m_BackgroundSound;
	std::map<std::string, NNSound*> m_EffectSoundTable;

public:
	/*		Background	*/
	void SetBackgroundSound( std::wstring path );
	void PlayBackgroundSound();
	void PauseBackgroundSound();
	void StopBackgroundSound();

	/*		Effect		*/
	void AddEffectSound( std::string key, std::wstring path );
	void RemoveEffectSound( std::string key );

	void PlayEffectSound( std::string key );
	void PauseEffectSound( std::string key );
	void StopEffectSound( std::string key );

	void AllPlayEffectSound();
	void AllPauseEffectSound();
	void AllStopEffectSound();

public:
	inline NNSound* GetBackgroundSound() const { return m_BackgroundSound; }
	inline NNSound* GetEffectSound( std::string key ) /*const*/ { return m_EffectSoundTable[key]; }
};


