#include "NNBird.h"
#include "BHDefine.h"
#include "NNPooManager.h"
#include "NNAnimation.h"

NNBird::NNBird(void)
{
	m_SumTime	= 0;
}

NNBird::~NNBird(void)
{

}

void NNBird::Update( float dTime )
{
	if( m_BirdProperty.goingDirection == LEFT_GO )
	{
		SetPosition( GetPositionX() - m_BirdProperty.speed * dTime, GetPositionY() );
		
		if( GetPositionX() <= 0 )
		{
			SetScaleX( GetScaleX() * (-1) );
			m_BirdProperty.goingDirection = RIGHT_GO;
		}
	}
	else
	{
		SetPosition( GetPositionX() + m_BirdProperty.speed * dTime, GetPositionY() );

		if(GetPositionX() >= RESOLUTION_WIDTH )
		{	
			SetScaleX( GetScaleX() * (-1) );
			m_BirdProperty.goingDirection = LEFT_GO;
		}
	}

	m_SumTime += dTime;

	if( m_SumTime >= m_BirdProperty.pooCoolTime )
	{
		NNPooManager::GetInstance()->MakePoo( m_BirdProperty.type, GetPosition() );
		m_SumTime = 0;
	}
}

void NNBird::SetBirdProperty( BIRD_PROPERTY &bird_property )
{
	m_BirdProperty	=	bird_property;
	
	m_pBird				= bird_property.birdAnimation;
	m_pBird->SetLoop(true);
// 	m_pBird->SetScaleX(bird_property.imageHeight);
// 	m_pBird->SetScaleY(bird_property.imageWidth);
	//m_pBird			=	NNSprite::Create( bird_property.sprite_path );
	//m_pBird->SetImageHeight( bird_property.imageHeight );
	//m_pBird->SetImageWidth( bird_property.imageWidth );	
	SetZindex( bird_property.zIndex );
	//m_pBird->SetCenter( m_BirdProperty.position );
	AddChild( m_pBird );
}