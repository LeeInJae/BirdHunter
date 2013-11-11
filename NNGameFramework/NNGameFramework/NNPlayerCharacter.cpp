#include "NNPlayerCharacter.h"
#include "BHDefine.h"


NNPlayerCharacter::NNPlayerCharacter(void)
{
	m_CheckByPoo = false;
	m_PlayerSpeed = INIT_PLAYERSPEED;
	m_pChar = NNSprite::Create( L"Image/character.png" );
	m_pChar -> SetImageWidth( PLAYER_WIDTH );
	m_pChar -> SetImageHeight( PLAYER_HEIGHT );
	m_pChar -> SetZindex( 1 );
	m_pChar -> SetPosition( PLAYER_POSITION_X, PLAYER_POSITION_Y );

	m_SumTime = 0;
}


NNPlayerCharacter::~NNPlayerCharacter(void)
{
}

void NNPlayerCharacter::Move( float dTime )
{
	NNPoint CharacterNowPoint = m_pChar -> GetPosition();

	switch( NNInputSystem::GetInstance() -> CheckWhichPressedKey() )
	{
	case LEFT:
		if( CharacterNowPoint.GetX() - m_PlayerSpeed * dTime >= 0 )
			m_pChar -> SetPosition( CharacterNowPoint.GetX() - m_PlayerSpeed * dTime, CharacterNowPoint.GetY() );
		break;

	case RIGHT:
		if( CharacterNowPoint.GetX() + m_PlayerSpeed * dTime <= 700 )
			m_pChar -> SetPosition( CharacterNowPoint.GetX() + m_PlayerSpeed * dTime, CharacterNowPoint.GetY() );
		break;
	default:
		break;
	}


	m_SumTime += dTime;
	//if( m_SumTime >= 0.5)
	{
		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACk:
			MakeBullet();
			break;

		case ITEM1:
			break;

		case ITEM2:
			break;

		default:
			break;
		}
		//MakeBullet();
		m_SumTime = 0;
	}
	//m_pCharacter.m_Direction = NNInputSystem::GetInstance -> GetDirection();

	std::list< NNBullet_A* >::iterator bulletIter;
	for( bulletIter = m_Player_Bullet_A.begin(); bulletIter != m_Player_Bullet_A.end(); ++bulletIter )
	{
		(*bulletIter)->Move( dTime );
	}
	////////////////////////////////////
}

void NNPlayerCharacter::MakeBullet()
{
	NNBullet_A* newBullet = new NNBullet_A;

	NNPoint nowCharacterPosition = m_pChar->GetPosition();
	( newBullet->GetBulletSprite() )->SetPosition( nowCharacterPosition );
	( newBullet->GetBulletSprite() )->SetZindex( 4 );
	m_Player_Bullet_A.push_back( newBullet );

	//	delete newPoo;
}

NNSprite* NNPlayerCharacter::GetBulletSprite()
{
	if( m_Player_Bullet_A.empty() )
		return false;
	return (m_Player_Bullet_A.back())->GetBulletSprite();

	return false;
}