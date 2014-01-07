#include "NNGameOver.h"
#include "NNInputSystem.h"
#include "NNSoundManager.h"
#include "NNSceneDirector.h"
#include "NNStartScene.h"
#include "NNLabel.h"


NNGameOver::NNGameOver(void)
{
	m_pBackGround=NNSprite::Create( GAMEOVER_SPRITE );
	AddChild( m_pBackGround );
}

NNGameOver::NNGameOver( float timeScore, float waitTime )
{
	m_pBackGround=NNSprite::Create( GAMEOVER_SPRITE );
	AddChild( m_pBackGround );

	m_ElapsedPlayTimeLabel = NNLabel::Create
		(L"0.0", L"Feast of Flesh BB", 80.f, 0xAE3011);

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"TIME SCORE : %0.1f", 
		timeScore - waitTime );
	
	m_ElapsedPlayTimeLabel->SetPosition(150.f, 300.f);
	m_ElapsedPlayTimeLabel->SetZindex(0);
	m_ElapsedPlayTimeLabel->SetString(m_PlayTimeString);
	AddChild(m_ElapsedPlayTimeLabel);
}


NNGameOver::~NNGameOver(void)
{
}

void NNGameOver::Render()
{
	NNScene::Render();
}

void NNGameOver::Update( float dTime )
{
	NNScene::Update( dTime );
	
	if( NNInputSystem::GetInstance()->PressedKeyCheck() )
	{
		NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_BgmChannel);
		//exit(0);
		NNSceneDirector::GetInstance()->ChangeScene( new NNStartScene() );
		return;
	}
}
