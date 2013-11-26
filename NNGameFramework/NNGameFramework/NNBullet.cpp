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
	if( GetPositionY() >= WINDOW_HEIGHT_UP_EDGE )  // 0���� �����ؾ���. 
	{
		SetPosition( GetPositionX(), GetPositionY() - m_BulletSpeed * dTime );
	}
}

void NNBullet::SetBulletProperty( Bullet_PROPERTY bullet_property )
{
	// agebreak : �� ������ �� �����ϴ°�?
	m_CheckByBird = false;
	m_CheckByPoo  = false;

	m_pBullet			= NNSprite::Create( bullet_property.sprite_path );
	m_SpriteHeight		= bullet_property.setImageHeight;
	m_SpriteWidth		= bullet_property.setImageWidth;
	m_Type				= bullet_property.type;

	m_pBullet->SetImageWidth( bullet_property.setImageWidth );
	m_pBullet->SetImageHeight( bullet_property.setImageHeight );
	m_pBullet->SetZindex( bullet_property.zindex );
	m_BulletSpeed = bullet_property.speed;
	AddChild( m_pBullet );
}