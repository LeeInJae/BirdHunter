#include "NNPlayerCharacter.h"
#include "BHDefine.h"
#include "NNBulletManager.h"
#include "NNInputSystem.h"

NNPlayerCharacter::NNPlayerCharacter(void)
{
	m_PlayerSpeed	= INIT_PLAYERSPEED;
	m_pChar = NNSprite::Create( PLAYER_SPRITE );

	m_SpriteHeight	=	PLAYER_HEIGHT;
	m_SpriteWidth	=	PLAYER_WIDTH;

	m_pChar->SetImageWidth( PLAYER_WIDTH );
	m_pChar->SetImageHeight( PLAYER_HEIGHT );

	SetPosition	( PLAYER_POSITION_X, PLAYER_POSITION_Y );
	SetZindex	( PLAYER_ZINDEX );
	m_SumTime = 0;
	m_PauseKey = false;
	AddChild( m_pChar );
}

NNPlayerCharacter::~NNPlayerCharacter(void)
{

}

void NNPlayerCharacter::Update( float dTime )
{
	NNPoint wich = GetPosition();

	if( !m_PauseKey )
	{
		switch( NNInputSystem::GetInstance()->CheckWhichPressedKey() )
		{
		case LEFT:
			if( GetPositionX() - m_PlayerSpeed * dTime >= WINDOW_WIDTH_LEFT_EDGE )
				SetPosition( GetPositionX() - m_PlayerSpeed * dTime, GetPositionY() );
			break;

		case RIGHT:
			if( GetPositionX() + m_PlayerSpeed * dTime <= WINDOW_WIDTH_RIGHT_EDGE - PLAYER_WIDTH )
				SetPosition( GetPositionX() + m_PlayerSpeed * dTime, GetPositionY() );
			break;
		default:
			break;
		}

		switch( NNInputSystem::GetInstance()->CheckSpecialPressedKey() )
		{
		case ATTACK: 
			NNBulletManager::GetInstance()->MakeBullet( NORMAL_BULLET, GetPosition() );
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