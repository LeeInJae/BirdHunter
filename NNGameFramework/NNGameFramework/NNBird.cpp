#include "NNBird.h"
#include "BHDefine.h"
#include "NNPooManager.h"

NNBird::NNBird(void)
{
	m_Toggle	= -1;
	m_SumTime	= 0;
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
			m_Toggle *= -1;	// agebreak : 이 변수는 필요 없을듯?
			m_BirdDirection = LEFT_GO;
		}
	}

	m_SumTime += dTime;

	// agebreak : 지금은 3초마다 생성하지만, 이것을 새의 종류에 따라 설정할 수 있는 형태로 변경해야 한다.
	if( m_SumTime >= 3)
	{
		NNPooManager::GetInstance()->MakePoo( NORMAL_POO, GetPosition() );
		m_SumTime = 0;
	}
}

void NNBird::SetBirdProperty( BIRD_PROPERTY bird_property )
{
	m_BirdSpeed		= bird_property.speed;
	m_BirdDirection = bird_property.goingDirection;
	
	m_Type			= bird_property.type;
	m_pBird			= NNSprite::Create( bird_property.sprite_path );
	m_SpriteHeight	= bird_property.setImageHeight;
	m_SpriteWidth	= bird_property.setImageWidth;
	m_Zindex		= bird_property.zindex;

	m_pBird->SetImageHeight( bird_property.setImageHeight );
	m_pBird->SetImageWidth( bird_property.setImageWidth );	
	SetZindex( bird_property.zindex );
	AddChild( m_pBird );
}