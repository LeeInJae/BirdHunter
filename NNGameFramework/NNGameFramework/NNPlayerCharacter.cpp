#include "NNPlayerCharacter.h"
#include "BHDefine.h"
#include "NNBulletManager.h"
#include "NNInputSystem.h"
#include "NNSpriteAtlas.h"
#include "NNAnimation.h"

NNPlayerCharacter::NNPlayerCharacter(void): isLeft(false), isAttack(false)
{
	m_PlayerSpeed	= INIT_PLAYERSPEED;
	m_AttackStatus	=	NORMAL;

	PCAnimationInit();

	m_pCharTop = m_StandingTopR;

	m_SpriteHeight	=	PLAYER_HEIGHT;
	m_SpriteWidth	=	PLAYER_WIDTH;

	SetPosition	( PLAYER_POSITION_X -2, PLAYER_POSITION_Y - 38 );
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
		case LEFT:
			switch ( m_AttackStatus )
			{
			case NORMAL:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR
					|| m_pCharTop == m_DualGunRunningTopR ||  m_pCharTop == m_DualGunStandingTopR 
					|| m_pCharTop == m_AmorRunningTopR	|| m_pCharTop == m_AmorStandingTopR )
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

			case DUAL_GUN:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR
					|| m_pCharTop == m_DualGunRunningTopR ||  m_pCharTop == m_DualGunStandingTopR
					|| m_pCharTop == m_AmorRunningTopR	|| m_pCharTop == m_AmorStandingTopR )
				{
					isAttack = false;
					RemoveChild(m_pCharTop, false);
					m_pCharTop = m_DualGunRunningTopL;
					AddChild(m_pCharTop);
				}
				isLeft = true;

				if( GetPositionX() - m_PlayerSpeed * dTime >= WINDOW_WIDTH_LEFT_EDGE )
					SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );

				break;

			default:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR
					|| m_pCharTop == m_DualGunRunningTopR ||  m_pCharTop == m_DualGunStandingTopR
					|| m_pCharTop == m_AmorRunningTopR	|| m_pCharTop == m_AmorStandingTopR )
				{
					isAttack = false;
					RemoveChild(m_pCharTop, false);
					m_pCharTop = m_AmorRunningTopL;
					AddChild(m_pCharTop);
				}
				isLeft = true;

				if( GetPositionX() - m_PlayerSpeed * dTime >= WINDOW_WIDTH_LEFT_EDGE )
					SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );
				break;
			}
			break;

		case RIGHT:
			switch ( m_AttackStatus )
			{
			case NORMAL:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL 
					|| m_pCharTop == m_DualGunRunningTopL ||  m_pCharTop == m_DualGunStandingTopL
					|| m_pCharTop == m_AmorRunningTopL	|| m_pCharTop == m_AmorStandingTopL)
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

			case DUAL_GUN:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL 
					|| m_pCharTop == m_DualGunRunningTopL ||  m_pCharTop == m_DualGunStandingTopL
					|| m_pCharTop == m_AmorRunningTopL	|| m_pCharTop == m_AmorStandingTopL)
				{
					isAttack = false;
					RemoveChild(m_pCharTop, false);
					m_pCharTop = m_DualGunRunningTopR;
					AddChild(m_pCharTop);
				}

				isLeft = false;

				if( GetPositionX() + m_PlayerSpeed * dTime <= WINDOW_WIDTH_RIGHT_EDGE - PLAYER_WIDTH )
					SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
				break;

			default:
				if( m_pCharTop->IsAnimationEnded() || m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL 
					|| m_pCharTop == m_DualGunRunningTopL ||  m_pCharTop == m_DualGunStandingTopL
					|| m_pCharTop == m_AmorRunningTopL	|| m_pCharTop == m_AmorStandingTopL)
				{
					isAttack = false;
					RemoveChild(m_pCharTop, false);
					m_pCharTop = m_AmorRunningTopR;
					AddChild(m_pCharTop);
				}

				isLeft = false;

				if( GetPositionX() + m_PlayerSpeed * dTime <= WINDOW_WIDTH_RIGHT_EDGE - PLAYER_WIDTH )
					SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
				break;
			}

			break;

		case NONE:
			switch ( m_AttackStatus )
			{
			case NORMAL:
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
			case DUAL_GUN:
				isAttack = false;
				if (m_pCharTop->IsAnimationEnded())
				{
					RemoveChild(m_pCharTop, false);
					if (isLeft)
					{
						m_pCharTop = m_DualGunStandingTopL;
					}
					else
					{
						m_pCharTop = m_DualGunStandingTopR;
					}
					AddChild(m_pCharTop);
				}
				break;
			default:
				isAttack = false;
				if (m_pCharTop->IsAnimationEnded())
				{
					RemoveChild(m_pCharTop, false);
					if (isLeft)
					{
						m_pCharTop = m_AmorStandingTopL;
					}
					else
					{
						m_pCharTop = m_AmorStandingTopR;
					}
					AddChild(m_pCharTop);
				}
				break;
			}
			break;			
		default:
			break;
		}

		NNPoint bulletPos;

		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACK:
			switch ( m_AttackStatus )
			{
			case NORMAL:
				
				if (isLeft)
				{
					RemoveChild(m_pCharTop, false);
					m_NormalShotL =  NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_L_00, NORMAL_SHOT_L_01, NORMAL_SHOT_L_02, NORMAL_SHOT_L_03, 
						NORMAL_SHOT_L_04, NORMAL_SHOT_L_05, NORMAL_SHOT_L_06, NORMAL_SHOT_L_07, NORMAL_SHOT_L_08, NORMAL_SHOT_L_09);
					m_NormalShotL->SetLoop( false );
					m_pCharTop = m_NormalShotL;
					AddChild(m_pCharTop);
				}
				else
				{
					RemoveChild(m_pCharTop, false);
					m_NormalShotR = NNAnimation::Create(0.03f, 52,100,10, NORMAL_SHOT_R_00, NORMAL_SHOT_R_01, NORMAL_SHOT_R_02, NORMAL_SHOT_R_03, 
						NORMAL_SHOT_R_04, NORMAL_SHOT_R_05, NORMAL_SHOT_R_06, NORMAL_SHOT_R_07, NORMAL_SHOT_R_08, NORMAL_SHOT_R_09);
					m_NormalShotR->SetLoop( false );
					m_pCharTop = m_NormalShotR;
					AddChild(m_pCharTop);
				}
				bulletPos = GetPosition();
				if( isLeft )
					bulletPos.SetX( bulletPos.GetX() + 20 );

				NNBulletManager::GetInstance()->MakeBullet( NORMAL_BULLET, bulletPos );
				break;
			case DUAL_GUN:
				if (isLeft)
				{
					RemoveChild(m_pCharTop, false);
					m_DualGunShotL =  NNAnimation::Create(0.03f, 52,52,8, DUALGUN_SHOT_L_00, DUALGUN_SHOT_L_01, DUALGUN_SHOT_L_02,
						 DUALGUN_SHOT_L_03, DUALGUN_SHOT_L_04, DUALGUN_SHOT_L_05, DUALGUN_SHOT_L_06, DUALGUN_SHOT_L_07 );
					m_DualGunShotL->SetLoop( false );
					m_pCharTop = m_DualGunShotL;
					AddChild(m_pCharTop);
				}
				else
				{
					RemoveChild(m_pCharTop, false);
					m_DualGunShotR = NNAnimation::Create(0.03f, 52,52,8, DUALGUN_SHOT_R_00, DUALGUN_SHOT_R_01, DUALGUN_SHOT_R_02, DUALGUN_SHOT_R_03, 
						DUALGUN_SHOT_R_04, DUALGUN_SHOT_R_05, DUALGUN_SHOT_R_06, DUALGUN_SHOT_R_07 );
					m_DualGunShotR->SetLoop( false );
					m_pCharTop = m_DualGunShotR;
					AddChild(m_pCharTop);
				}
				bulletPos = GetPosition();
				NNBulletManager::GetInstance()->MakeBullet( NORMAL_BULLET, bulletPos );
				bulletPos.SetX( bulletPos.GetX() + 20 );
				NNBulletManager::GetInstance()->MakeBullet( NORMAL_BULLET, bulletPos );
				break;

			
			default:
				break;
			}

			

		
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
	//NORMAL 모션
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

	//DualGun 모션
	m_DualGunRunningTopR = NNAnimation::Create(0.2f, 60,65, 7, PLAYER_DUALGUN_STAND_TOP_R_00, 
		PLAYER_DUALGUN_STAND_TOP_R_01, PLAYER_DUALGUN_STAND_TOP_R_02, PLAYER_DUALGUN_STAND_TOP_R_03, 
		PLAYER_DUALGUN_STAND_TOP_R_02, PLAYER_DUALGUN_STAND_TOP_R_01, PLAYER_DUALGUN_STAND_TOP_R_00);
	m_DualGunRunningTopR->SetLoop(true);

	m_DualGunRunningTopL = NNAnimation::Create(0.2f, 60,65, 7, PLAYER_DUALGUN_STAND_TOP_L_00, 
		PLAYER_DUALGUN_STAND_TOP_L_01, PLAYER_DUALGUN_STAND_TOP_L_02, PLAYER_DUALGUN_STAND_TOP_L_03, 
		PLAYER_DUALGUN_STAND_TOP_L_02, PLAYER_DUALGUN_STAND_TOP_L_01, PLAYER_DUALGUN_STAND_TOP_L_00);
	m_DualGunRunningTopL->SetLoop(true);

	m_DualGunStandingTopR =  NNAnimation::Create(0.2f, 60,65, 7, PLAYER_DUALGUN_STAND_TOP_R_00, 
		PLAYER_DUALGUN_STAND_TOP_R_01, PLAYER_DUALGUN_STAND_TOP_R_02, PLAYER_DUALGUN_STAND_TOP_R_03, 
		PLAYER_DUALGUN_STAND_TOP_R_02, PLAYER_DUALGUN_STAND_TOP_R_01, PLAYER_DUALGUN_STAND_TOP_R_00);
	m_DualGunRunningTopR->SetLoop(true);

	m_DualGunStandingTopL = NNAnimation::Create(0.2f, 60,65, 7, PLAYER_DUALGUN_STAND_TOP_L_00, 
		PLAYER_DUALGUN_STAND_TOP_L_01, PLAYER_DUALGUN_STAND_TOP_L_02, PLAYER_DUALGUN_STAND_TOP_L_03, 
		PLAYER_DUALGUN_STAND_TOP_L_02, PLAYER_DUALGUN_STAND_TOP_L_01, PLAYER_DUALGUN_STAND_TOP_L_00);
	m_DualGunRunningTopL->SetLoop(true);
	/////////////////////////////////
	//나머지 모든 무기 모션
	m_AmorStandingTopR = NNAnimation::Create(0.2f, 60, 50, 12, PLAYER_AMOR_STAND_TOP_R_01,PLAYER_AMOR_STAND_TOP_R_02,
		PLAYER_AMOR_STAND_TOP_R_03,PLAYER_AMOR_STAND_TOP_R_04,PLAYER_AMOR_STAND_TOP_R_05,PLAYER_AMOR_STAND_TOP_R_06,
		PLAYER_AMOR_STAND_TOP_R_07,PLAYER_AMOR_STAND_TOP_R_08,PLAYER_AMOR_STAND_TOP_R_09,PLAYER_AMOR_STAND_TOP_R_10,
		PLAYER_AMOR_STAND_TOP_R_11,PLAYER_AMOR_STAND_TOP_R_12);
	m_AmorStandingTopR->SetLoop(true);

	m_AmorRunningTopR = NNAnimation::Create(0.2f, 60, 50, 12, PLAYER_AMOR_STAND_TOP_R_01,PLAYER_AMOR_STAND_TOP_R_02,
		PLAYER_AMOR_STAND_TOP_R_03,PLAYER_AMOR_STAND_TOP_R_04,PLAYER_AMOR_STAND_TOP_R_05,PLAYER_AMOR_STAND_TOP_R_06,
		PLAYER_AMOR_STAND_TOP_R_07,PLAYER_AMOR_STAND_TOP_R_08,PLAYER_AMOR_STAND_TOP_R_09,PLAYER_AMOR_STAND_TOP_R_10,
		PLAYER_AMOR_STAND_TOP_R_11,PLAYER_AMOR_STAND_TOP_R_12);
	m_AmorRunningTopR->SetLoop(true);

	m_AmorStandingTopL = NNAnimation::Create(0.2f, 60, 50, 12, PLAYER_AMOR_STAND_TOP_L_01,PLAYER_AMOR_STAND_TOP_L_02,
		PLAYER_AMOR_STAND_TOP_L_03,PLAYER_AMOR_STAND_TOP_L_04,PLAYER_AMOR_STAND_TOP_L_05,PLAYER_AMOR_STAND_TOP_L_06,
		PLAYER_AMOR_STAND_TOP_L_07,PLAYER_AMOR_STAND_TOP_L_08,PLAYER_AMOR_STAND_TOP_L_09,PLAYER_AMOR_STAND_TOP_L_10,
		PLAYER_AMOR_STAND_TOP_L_11,PLAYER_AMOR_STAND_TOP_L_12);
	m_AmorStandingTopL->SetLoop(true);

	m_AmorRunningTopL = NNAnimation::Create(0.2f, 60, 50, 12, PLAYER_AMOR_STAND_TOP_L_01,PLAYER_AMOR_STAND_TOP_L_02,
		PLAYER_AMOR_STAND_TOP_L_03,PLAYER_AMOR_STAND_TOP_L_04,PLAYER_AMOR_STAND_TOP_L_05,PLAYER_AMOR_STAND_TOP_L_06,
		PLAYER_AMOR_STAND_TOP_L_07,PLAYER_AMOR_STAND_TOP_L_08,PLAYER_AMOR_STAND_TOP_L_09,PLAYER_AMOR_STAND_TOP_L_10,
		PLAYER_AMOR_STAND_TOP_L_11,PLAYER_AMOR_STAND_TOP_L_12);
	m_AmorRunningTopL->SetLoop(true);

	
}

void NNPlayerCharacter::SetAttackStatus( ATTACK_STATUS status )
{
	if( m_AttackStatus == NORMAL && status == DUAL_GUN )
	{
		m_AttackStatus = status;
		if( m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL ||  m_pCharTop == m_NormalShotL  )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_DualGunRunningTopL;
			AddChild(m_pCharTop);
		}
		else if( m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR ||  m_pCharTop == m_NormalShotR )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_DualGunRunningTopR;
			AddChild(m_pCharTop);
		}
			SetPosition( GetPositionX()-1, GetPositionY() + 49);
	}
	else if( m_AttackStatus == DUAL_GUN && status == NORMAL )
	{
		m_AttackStatus = status;

		if( m_pCharTop == m_DualGunRunningTopL ||  m_pCharTop == m_DualGunStandingTopL ||  m_pCharTop == m_DualGunShotL  )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_RunningTopL;
			AddChild(m_pCharTop);
		}
		else if(m_pCharTop == m_DualGunRunningTopR ||  m_pCharTop == m_DualGunStandingTopR ||  m_pCharTop == m_DualGunShotR )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_RunningTopR;
			AddChild(m_pCharTop);
		}
		SetPosition( GetPositionX()+1, GetPositionY() - 49);
	}
	

	if( m_AttackStatus == NORMAL && status == FIRE)
	{
		m_AttackStatus = status;
		if( m_pCharTop == m_RunningTopL ||  m_pCharTop == m_StandingTopL ||  m_pCharTop == m_NormalShotL  )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_AmorRunningTopL;
			AddChild(m_pCharTop);
		}
		else if( m_pCharTop == m_RunningTopR ||  m_pCharTop == m_StandingTopR ||  m_pCharTop == m_NormalShotR )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_AmorRunningTopR;
			AddChild(m_pCharTop);
		}
		SetPosition( GetPositionX()-3, GetPositionY() + 51);
	}
	else if( m_AttackStatus == FIRE && status == NORMAL )
	{
		m_AttackStatus = status;

		if( m_pCharTop == m_AmorRunningTopL ||  m_pCharTop == m_AmorStandingTopL ||  m_pCharTop == m_AmorShotL  )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_RunningTopL;
			AddChild(m_pCharTop);
		}
		else if( m_pCharTop == m_AmorRunningTopR ||  m_pCharTop == m_AmorStandingTopR ||  m_pCharTop == m_AmorShotR )
		{
			isAttack = false;
			RemoveChild(m_pCharTop, false);
			m_pCharTop = m_RunningTopR;
			AddChild(m_pCharTop);
		}
		SetPosition( GetPositionX()+3, GetPositionY() - 51);
	}
}

GOING_DIRECTION NNPlayerCharacter::GetPlayerDirection()
{
	if( m_pCharTop == m_RunningTopL || m_pCharTop == m_StandingTopL || m_pCharTop == m_NormalShotL )
		return LEFT_GO;
	else
		return RIGHT_GO;
}
