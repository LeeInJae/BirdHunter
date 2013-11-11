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
	//m_pCharacter.m_Direction = NNInputSystem::GetInstance -> GetDirection();
}