#include "NNPlayerCharacter.h"
#include "BHDefine.h"
#include "NNBulletManager.h"
#include "NNInputSystem.h"
#include "NNSpriteAtlas.h"
#include "NNAnimation.h"

NNPlayerCharacter::NNPlayerCharacter(void): isLeft(false), isAttack(false)
{
	m_PlayerSpeed	= INIT_PLAYERSPEED;

	PCAnimationInit();

	m_pCharTop = m_StandingTopR;

	m_SpriteHeight	=	PLAYER_HEIGHT;
	m_SpriteWidth	=	PLAYER_WIDTH;

	SetPosition	( PLAYER_POSITION_X -  4, PLAYER_POSITION_Y - 25 );
	SetZindex	( PLAYER_ZINDEX + 1 );
	m_SumTime = 0;
	m_PauseKey = false;

	AddChild(m_pCharTop);
}

NNPlayerCharacter::~NNPlayerCharacter(void)
{

}

void NNPlayerCharacter::Update( float dTime )
{
	NNPoint wich = GetPosition();

	if( !m_PauseKey )
	{
		m_pCharTop->Update(dTime);
		switch( NNInputSystem::GetInstance()->CheckWhichPressedKey() )
		{
		case LEFT_GOING_ATTACK:
			RemoveChild( m_pCharTop, false );
			m_NormalShotL =  NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_L_00, NORMAL_SHOT_L_01, NORMAL_SHOT_L_02, NORMAL_SHOT_L_03, 
				NORMAL_SHOT_L_04, NORMAL_SHOT_L_05, NORMAL_SHOT_L_06, NORMAL_SHOT_L_07, NORMAL_SHOT_L_08, NORMAL_SHOT_L_09);
			m_NormalShotL->SetLoop(false); 
			m_pCharTop = m_NormalShotL;
			AddChild(m_pCharTop);
			break;

		case RIGHT_GOING_ATTACK:
			RemoveChild( m_pCharTop, false );
			m_NormalShotR = NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_R_00, NORMAL_SHOT_R_01, NORMAL_SHOT_R_02, NORMAL_SHOT_R_03, 
				NORMAL_SHOT_R_04, NORMAL_SHOT_R_05, NORMAL_SHOT_R_06, NORMAL_SHOT_R_07, NORMAL_SHOT_R_08, NORMAL_SHOT_R_09);
			m_NormalShotR->SetLoop( false );
			m_pCharTop = m_NormalShotR;
			AddChild(m_pCharTop);
			break;

		case LEFT:
			if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR)
			{
				isAttack = false;
				RemoveChild(m_pCharTop, false);
				m_pCharTop = m_RunningTopL;
				AddChild(m_pCharTop);
			}
			isLeft = true;

			if( GetPositionX() - m_PlayerSpeed * dTime >= WINDOW_WIDTH_LEFT_EDGE )
				SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );
			break;

		case RIGHT:
			if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL )
			{
				isAttack = false;
				RemoveChild(m_pCharTop, false);
				m_pCharTop = m_RunningTopR;
				AddChild(m_pCharTop);
			}

			isLeft = false;

			if( GetPositionX() + m_PlayerSpeed * dTime <= WINDOW_WIDTH_RIGHT_EDGE - PLAYER_WIDTH )
				SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
			break;

		
		case NONE:
			isAttack = false;
			if (m_pCharTop->IsAnimationEnded())
			{
				RemoveChild(m_pCharTop, false);
				if (isLeft)
				{
					m_pCharTop = m_StandingTopL;
				}
				else
				{
					m_pCharTop = m_StandingTopR;
				}
				AddChild(m_pCharTop);
			}
			break;
		default:
			break;
		}

		NNPoint bulletPos;

		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACK:
			RemoveChild(m_pCharTop, false);
			if (isLeft)
			{
				m_NormalShotL =  NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_L_00, NORMAL_SHOT_L_01, NORMAL_SHOT_L_02, NORMAL_SHOT_L_03, 
					NORMAL_SHOT_L_04, NORMAL_SHOT_L_05, NORMAL_SHOT_L_06, NORMAL_SHOT_L_07, NORMAL_SHOT_L_08, NORMAL_SHOT_L_09);
				m_NormalShotL->SetLoop( false );
				m_pCharTop = m_NormalShotL;
			}
			else
			{
				m_NormalShotR = NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_R_00, NORMAL_SHOT_R_01, NORMAL_SHOT_R_02, NORMAL_SHOT_R_03, 
									NORMAL_SHOT_R_04, NORMAL_SHOT_R_05, NORMAL_SHOT_R_06, NORMAL_SHOT_R_07, NORMAL_SHOT_R_08, NORMAL_SHOT_R_09);
 				m_NormalShotR->SetLoop( false );
				m_pCharTop = m_NormalShotR;
			}
			
			AddChild(m_pCharTop);

			bulletPos = GetPosition();
			if( isLeft )
				bulletPos.SetX( bulletPos.GetX() + 20 );

			NNBulletManager::GetInstance()->MakeBullet( NORMAL_BULLET, bulletPos );
			isAttack = true;
			break;

		case ITEM1:
			break;

		case ITEM2:
			break;

		default:
			break;
		}

	}

	if( NNInputSystem::GetInstance()->CheckSpecialPressedKey() == PAUSE )
		( m_PauseKey == true ) ? m_PauseKey = false : m_PauseKey = true;
}

void NNPlayerCharacter::PCAnimationInit( void )
{
	m_StandingTopR = NNAnimation::Create(0.2f, 60,100, 6, PLAYER_STAND_TOP_R_00, PLAYER_STAND_TOP_R_01, 
		PLAYER_STAND_TOP_R_02, PLAYER_STAND_TOP_R_03, PLAYER_STAND_TOP_R_02, PLAYER_STAND_TOP_R_01);
	m_StandingTopR->SetLoop(true);

	m_StandingTopL = NNAnimation::Create(0.2f, 60,100,6, PLAYER_STAND_TOP_L_00, PLAYER_STAND_TOP_L_01, 
		PLAYER_STAND_TOP_L_02, PLAYER_STAND_TOP_L_03,PLAYER_STAND_TOP_L_02, PLAYER_STAND_TOP_L_01);
	m_StandingTopR->SetLoop(true);

	m_RunningTopR = NNAnimation::Create(0.2f, 60,100,6, PLAYER_RUN_TOP_R_00, PLAYER_RUN_TOP_R_01, 
		PLAYER_RUN_TOP_R_02, PLAYER_RUN_TOP_R_03, PLAYER_RUN_TOP_R_04, PLAYER_RUN_TOP_R_05);
	m_RunningTopR->SetLoop(true);

	m_RunningTopL = NNAnimation::Create(0.2f, 60,100,6, PLAYER_RUN_TOP_L_00, PLAYER_RUN_TOP_L_01, 
		PLAYER_RUN_TOP_L_02, PLAYER_RUN_TOP_L_03, PLAYER_RUN_TOP_L_04, PLAYER_RUN_TOP_L_05);
	m_RunningTopL->SetLoop(true);
}
