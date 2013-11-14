#include "NNBird.h"
#include "BHDefine.h"
#include "NNPooManager.h"


NNBird::NNBird(void)
{
}


NNBird::~NNBird(void)
{
}

void NNBird::Update( float dTime )
{
	if( m_BirdDirection == LEFT_GO )
	{
		SetPosition( GetPositionX() - m_BirdSpeed * dTime, GetPositionY() );
		if( GetPositionX() <= 0 )
		{
			SetScaleX( m_Toggle );
			m_Toggle *= -1;
			m_BirdDirection = RIGHT_GO;
		}
	}
	else
	{
		SetPosition( GetPositionX() + m_BirdSpeed * dTime, GetPositionY() );
		if(GetPositionX() >= RESOLUTION_WIDTH )
		{
			SetScaleX(  m_Toggle );
			m_Toggle *= -1;
			m_BirdDirection = LEFT_GO;
		}
	}

	m_SumTime += dTime;

	if( m_SumTime >= 0.5)
	{
		NNPooManager::GetInstance()->MakePoo( POO_A, GetPosition() );
		m_SumTime = 0;
	}

}

void NNBird::SetBirdProperty( BIRD_PROPERTY bird_property )
{
	m_Toggle = -1;
	m_DeadCheck = false;
	m_CheckByBullet = false;

	m_BirdSpeed = bird_property.speed;
	m_BirdDirection = bird_property.goingDirection;
	m_SumTime = 0;
	m_Type = bird_property.type;
	m_pBird = NNSprite::Create( bird_property.sprite_path );
	m_SpriteHeight = bird_property.setImageHeight;
	m_SpriteWidth = bird_property.setImageWidth;

	m_pBird->SetImageHeight( bird_property.setImageHeight );
	m_pBird->SetImageWidth( bird_property.setImageWidth );	
	SetZindex( bird_property.zindex );
	AddChild( m_pBird );
}