#include "NNPlayerCharacterBottom.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"
#include "NNSpriteAtlas.h"
#include "NNAnimation.h"

NNPlayerCharacterBottom::NNPlayerCharacterBottom(void): m_SumTime(0), m_PauseKey(false), isLeft(false)
{
	PCAnimationInit();
	m_PlayerSpeed	= INIT_PLAYERSPEED;
	m_pCharBottom = m_StandingBottomR;

	m_SpriteHeight	=	PLAYER_HEIGHT;
	m_SpriteWidth	=	PLAYER_WIDTH;

	SetPosition	( PLAYER_POSITION_X, PLAYER_POSITION_Y + 52.f);
	SetZindex	( PLAYER_ZINDEX );
	AddChild(m_pCharBottom);
}


NNPlayerCharacterBottom::~NNPlayerCharacterBottom(void)
{
}

void NNPlayerCharacterBottom::Update( float dTime )
{
	
	NNPoint wich = GetPosition();

	if( !m_PauseKey )
	{
		m_pCharBottom->Update(dTime);
		switch( NNInputSystem::GetInstance()->CheckWhichPressedKey() )
		{
		case LEFT:
			RemoveChild(m_pCharBottom, false);
			m_pCharBottom = m_RunningBottomL;
			
			AddChild(m_pCharBottom);

			if (isLeft == false)
			{
				SetPosition(GetPositionX() + 15.f, GetPositionY());
				isLeft = true;
			}
			
			if( GetPositionX() - m_PlayerSpeed * dTime >= WINDOW_WIDTH_LEFT_EDGE + 20 )
				SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );
			break;

		case RIGHT:
			RemoveChild(m_pCharBottom, false);
			m_pCharBottom = m_RunningBottomR;
			AddChild(m_pCharBottom);

			if (isLeft)
			{
				SetPosition(GetPositionX() - 15.f, GetPositionY());
				isLeft = false;
			}
			if( GetPositionX() + m_PlayerSpeed * dTime <= WINDOW_WIDTH_RIGHT_EDGE - PLAYER_WIDTH )
				SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
			break;

		case NONE:
			RemoveChild(m_pCharBottom, false);
			if (isLeft)
			{
				m_pCharBottom = m_StandingBottomL;
			}
			else
			{
				m_pCharBottom = m_StandingBottomR;
			}
			AddChild(m_pCharBottom);
		default:
			break;
		}

		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACK: 
			break;

		case ITEM1:
			break;

		case ITEM2:
			break;

		default:
			break;
		}
	}
}

void NNPlayerCharacterBottom::PCAnimationInit( void )
{
	m_StandingBottomR = NNAnimation::Create(0.2f, 34, 34, 1, PLAYER_STAND_BOTTOM_R);
	m_StandingBottomL = NNAnimation::Create(0.2f, 34, 34, 1, PLAYER_STAND_BOTTOM_L);

	m_RunningBottomR = NNAnimation::Create(0.1f, 43, 36,6, PLAYER_RUN_BOTTOM_R_00, PLAYER_RUN_BOTTOM_R_01, 
		PLAYER_RUN_BOTTOM_R_02, PLAYER_RUN_BOTTOM_R_03, PLAYER_RUN_BOTTOM_R_04, PLAYER_RUN_BOTTOM_R_05);
	m_RunningBottomR->SetLoop(true);

	m_RunningBottomL = NNAnimation::Create(0.1f, 43, 36, 6, PLAYER_RUN_BOTTOM_L_00, PLAYER_RUN_BOTTOM_L_01, 
		PLAYER_RUN_BOTTOM_L_02, PLAYER_RUN_BOTTOM_L_03, PLAYER_RUN_BOTTOM_L_04, PLAYER_RUN_BOTTOM_L_05);
	m_RunningBottomL->SetLoop(true);

// 	m_StandingBottomR = NNAnimation::Create(1, PLAYER_STAND_BOTTOM_R);
// 	m_StandingBottomL = NNAnimation::Create(1, PLAYER_STAND_BOTTOM_L);
// 
// 	m_RunningBottomR = NNAnimation::Create(6, PLAYER_RUN_BOTTOM_R_00, PLAYER_RUN_BOTTOM_R_01, 
// 		PLAYER_RUN_BOTTOM_R_02, PLAYER_RUN_BOTTOM_R_03, PLAYER_RUN_BOTTOM_R_04, PLAYER_RUN_BOTTOM_R_05);
// 	m_RunningBottomR->SetLoop(true);
// 	m_RunningBottomR->SetFrameTime(0.1f);
// 
// 	m_RunningBottomL = NNAnimation::Create(6, PLAYER_RUN_BOTTOM_L_00, PLAYER_RUN_BOTTOM_L_01, 
// 		PLAYER_RUN_BOTTOM_L_02, PLAYER_RUN_BOTTOM_L_03, PLAYER_RUN_BOTTOM_L_04, PLAYER_RUN_BOTTOM_L_05);
// 	m_RunningBottomL->SetLoop(true);
// 	m_RunningBottomL->SetFrameTime(0.1f);
}

bool NNPlayerCharacterBottom::IsLeft()
{
	if( isLeft )
		return true;
	return false;
}
