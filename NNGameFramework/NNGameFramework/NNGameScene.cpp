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
	
	m_PauseTime	= 0;
	m_SumTime = 0;

	struct BIRD_BORN_TIME birdBornItem;

	birdBornItem.birdType		=	BLACK_SMALL_BIRD;
	birdBornItem.bornTime		=	BLACK_SMALL_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	SMALL_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 0 ]	=	birdBornItem;

	birdBornItem.birdType		=	ORANGE_SMALL_BIRD;
	birdBornItem.bornTime		=	ORANGE_SMALL_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	SMALL_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 1 ]	=	birdBornItem;

	birdBornItem.birdType		=	WHITE_SMALL_BIRD;
	birdBornItem.bornTime		=	WHITE_SMALL_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	SMALL_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 2 ]	=	birdBornItem;

	birdBornItem.birdType		=	RED_SMALL_BIRD;
	birdBornItem.bornTime		=	RED_SMALL_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	SMALL_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 3 ]	=	birdBornItem;

	birdBornItem.birdType		=	BLACK_MID_BIRD;
	birdBornItem.bornTime		=	BLACK_MID_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	MID_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 4 ]	=	birdBornItem;

	birdBornItem.birdType		=	CARAMEL_MID_BIRD;
	birdBornItem.bornTime		=	CARAMEL_MID_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	MID_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 5 ]	=	birdBornItem;

	birdBornItem.birdType		=	GREEN_MID_BIRD;
	birdBornItem.bornTime		=	GREEN_MID_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	MID_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 6 ]	=	birdBornItem;

	birdBornItem.birdType		=	ICE_MID_BIRD;
	birdBornItem.bornTime		=	GREEN_MID_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	MID_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 7 ]	=	birdBornItem;

	birdBornItem.birdType		=	YELLOW_MID_BIRD;
	birdBornItem.bornTime		=	YELLOW_MID_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	MID_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 8 ]	=	birdBornItem;

	birdBornItem.birdType		=	BROWN_BIG_BIRD;
	birdBornItem.bornTime		=	BROWN_BIG_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	BIG_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 9 ]	=	birdBornItem;

	birdBornItem.birdType		=	WHITE_BIG_BIRD;
	birdBornItem.bornTime		=	WHITE_BIG_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	BIG_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 10 ]	=	birdBornItem;

	birdBornItem.birdType		=	PINK_BIG_BIRD;
	birdBornItem.bornTime		=	PINK_BIG_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	BIG_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 11 ]	=	birdBornItem;

	birdBornItem.birdType		=	ITEM_KING_BIRD;
	birdBornItem.bornTime		=	ITEM_KING_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	ITEM_KING_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 12 ]	=	birdBornItem;

	birdBornItem.birdType		=	RED_OLD_BIRD;
	birdBornItem.bornTime		=	RED_OLD_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	OLD_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 13 ]	=	birdBornItem;

	birdBornItem.birdType		=	GREEN_OLD_BIRD;
	birdBornItem.bornTime		=	GREEN_OLD_BIRD_BORN_TIME;
	birdBornItem.bornCoolTime	=	OLD_BIRD_COOLTIME;
	m_BirdBornCheckArray[ 14 ]	=	birdBornItem;

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

	if( !m_Character->GetPauseKey() )
	{
		NNScene::Update( dTime );
		UIUpdate( dTime );
	}
	else
	{
		m_PauseTime += dTime;
		m_Character->Update( dTime );
	}
	

	m_SumTime += dTime;
	
	for( int i=0; i<BIRD_ALL_NUMBER; ++i )
	{
		if( m_SumTime >= m_BirdBornCheckArray[ i ].bornTime )
		{
			NNBirdFactory::GetInstance()->MakeBird( m_BirdBornCheckArray[ i ].birdType );
			m_BirdBornCheckArray[ i ].bornTime += m_BirdBornCheckArray[ i ].bornCoolTime;
		}
	}

// 	if( m_SumTime <= TIME_LEVEL_00 )
//  	{
//  		NNBirdFactory::GetInstance()->MakeBird( BLACK_SMALL_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( ORANGE_SMALL_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( WHITE_SMALL_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( RED_SMALL_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( BLACK_MID_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( CARAMEL_MID_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( GREEN_MID_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( ICE_MID_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( YELLOW_MID_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( BROWN_BIG_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( WHITE_BIG_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( PINK_BIG_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( ITEM_KING_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( RED_OLD_BIRD );
// 		NNBirdFactory::GetInstance()->MakeBird( GREEN_OLD_BIRD );
// 		m_SumTime = 0;
//  	}
	
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

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"TIME : %0.1f sec", NNApplication::GetInstance()->GetElapsedTime() - m_PauseTime);
	m_PlayTimeLabel->SetString(m_PlayTimeString);

	swprintf_s(m_LandedPooString, _countof(m_LandedPooString), L"POLLUTION : %d ", NNPooManager::GetInstance()->GetLandedPoo());
	m_LandedPooLabel->SetString(m_LandedPooString);

	swprintf_s(m_FPSString, _countof(m_FPSString), L"FPS : %0.1f ", NNApplication::GetInstance()->GetFPS());
	m_FPSLabel->SetString(m_FPSString);
}