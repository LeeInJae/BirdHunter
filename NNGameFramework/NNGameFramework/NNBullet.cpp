#include "NNBullet.h"
#include "BHDefine.h"

NNBullet::NNBullet(void)
{
}

NNBullet::~NNBullet(void)
{
}

void NNBullet::Update( float dTime )
{
	if( GetPositionY() >= WINDOW_HEIGHT_UP_EDGE ) 
	{
		SetPosition( GetPositionX(), GetPositionY() - m_BulletProperty.speed * dTime );
	}
}

void NNBullet::SetBulletProperty( BULLET_PROPERTY bullet_property )
{
	m_pBullet			= NNSprite::Create( bullet_property.sprite_path );
	
	m_BulletProperty	=	bullet_property;

	m_pBullet->SetImageWidth( m_BulletProperty.imageWidth );
	m_pBullet->SetImageHeight( m_BulletProperty.imageHeight );
	m_pBullet->SetZindex( m_BulletProperty.zIndex );
	
	//m_pBullet->SetCenter( m_BulletProperty.position );
	AddChild( m_pBullet );
}