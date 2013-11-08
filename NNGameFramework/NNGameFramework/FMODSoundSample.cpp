
#ifdef _DEBUG

#include "FMODSoundSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"

FMODSoundSample::FMODSoundSample()
{
	m_Background = NNResourceManager::GetInstance()->LoadSoundFromFile( "Resources/Sound/effect1.mp3", true );
	m_Sound = NNResourceManager::GetInstance()->LoadSoundFromFile( "Resources/Sound/effect.wav" );
	// ���� ����. ������ ������

	NNAudioSystem::GetInstance()->Play( m_Sound ); // �÷���
	NNAudioSystem::GetInstance()->Play( m_Background ); // �÷���
}
FMODSoundSample::~FMODSoundSample()
{

}

void FMODSoundSample::Render()
{
	NNScene::Render();
}
void FMODSoundSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif