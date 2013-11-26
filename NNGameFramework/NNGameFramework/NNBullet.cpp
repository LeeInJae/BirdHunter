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
		SetPosition( GetPositionX(), GetPositionY() - m_BulletSpeed * dTime );
	}
}

void NNBullet::SetBulletProperty( BULLET_PROPERTY bullet_property )
{
	m_pBullet			= NNSprite::Create( bullet_property.sprite_path );
	m_SpriteHeight		= bullet_property.imageHeight;
	m_SpriteWidth		= bullet_property.imageWidth;
	m_Type				= bullet_property.type;

	m_pBullet->SetImageWidth( bullet_property.imageWidth );
	m_pBullet->SetImageHeight( bullet_property.imageHeight );
	m_pBullet->SetZindex( bullet_property.zIndex );
	m_BulletSpeed = bullet_property.speed;
	AddChild( m_pBullet );
}