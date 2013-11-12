#include "NNBullet_A.h"
#include "BHDefine.h"


NNBullet_A::NNBullet_A(void)
{
	m_pBullet = NNSprite::Create( L"Image/BULLET_A.png" );
	m_pBullet -> SetImageWidth( BULLET_A_WIDTH );
	m_pBullet -> SetImageHeight( BULLET_A_HEIGHT );
	m_pBullet -> SetZindex( 4 );
	m_BulletSpeed = BULLET_A_SPEED;
	AddChild( m_pBullet );
}


NNBullet_A::~NNBullet_A(void)
{
}

void NNBullet_A::Move( float dTime )
{
	NNBullet::Move( dTime );
}
