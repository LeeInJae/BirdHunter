#include "NNPlayerCharacter.h"
#include "BHDefine.h"
#include "NNBulletManager.h"
#include "NNInputSystem.h"

NNPlayerCharacter::NNPlayerCharacter(void)
{
	m_CheckByPoo	= false;
	m_PlayerSpeed	= INIT_PLAYERSPEED;
	m_pChar = NNSprite::Create( PLAYER_SPRITE );
	
	m_SpriteHeight	=	PLAYER_HEIGHT;
	m_SpriteWidth	=	PLAYER_WIDTH;

	m_pChar->SetImageWidth( PLAYER_WIDTH );
	m_pChar->SetImageHeight( PLAYER_HEIGHT );

	SetPosition	( PLAYER_POSITION_X, PLAYER_POSITION_Y );
	SetZindex	( PLAYER_ZINDEX );
	m_SumTime = 0;
	
	AddChild( m_pChar );
}

NNPlayerCharacter::~NNPlayerCharacter(void)
{

}

void NNPlayerCharacter::Update( float dTime )
{
	NNPoint wich = GetPosition();
	
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

	m_SumTime += dTime;

	if( m_SumTime >= 0.1)
	{
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
		m_SumTime = 0;
	}
}