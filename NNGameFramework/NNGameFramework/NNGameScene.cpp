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
#include "NNSoundManager.h"
#include "NNStartScene.h"
#include "NNPlayerCharacterBottom.h"
#include "NNAnimation.h"

NNGameScene::NNGameScene(void ) : m_CheckGameStart(false), m_CheckBgmStarted(false), 
	m_CheckElapsedTenSec(false), m_CheckElapsedHundredSec(false), m_AppearTime(0)
{
	m_CheckGameOver = false;
	m_Character = new NNPlayerCharacter();
	m_CharacterBottom = new NNPlayerCharacterBottom();

	m_PauseTime	= 0;
	m_SumTime = 0;
	m_GameSceneStartTime	=	NNApplication::GetInstance()->GetElapsedTime();	

	m_CheckLodingAddChild = false;
	m_CheckPlayingAddChild = false;

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
	
	//AddChild( m_Character );
	//AddChild( m_CharacterBottom);
	
	//AddChild( NNPooManager::GetInstance() );
	//AddChild( NNBulletManager::GetInstance() );
	//AddChild( NNBirdFactory::GetInstance() );
	//AddChild( NNEffectManager::GetInstance() );
	//AddChild( NNSoundManager::GetInstance() );

	UIInit();
	NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_SystemSound[GAMESTART]);

	m_PlayerCharacterAppear	=	NNAnimation::Create(7,
						PLAYERCHARACTER_APPEAR_SPRITE1, 
						PLAYERCHARACTER_APPEAR_SPRITE2, 
						PLAYERCHARACTER_APPEAR_SPRITE3,
						PLAYERCHARACTER_APPEAR_SPRITE4,
						PLAYERCHARACTER_APPEAR_SPRITE5,
						PLAYERCHARACTER_APPEAR_SPRITE6,
						PLAYERCHARACTER_APPEAR_SPRITE7
						);
	m_PlayerCharacterAppear->SetScale( 1.8f, 1.8f );
	m_PlayerCharacterAppear->SetPosition( PLAYER_POSITION_X - 10.f, PLAYER_POSITION_Y - 350.f );
	m_PlayerCharacterAppear->SetFrameTime( PLAYERCHARACTER_APPEAR_FPS );
	AddChild( m_PlayerCharacterAppear );


}

void NNGameScene::UIInit()
{
	m_ElapsedPlayTimeLabel = NNLabel::Create
		(L"0.0", L"Feast of Flesh BB", 25.f, 0xAE3011);
	m_ElapsedPlayTimeLabel->SetPosition(725.f, 380.f);
	m_ElapsedPlayTimeLabel->SetZindex(0);
	//AddChild(m_ElapsedPlayTimeLabel);

	m_LandedPoo1 = NNSprite::Create(NORMAL_POO_SPRITE);
	m_LandedPoo1->SetPosition(675.f, 273.f);
	m_LandedPoo1->SetZindex(0);
	m_LandedPoo1->SetImageWidth(32.f);
	m_LandedPoo1->SetImageHeight(27.f);
	m_LandedPoo1->SetVisible(false);
	m_LandedPoo1->SetRotation(-11.f);
	AddChild(m_LandedPoo1);

	m_LandedPoo2 = NNSprite::Create(NORMAL_POO_SPRITE);
	m_LandedPoo2->SetPosition(711.f, 267.f);
	m_LandedPoo2->SetZindex(0);
	m_LandedPoo2->SetImageWidth(32.f);
	m_LandedPoo2->SetImageHeight(27.f);
	m_LandedPoo2->SetVisible(false);
	m_LandedPoo2->SetRotation(-11.f);
	AddChild(m_LandedPoo2);

	m_LandedPoo3 = NNSprite::Create(NORMAL_POO_SPRITE);
	m_LandedPoo3->SetPosition(745.f, 261.f);
	m_LandedPoo3->SetZindex(0);
	m_LandedPoo3->SetImageWidth(32.f);
	m_LandedPoo3->SetImageHeight(27.f);
	m_LandedPoo3->SetVisible(false);
	m_LandedPoo3->SetRotation(-11.f);
	AddChild(m_LandedPoo3);

	m_FPSLabel = NNLabel::Create(L"FPS : ", L"¸¼Àº °íµñ", 15.f);
	m_FPSLabel->SetPosition(670.f, 1.f);
	m_FPSLabel->SetZindex(3);
	AddChild(m_FPSLabel);

	m_AmmoLabel = NNLabel::Create(L"Ready", L"Feast of Flesh BB", 30.f, 148, 84, 14);
	m_AmmoLabel->SetPosition(685.f, 471.f);
	m_AmmoLabel->SetZindex(3);
	//AddChild(m_AmmoLabel);
}

NNGameScene::~NNGameScene(void)
{

}

void NNGameScene::Update( float dTime )
{
	NNSoundManager::GetInstance()->Update(dTime);
	if( m_SumTime >= PLAYERCHARACTER_APPEAR_FPS * PLAYERCHARACTER_APPEAR_NUMBER && m_CheckPlayingAddChild == false )
	{
		RemoveChild( m_PlayerCharacterAppear, true );

		AddChild( m_Character );
		AddChild( m_CharacterBottom);

		AddChild( NNPooManager::GetInstance() );
		AddChild( NNBulletManager::GetInstance() );
		AddChild( NNBirdFactory::GetInstance() );
		AddChild( NNEffectManager::GetInstance() );
		AddChild(m_ElapsedPlayTimeLabel);
		AddChild(m_AmmoLabel);

		m_CheckPlayingAddChild = true;
		m_AppearTime = m_SumTime;
	}

	if (m_CheckGameStart == false)
	{
		NNSoundManager::GetInstance()->PlayAndGetChannel(
			NNSoundManager::GetInstance()->SE_SystemSound[GAMEBGM],
			&NNSoundManager::GetInstance()->m_BgmChannel);
		NNSoundManager::GetInstance()->Pause(NNSoundManager::GetInstance()->m_BgmChannel);
		m_CheckGameStart = true;
	}

	if (m_CheckBgmStarted == false && (NNApplication::GetInstance()->GetElapsedTime() - 
		m_PauseTime - m_AppearTime - m_GameSceneStartTime) >= 2.5f)
	{
		NNSoundManager::GetInstance()->Resume(NNSoundManager::GetInstance()->m_BgmChannel);
		m_CheckBgmStarted = true;
	}

	if( NNPooManager::GetInstance()->HitCheckByPlayer( m_Character ) )
	{ 
		m_CheckGameOver = true;

		m_GameOver = NNSprite::Create( GAMEOVER_SPRITE );
		m_GameOver->SetZindex( GAMEOVER_ZINDEX );
		m_GameOver->SetImageHeight( 200.f );
		m_GameOver->SetImageWidth( 600.f );
		m_GameOver->SetPosition( 100.f, 200.f );
		AddChild( m_GameOver );
		
		m_CheckGameOver = true;
	

		FMOD::Channel* m_gameoverCh = nullptr;
		NNSoundManager::GetInstance()->PlayAndGetChannel(NNSoundManager::GetInstance()->SE_SystemSound[GAMEOVER], &m_gameoverCh);
		NNSoundManager::GetInstance()->SetVolume(m_gameoverCh, 1);
		NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_BgmChannel);
		
		return;
	}

	if( !m_Character->GetPauseKey() )
	{
		NNScene::Update( dTime );
		UIUpdate( dTime );
		if (m_CheckBgmStarted == true)
		{
			NNSoundManager::GetInstance()->Resume(NNSoundManager::GetInstance()->m_BgmChannel);
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
	}
	else
	{
		m_PauseTime += dTime;
		m_Character->Update( dTime );
		NNSoundManager::GetInstance()->Pause(NNSoundManager::GetInstance()->m_BgmChannel);
	}
}

void NNGameScene::Render()
{
	NNScene::Render();
}

void NNGameScene::UIUpdate( float dTime )
{
	if ((NNApplication::GetInstance()->GetElapsedTime() - 
		m_PauseTime - m_AppearTime - m_GameSceneStartTime) > 9.9f &&
		m_CheckElapsedTenSec == false)
	{
		//NNApplication::GetInstance()->SetElapsedTime(93.f);
		m_ElapsedPlayTimeLabel->SetPosition
			(m_ElapsedPlayTimeLabel->GetPositionX()-8.5f, 
			m_ElapsedPlayTimeLabel->GetPositionY());
		m_CheckElapsedTenSec = true;
	}
	if ((NNApplication::GetInstance()->GetElapsedTime() - 
		m_PauseTime - m_AppearTime - m_GameSceneStartTime) > 99.9f &&
		m_CheckElapsedHundredSec == false)
	{
		m_ElapsedPlayTimeLabel->SetPosition
			(m_ElapsedPlayTimeLabel->GetPositionX()-8.5f, 
			m_ElapsedPlayTimeLabel->GetPositionY());
		m_CheckElapsedHundredSec = true;
	}

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"%0.1f", 
		NNApplication::GetInstance()->GetElapsedTime() - 
		m_PauseTime - m_AppearTime - m_GameSceneStartTime );

	m_ElapsedPlayTimeLabel->SetString(m_PlayTimeString);

	if (NNPooManager::GetInstance()->GetLandedPoo() > POLLUTION_WARNING_LV_01)
	{
		m_LandedPoo1->SetVisible(true);
	}
	if (NNPooManager::GetInstance()->GetLandedPoo() > POLLUTION_WARNING_LV_02)
	{
		m_LandedPoo2->SetVisible(true);
	}
	if (NNPooManager::GetInstance()->GetLandedPoo() > POLLUTION_WARNING_LV_03)
	{
		m_LandedPoo3->SetVisible(true);
	}

	swprintf_s(m_FPSString, _countof(m_FPSString), L"FPS : %0.1f ",
		NNApplication::GetInstance()->GetFPS());

	m_FPSLabel->SetString(m_FPSString);

	swprintf_s(m_AmmoString, _countof(m_AmmoString), L"%d",
		NNBulletManager::GetInstance()->GetAmmoLeft());

	m_AmmoLabel->SetString(m_AmmoString);
}