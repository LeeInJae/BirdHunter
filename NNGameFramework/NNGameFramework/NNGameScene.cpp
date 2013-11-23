#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"
#include "NNBirdFactory.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include "NNPooManager.h"
#include <assert.h>
#include "NNMapManager.h"
#include "NNEffectManager.h"
#include "NNSound.h"
#include "NNAudioSystem.h"

NNGameScene::NNGameScene(void )
{
	m_CheckGameOver = false;
	m_Character = new NNPlayerCharacter();

	m_SumTime = 0;

	AddChild( NNMapManager::GetInstance() );
	AddChild( m_Character );
	AddChild( NNPooManager::GetInstance() );
	AddChild( NNBulletManager::GetInstance() );
	AddChild( NNBirdFactory::GetInstance() );
	AddChild( NNEffectManager::GetInstance() );

	UIInit();
	m_AudioPlayer = NNAudioSystem::GetInstance();
	m_AudioPlayer->Play(SE_GAMESTART);
}

void NNGameScene::UIInit()
{
	m_PlayTimeLabel = NNLabel::Create(L"TIME : ", L"¸¼Àº °íµñ", 15.f);
	m_PlayTimeLabel->SetPosition(1.f, 1.f);
	AddChild(m_PlayTimeLabel);

	m_LandedPooLabel = NNLabel::Create(L"POLLUTION : ", L"¸¼Àº °íµñ", 15.f);
	m_LandedPooLabel->SetPosition(1.f, 30.f);
	AddChild(m_LandedPooLabel);

	m_FPSLabel = NNLabel::Create(L"FPS : ", L"¸¼Àº °íµñ", 15.f);
	m_FPSLabel->SetPosition(670.f, 1.f);
	AddChild(m_FPSLabel);
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	if(m_CheckGameOver)
		return;

	NNScene::Update( dTime );

	m_SumTime += dTime;
		
	if( m_SumTime >= 3 )
 	{
 		NNBirdFactory::GetInstance()->MakeBird( NORMAL_BIRD );
		NNBirdFactory::GetInstance()->MakeBird( NORMAL_BIRD );
		NNBirdFactory::GetInstance()->MakeBird( EASY_BIRD );
		m_SumTime = 0;
 	}


	
	UIUpdate( dTime );
}

void NNGameScene::Render()
{
   	NNScene::Render();
}

void NNGameScene::UIUpdate( float dTime )
{
	if( NNPooManager::GetInstance()->HitCheckByPlayer( m_Character ) )
	{ 
		m_GameOverLabel = NNLabel::Create(L"GameOver ", L"¸¼Àº °íµñ", 50.f);
		m_GameOverLabel->SetPosition(RESOLUTION_WIDTH * 0.5f, RESOLUTION_HEIGHT * 0.5f );
		m_GameOverLabel->SetCenter(RESOLUTION_WIDTH, RESOLUTION_HEIGHT); 
		AddChild(m_GameOverLabel);
		m_CheckGameOver = true;
	}

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"TIME : %0.1f sec", NNApplication::GetInstance()->GetElapsedTime());
	m_PlayTimeLabel->SetString(m_PlayTimeString);

	swprintf_s(m_LandedPooString, _countof(m_LandedPooString), L"POLLUTION : %d ", NNPooManager::GetInstance()->GetLandedPoo());
	m_LandedPooLabel->SetString(m_LandedPooString);

	swprintf_s(m_FPSString, _countof(m_FPSString), L"FPS : %0.1f ", NNApplication::GetInstance()->GetFPS());
	m_FPSLabel->SetString(m_FPSString);
}

