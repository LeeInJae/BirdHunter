#include "NNPlayerCharacter.h"
#include "BHDefine.h"
#include "NNBulletManager.h"


NNPlayerCharacter::NNPlayerCharacter(void)
{
	m_CheckByPoo = false;
	m_PlayerSpeed = INIT_PLAYERSPEED;
	m_pChar = NNSprite::Create( L"Image/character.png" );

	m_pChar -> SetImageWidth( PLAYER_WIDTH );
	m_pChar -> SetImageHeight( PLAYER_HEIGHT );
	//m_pChar -> SetZindex( 1 );
	//m_pChar -> SetPosition( PLAYER_POSITION_X, PLAYER_POSITION_Y );
	
	SetPosition( PLAYER_POSITION_X, PLAYER_POSITION_Y );
	SetZindex( 1 );
	m_SumTime = 0;
	AddChild( m_pChar );
}


NNPlayerCharacter::~NNPlayerCharacter(void)
{
}

void NNPlayerCharacter::Move( float dTime )
{
	NNPoint wich = GetPosition();
	switch( NNInputSystem::GetInstance() -> CheckWhichPressedKey() )
	{
	case LEFT:
		// agebreak : 0, 700 같은 상수를 사용하지 말고, Define을 사용하여 명확하게 할것. 

		if( GetPositionX() - m_PlayerSpeed * dTime >= 0 )
			SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );
		break;

	case RIGHT:
		if( GetPositionX() + m_PlayerSpeed * dTime <= 700 )
			SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
		break;
	default:
		break;
	}

	m_SumTime += dTime;

	if( m_SumTime >= 0.5)
	{
		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACK:
 	  		NNBulletManager::GetInstance()->MakeBullet( Bullet_A, GetPosition() );
			break;

		case ITEM1:
			break;

		case ITEM2:
			break;

		default:
			break;
		}
		m_SumTime = 0;
	}
	//NNInputSystem::ReleaseInstance();
}
