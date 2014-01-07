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
#include "NNItemManager.h"
#include "NNItem.h"
#include "NNGameOver.h"

NNGameScene::NNGameScene(void ) : m_CheckGameStart(false), m_CheckBgmStarted(false), 
	m_CheckElapsedTenSec(false), m_CheckElapsedHundredSec(false), m_AppearTime(0), m_GameOverPooSpeed(100.f), m_GameOverPooAccelSpeed(0.5f), m_CheckPollutionMax(false), m_CheckGameOverByPollution(false)
{
	//NNPooManager::GetInstance()->SetLandedPoo(100);
	m_CheckGameOver = false;
	m_CharacterBottom = new NNPlayerCharacterBottom();
	m_Character = new NNPlayerCharacter();
	

	//m_Shield = NNAnimation::Create(0.2f, 50.f, 8.f, 1, SHIELD_SPRITE);
	//m_Shield = NNAnimation::Create(0.2f, 70.f, 18.f, 1, SHIELD_SPRITE);
	m_Shield = NNAnimation::Create(0.1f, 100.f, 100.f, 9, SHIELD_SPRITE_00, SHIELD_SPRITE_01, SHIELD_SPRITE_02, SHIELD_SPRITE_03, SHIELD_SPRITE_04, SHIELD_SPRITE_05, SHIELD_SPRITE_06, SHIELD_SPRITE_07, SHIELD_SPRITE_08);
	m_Shield->SetVisible(false);
	m_Shield->SetZindex(5);
	AddChild(m_Shield);

	m_GameOverPoo = NNAnimation::Create(0.05f, 100.f, 100.f, 11, BLACK_SMALL_BIRD_POO_SPRITE, ORANGE_SMALL_BIRD_POO_SPRITE, WHITE_SMALL_BIRD_POO_SPRITE, RED_SMALL_BIRD_POO_SPRITE, CARAMEL_MID_BIRD_POO_SPRITE, GREEN_MID_BIRD_POO_SPRITE, ICE_MID_BIRD_POO_SPRITE, YELLOW_MID_BIRD_POO_SPRITE, BROWN_BIG_BIRD_POO_SPRITE, PINK_BIG_BIRD_POO_SPRITE, ITEM_KING_BIRD_POO_SPRITE);
	m_GameOverPoo->SetVisible(false);
	m_GameOverPoo->SetZindex(2);
	m_GameOverPoo->SetPosition(350.f, -100.f);
	AddChild(m_GameOverPoo);

	m_GameOverExplosion = NNAnimation::Create(0.1f, 400.f, 400.f, 15, GAMEOVER_EXPLOSION_00, GAMEOVER_EXPLOSION_01, GAMEOVER_EXPLOSION_02, GAMEOVER_EXPLOSION_03, GAMEOVER_EXPLOSION_04, GAMEOVER_EXPLOSION_05, GAMEOVER_EXPLOSION_06, GAMEOVER_EXPLOSION_07, GAMEOVER_EXPLOSION_08, GAMEOVER_EXPLOSION_09, GAMEOVER_EXPLOSION_10, GAMEOVER_EXPLOSION_11, GAMEOVER_EXPLOSION_12, GAMEOVER_EXPLOSION_13, GAMEOVER_EXPLOSION_14);
	m_GameOverExplosion->SetPosition(200.f, WINDOW_HEIGHT_DOWN_EDGE - 440);
	m_GameOverExplosion->SetLoop(false);
	m_GameOverExplosion->SetVisible(false);
	m_GameOverExplosion->SetZindex(6);
	AddChild(m_GameOverExplosion);

	m_PauseTime	= 0;
	m_SumTime = 0;
	m_GameSceneStartTime	=	NNApplication::GetInstance()->GetElapsedTime();	

	m_CheckLodingAddChild = false;
	m_CheckPlayingAddChild = false;
	m_DieEndCheck = false;

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

	
	//AddChild( NNMapManager::GetInstance() );
	
	m_ChangeGameOVerTime = 0.f;

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
	/////////////////////////////////////////////////
	m_PlayerCharacterRightDie	=	NNAnimation::Create(PLAYERCHARACTER_RIGHT_DIE_NUMBER,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE1, 
		PLAYERCHARACTER_RIGHT_DIE_SPRITE2,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE3,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE4,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE5,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE6,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE7, 
		PLAYERCHARACTER_RIGHT_DIE_SPRITE8, 
		PLAYERCHARACTER_RIGHT_DIE_SPRITE9,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE10,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE11,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE12,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE13,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE14, 
		PLAYERCHARACTER_RIGHT_DIE_SPRITE15,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE16,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE17,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE18,
		PLAYERCHARACTER_RIGHT_DIE_SPRITE19
		);

	m_PlayerCharacterRightDie->SetScale( 1.8f, 1.8f );
	m_PlayerCharacterRightDie->SetFrameTime( PLAYERCHARACTER_RIGHT_DIE_FPS );
	m_PlayerCharacterRightDie->SetLoop( false );

	m_PlayerCharacterLeftDie	=	NNAnimation::Create(PLAYERCHARACTER_LEFT_DIE_NUMBER,
		PLAYERCHARACTER_LEFT_DIE_SPRITE1, 
		PLAYERCHARACTER_LEFT_DIE_SPRITE2,
		PLAYERCHARACTER_LEFT_DIE_SPRITE3,
		PLAYERCHARACTER_LEFT_DIE_SPRITE4,
		PLAYERCHARACTER_LEFT_DIE_SPRITE5,
		PLAYERCHARACTER_LEFT_DIE_SPRITE6,
		PLAYERCHARACTER_LEFT_DIE_SPRITE7, 
		PLAYERCHARACTER_LEFT_DIE_SPRITE8, 
		PLAYERCHARACTER_LEFT_DIE_SPRITE9,
		PLAYERCHARACTER_LEFT_DIE_SPRITE10,
		PLAYERCHARACTER_LEFT_DIE_SPRITE11,
		PLAYERCHARACTER_LEFT_DIE_SPRITE12,
		PLAYERCHARACTER_LEFT_DIE_SPRITE13,
		PLAYERCHARACTER_LEFT_DIE_SPRITE14, 
		PLAYERCHARACTER_LEFT_DIE_SPRITE15,
		PLAYERCHARACTER_LEFT_DIE_SPRITE16,
		PLAYERCHARACTER_LEFT_DIE_SPRITE17,
		PLAYERCHARACTER_LEFT_DIE_SPRITE18,
		PLAYERCHARACTER_LEFT_DIE_SPRITE19
		);

	m_PlayerCharacterLeftDie->SetScale( 1.8f, 1.8f );
	m_PlayerCharacterLeftDie->SetFrameTime( PLAYERCHARACTER_LEFT_DIE_FPS );
	m_PlayerCharacterLeftDie->SetLoop( false );
	
	m_LeftEndPlayerSprite = NNSprite::Create( PLAYERCHARACTER_LEFT_DIE_SPRITE19 );
	m_RightEndPlayerSprite     =                                                                  NNSprite::Create( PLAYERCHARACTER_RIGHT_DIE_SPRITE19 );
	
	m_LeftEndPlayerSprite->SetScale( 1.8f, 1.8f );
	m_RightEndPlayerSprite->SetScale( 1.8f, 1.8f );

	m_LeftEndPlayerSprite->SetZindex( 5 );
	m_RightEndPlayerSprite->SetZindex( 5 );

	m_LeftEndPlayerSprite->SetVisible( false );
	m_RightEndPlayerSprite->SetVisible( false );

	AddChild( m_LeftEndPlayerSprite );
	AddChild( m_RightEndPlayerSprite );

	
}

void NNGameScene::UIInit()
{
	m_SkillFirstBar		=	NNSprite::Create(SKILL_FIRST_BAR);
	m_SkillSecondBar	=	NNSprite::Create(SKILL_SECOND_BAR);
	m_SkillFirstBar->SetImageWidth( 80 );
	m_SkillSecondBar->SetImageWidth( 80 );
	m_SkillFirstBar->SetPosition(710.f, 471.f);
	m_SkillSecondBar->SetPosition(710.f, 471.f);
	AddChild(m_SkillFirstBar);
	AddChild(m_SkillSecondBar);

	/////////아이템 스프라이트 늘어나면 디파인 처리 할 것.
	m_ItemSprite[0]=NNSprite::Create( NORMALGUN );
	m_ItemSprite[0]->SetPosition( 673.f, 471.f );

	m_ItemSprite[1]=NNSprite::Create( DUALGUN );
	m_ItemSprite[1]->SetPosition( 673.f, 471.f );
	
	m_ItemSprite[2]=NNSprite::Create( FIREGUN );
	m_ItemSprite[2]->SetPosition( 673.f, 471.f );

	m_ItemSprite[3]=NNSprite::Create( SHOTGUN );
	m_ItemSprite[3]->SetPosition( 673.f, 471.f );

	m_ItemSprite[4]=NNSprite::Create( SHIELD );
	m_ItemSprite[4]->SetPosition( 673.f, 471.f );

	for(int i=0; i<5; ++i )
	{
		m_ItemSprite[i]->SetImageWidth( 30 );
		m_ItemSprite[i]->SetImageHeight( 30 );
		m_ItemSprite[i]->SetVisible(true);
		//AddChild( m_ItemSprite[i] );
	}
	m_ItemSprite[1]->SetScale(1.3f,1.3f);
	m_ItemSprite[2]->SetScale(0.8f,0.8f);
	m_ItemGunSprite=m_ItemSprite[0];
	m_ItemGunSprite->SetVisible(true);
	AddChild(m_ItemGunSprite);
	/////////////////////////////////
	
	
	m_ElapsedPlayTimeLabel = NNLabel::Create
		(L"0.0", L"Feast of Flesh BB", 25.f, 0xAE3011);
	m_ElapsedPlayTimeLabel->SetPosition(725.f, 380.f);
	m_ElapsedPlayTimeLabel->SetZindex(0);
	AddChild(m_ElapsedPlayTimeLabel);

	m_LandedPoo1 = NNAnimation::Create(0.2f, 32.f, 27.f, 1, NORMAL_POO_SPRITE);
	m_LandedPoo1->SetPosition(675.f, 273.f);
	m_LandedPoo1->SetZindex(0);
	m_LandedPoo1->SetVisible(false);
	m_LandedPoo1->SetRotation(-11.f);
	AddChild(m_LandedPoo1);

	m_LandedPoo2 = NNAnimation::Create(0.2f, 32.f, 27.f, 1, NORMAL_POO_SPRITE);
	m_LandedPoo2->SetPosition(711.f, 267.f);
	m_LandedPoo2->SetZindex(0);
	m_LandedPoo2->SetVisible(false);
	m_LandedPoo2->SetRotation(-11.f);
	AddChild(m_LandedPoo2);

	m_LandedPoo3 = NNAnimation::Create(0.2f, 32.f, 27.f, 1, NORMAL_POO_SPRITE);
	m_LandedPoo3->SetPosition(745.f, 261.f);
	m_LandedPoo3->SetZindex(0);
	m_LandedPoo3->SetVisible(false);
	m_LandedPoo3->SetRotation(-11.f);
	AddChild(m_LandedPoo3);


	m_FPSLabel = NNLabel::Create(L"FPS : ", L"맑은 고딕", 15.f);
	m_FPSLabel->SetPosition(670.f, 1.f);
	m_FPSLabel->SetZindex(3);
	AddChild(m_FPSLabel);

	m_AmmoLabel = NNLabel::Create(L"Ready", L"Feast of Flesh BB", 30.f, 148, 84, 14);
	m_AmmoLabel->SetPosition(685.f, 471.f);
	m_AmmoLabel->SetZindex(3);
}

NNGameScene::~NNGameScene(void)
{
	NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_WarningChannel);
}

void NNGameScene::Update( float dTime )
{
	//test
	


	m_Shield->SetPosition(m_Character->GetPositionX() - 22.f, m_Character->GetPositionY() + 30);

	NNSoundManager::GetInstance()->Update(dTime);

	if( m_SumTime >= PLAYERCHARACTER_APPEAR_FPS * PLAYERCHARACTER_APPEAR_NUMBER && m_CheckPlayingAddChild == false )
	{
		RemoveChild( m_PlayerCharacterAppear, true );

		AddChild( m_Character );
		AddChild( m_CharacterBottom);
		
		//AddChild( NNPooManager::GetInstance() );
		//AddChild( NNBulletManager::GetInstance() );
		//AddChild( NNBirdFactory::GetInstance() );
		//AddChild( NNEffectManager::GetInstance() );
		//AddChild( NNItemManager::GetInstance() );

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

	//오염도 MAX로 게임오버
	if (NNPooManager::GetInstance()->GetLandedPoo() >= POLLUTION_MAX)
	{
		NNPooManager::GetInstance()->RemoveAll();
		if (m_CheckPollutionMax == false )
		{
			m_CheckPollutionMax = true;
			NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_BgmChannel);
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_GameOverPooDrop);
			m_GameOverPoo->SetVisible(true);
		}
		m_GameOverPoo->SetPosition(m_GameOverPoo->GetPositionX(), m_GameOverPoo->GetPositionY() + m_GameOverPooSpeed * dTime);
		m_GameOverPooSpeed += m_GameOverPooAccelSpeed;
	}

	if ( m_CheckGameOverByPollution == false && m_GameOverPoo->GetPositionY() > WINDOW_HEIGHT_DOWN_EDGE - 140)
	{
		NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_GameOverExplosion);
		m_GameOverPoo->SetVisible(false);
		m_GameOverExplosion->SetVisible(true);
		m_CheckGameOverByPollution = true;
	}

	if (m_CheckGameOverByPollution && m_GameOverExplosion->IsAnimationEnded())
	{
		NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_WarningChannel);
		FMOD::Channel* m_gameoverCh = nullptr;
		NNSoundManager::GetInstance()->PlayAndGetChannel(NNSoundManager::GetInstance()->SE_SystemSound[GAMEOVER], &m_gameoverCh);
		
		m_ChangeGameOVerTime += dTime;

		if( m_ChangeGameOVerTime >= 3.0f)
		{
			NNMapManager::ReleaseInstance();
			NNPooManager::ReleaseInstance();
			NNBirdFactory::ReleaseInstance();
			NNBulletManager::ReleaseInstance();
			NNEffectManager::ReleaseInstance();
			NNItemManager::ReleaseInstance();
			NNSoundManager::ReleaseInstance();

			NNSceneDirector::GetInstance()->ChangeScene( new NNGameOver(NNApplication::GetInstance()->GetElapsedTime() - 
				m_PauseTime - m_AppearTime - 
				m_GameSceneStartTime, m_ChangeGameOVerTime) );
			return;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//똥에 맞고 게임오버
	if( NNPooManager::GetInstance()->HitCheckByPlayer( m_Character ) || m_CheckGameOver )
	{ 
		if( !m_CheckGameOver )
		{
			m_Character->IsGameOver();
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_Die );

			NNPoint playerPoint;
			playerPoint = m_Character->GetPosition();

			( m_Character->GetPlayerDirection() == LEFT_GO ) ? 
				m_PlayerCharacterDie = m_PlayerCharacterLeftDie :
				m_PlayerCharacterDie = m_PlayerCharacterRightDie;

				switch ( m_Character->GetAttackStatus() )
				{
				case NORMAL:
				case SHIELD_STATE:
					m_PlayerCharacterDie->SetPosition( playerPoint.GetX() + 10.f, playerPoint.GetY() + 50.f );
					break;
				case DUAL_GUN:
					m_PlayerCharacterDie->SetPosition( playerPoint.GetX() + 10.f, playerPoint.GetY() + 5 );
					break;
				case FIRE:
					m_PlayerCharacterDie->SetPosition( playerPoint.GetX() + 10.f, playerPoint.GetY() + 35 );
					break;
				case SHOT_GUN:
					m_PlayerCharacterDie->SetPosition( playerPoint.GetX() + 10.f, playerPoint.GetY() + 39 );
					break;
				default:
					break;
				}
			
			
			AddChild( m_PlayerCharacterDie );
			m_Character->SetVisible( false );
			m_CharacterBottom->SetVisible( false );
		}
		 
		if( m_PlayerCharacterDie->IsAnimationEnded() )
		{
			if( !m_DieEndCheck )
			{
				m_DieDirection =  m_Character->GetPlayerDirection();
			}

			if(m_DieDirection == LEFT_GO ) 
			{
				m_LeftEndPlayerSprite->SetVisible( true );
				m_LeftEndPlayerSprite->SetPosition( m_PlayerCharacterDie->GetPositionX(), m_PlayerCharacterDie->GetPositionY() );
			}
			else if( m_DieDirection == RIGHT_GO ) 
			{
				m_RightEndPlayerSprite->SetVisible( true );
				m_RightEndPlayerSprite->SetPosition( m_PlayerCharacterDie->GetPositionX(), m_PlayerCharacterDie->GetPositionY() );
			}

			m_PlayerCharacterDie->SetVisible( false );
			
			if (m_DieEndCheck == false)
			{
				FMOD::Channel* m_gameoverCh = nullptr;
				NNSoundManager::GetInstance()->PlayAndGetChannel(NNSoundManager::GetInstance()->SE_SystemSound[GAMEOVER], &m_gameoverCh);
				NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_BgmChannel);
				NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_WarningChannel);
				m_DieEndCheck = true;
			}
		}
		
		m_CheckGameOver = true;

		if( m_DieEndCheck ) 
		{
			m_ChangeGameOVerTime += dTime;
		}
		if( m_ChangeGameOVerTime >= 3.0f)
		{
			NNMapManager::ReleaseInstance();
			NNPooManager::ReleaseInstance();
			NNBirdFactory::ReleaseInstance();
			NNBulletManager::ReleaseInstance();
			NNEffectManager::ReleaseInstance();
			NNItemManager::ReleaseInstance();
			NNSoundManager::ReleaseInstance();

			NNSceneDirector::GetInstance()->ChangeScene( new NNGameOver(NNApplication::GetInstance()->GetElapsedTime() - 
				m_PauseTime - m_AppearTime - 
				m_GameSceneStartTime, m_ChangeGameOVerTime) );
			return;
		}
	}

	//아이템 충돌체크
	if ( NNItemManager::GetInstance()->HitCheck( m_Character) )
	{
		switch (NNItemManager::GetInstance()->GetItemType())
		{
		case ITEM_DUAL_GUN:
			m_Character->SetAttackStatus( DUAL_GUN ); 
			break;
		case ITEM_FIRE_SHOOTER:
			m_Character->SetAttackStatus( FIRE );
			break;
		case ITEM_SHOT_GUN:
			m_Character->SetAttackStatus( SHOT_GUN );
			break;
		case ITEM_CLEANER:
			NNPooManager::GetInstance()->SetLandedPoo(0);
			NNPooManager::GetInstance()->RemoveAll();
			break;
		case ITEM_SHIELD:
			m_Shield->SetVisible(true);
			m_Character->SetAttackStatus( SHIELD_STATE );
			
			break;
		case ITEM_MAX_NUM:
			break;
		default:
			break;
		}
		//m_Character->SetAttackStatus( DUAL_GUN ); 
		//m_Character->SetAttackStatus( FIRE );
	}
// 
 	if (m_Shield->IsVisible() )
	{
		NNPooManager::GetInstance()->HitCheckByShield(m_Shield);
 	//	m_Shield->SetVisible(false);
	}
	
	if( !m_Character->GetPauseKey() )
	{
		NNScene::Update( dTime );
		UIUpdate( dTime );
		NNPooManager::GetInstance()->Update( dTime );
		NNBulletManager::GetInstance()->Update( dTime );
		NNBirdFactory::GetInstance()->Update( dTime );
		NNEffectManager::GetInstance()->Update( dTime );
		NNItemManager::GetInstance()->Update( dTime );
		NNMapManager::GetInstance()->Update( dTime );
		if (m_CheckBgmStarted == true)
		{
			NNSoundManager::GetInstance()->Resume(NNSoundManager::GetInstance()->m_BgmChannel);
		}
		m_SumTime += dTime;

		if( !m_CheckGameOver )
		{
			for( int i=0; i<BIRD_ALL_NUMBER; ++i )
			{
				if( m_SumTime >= m_BirdBornCheckArray[ i ].bornTime )
				{
					NNBirdFactory::GetInstance()->MakeBird( m_BirdBornCheckArray[ i ].birdType );
					m_BirdBornCheckArray[ i ].bornTime += m_BirdBornCheckArray[ i ].bornCoolTime;
				}
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
	NNMapManager::GetInstance()->Render();
	NNScene::Render();
	NNPooManager::GetInstance()->Render();
	NNBulletManager::GetInstance()->Render();
	NNBirdFactory::GetInstance()->Render();
	NNEffectManager::GetInstance()->Render();
	NNItemManager::GetInstance()->Render();
	
}

void NNGameScene::UIUpdate( float dTime )
{
	if( m_Character->GetAttackStatus() != NORMAL )
	{
		switch( m_Character->GetAttackStatus() )
		{
		case DUAL_GUN:
			RemoveChild( m_ItemGunSprite, false );
			m_ItemGunSprite=m_ItemSprite[1];
			AddChild( m_ItemGunSprite );
			m_SkillSecondBar->SetImageWidth( m_SkillSecondBar->GetImageWidth() - dTime*( 80  / DUALGUN_RUNTIME));
			
			if(m_SkillSecondBar->GetImageWidth() - dTime*( 80  / DUALGUN_RUNTIME) < 0.f )
			{
				m_SkillSecondBar->SetImageWidth( 80 );
				m_Character->SetAttackStatus( NORMAL );

				RemoveChild( m_ItemGunSprite, false );
				m_ItemGunSprite=m_ItemSprite[0];
				AddChild( m_ItemGunSprite );
			}
			break;
		case FIRE:
			RemoveChild( m_ItemGunSprite, false );
			m_ItemGunSprite=m_ItemSprite[2];
			AddChild( m_ItemGunSprite );
			m_SkillSecondBar->SetImageWidth( m_SkillSecondBar->GetImageWidth() - dTime*( 80  / FIREGUN_RUNTIME));

			if(m_SkillSecondBar->GetImageWidth() - dTime*( 80  / FIREGUN_RUNTIME) < 0.f )
			{
				m_SkillSecondBar->SetImageWidth( 80 );
				m_Character->SetAttackStatus( NORMAL );

				RemoveChild( m_ItemGunSprite, false );
				m_ItemGunSprite=m_ItemSprite[0];
				AddChild( m_ItemGunSprite );
			}
			break;
		case SHOT_GUN:
			RemoveChild( m_ItemGunSprite, false );
			m_ItemGunSprite=m_ItemSprite[3];
			AddChild( m_ItemGunSprite );
			m_SkillSecondBar->SetImageWidth( m_SkillSecondBar->GetImageWidth() - dTime*( 80  / SHOTGUN_RUNTIME));

			if(m_SkillSecondBar->GetImageWidth() - dTime*( 80  / SHOTGUN_RUNTIME) < 0.f )
			{
				m_SkillSecondBar->SetImageWidth( 80 );
				m_Character->SetAttackStatus( NORMAL );

				RemoveChild( m_ItemGunSprite, false );
				m_ItemGunSprite=m_ItemSprite[0];
				AddChild( m_ItemGunSprite );
			}
			break;
		case SHIELD_STATE:
			RemoveChild( m_ItemGunSprite, false );
			m_ItemGunSprite=m_ItemSprite[4];
			AddChild( m_ItemGunSprite );
			m_SkillSecondBar->SetImageWidth( m_SkillSecondBar->GetImageWidth() - dTime*( 80  / SHIELD_RUNTIME));

			if(m_SkillSecondBar->GetImageWidth() - dTime*( 80  / SHIELD_RUNTIME) < 0.f )
			{
				m_SkillSecondBar->SetImageWidth( 80 );
				m_Character->SetAttackStatus( NORMAL );
				m_Shield->SetVisible(false);

				RemoveChild( m_ItemGunSprite, false );
				m_ItemGunSprite=m_ItemSprite[0];
				AddChild( m_ItemGunSprite );
			}
			break;
		default:
			break;
		}
	}
	
	if( !m_CheckGameOver )
	{
		if (m_CheckElapsedTenSec == false && 
			NNApplication::GetInstance()->GetElapsedTime() - 
			m_PauseTime - m_AppearTime - 
			m_GameSceneStartTime > 9.9f	 
			)
		{
			m_ElapsedPlayTimeLabel->SetPosition(708.f, 380.f);
			m_CheckElapsedTenSec = true;
		}

		swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"%0.1f", 
			NNApplication::GetInstance()->GetElapsedTime() - 
			m_PauseTime - m_AppearTime - m_GameSceneStartTime );

		if ((NNApplication::GetInstance()->GetElapsedTime() - 
			m_PauseTime - m_AppearTime - m_GameSceneStartTime) > 99.9f &&
			m_CheckElapsedHundredSec == false)
		{
			m_ElapsedPlayTimeLabel->SetPosition
				(m_ElapsedPlayTimeLabel->GetPositionX()-6.f, 
				m_ElapsedPlayTimeLabel->GetPositionY());
			m_CheckElapsedHundredSec = true;
		}

		m_ElapsedPlayTimeLabel->SetString(m_PlayTimeString);

		//////////////////////////////////////////////////////
		swprintf_s(m_AmmoString, _countof(m_AmmoString), L"%d",
			NNBulletManager::GetInstance()->GetAmmoLeft());

		m_AmmoLabel->SetString(m_AmmoString);

		if (NNPooManager::GetInstance()->GetLandedPoo() >= POLLUTION_WARNING_LV_01)
		{
			m_LandedPoo1->SetVisible(true);
		}
		else
		{
			m_LandedPoo1->SetVisible(false);
		}
		if (NNPooManager::GetInstance()->GetLandedPoo() >= POLLUTION_WARNING_LV_02)
		{
			m_LandedPoo2->SetVisible(true);
		}
		else
		{
			m_LandedPoo2->SetVisible(false);
		}
		if (NNPooManager::GetInstance()->GetLandedPoo() >= POLLUTION_WARNING_LV_03)
		{
			m_LandedPoo3->SetVisible(true);
		}
		else
		{
			m_LandedPoo3->SetVisible(false);
		}
	}
	swprintf_s(m_FPSString, _countof(m_FPSString), L"FPS : %0.1f ",
		NNApplication::GetInstance()->GetFPS());

	m_FPSLabel->SetString(m_FPSString);


}