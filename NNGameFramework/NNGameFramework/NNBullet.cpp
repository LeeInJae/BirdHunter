#include "NNBullet.h"


NNBullet::NNBullet(void)
{
	m_CheckByBird = false;
	m_CheckByPoo  = false;

}


NNBullet::~NNBullet(void)
{
}

void NNBullet::Move( float dTime )
{
	NNPoint nowBulletPosition = m_pBullet->GetPosition();

	if( nowBulletPosition.GetY() >= -100 )  // 0���� �����ؾ���. 
	{
		m_pBullet -> SetPosition( nowBulletPosition.GetX(), nowBulletPosition.GetY() - m_BulletSpeed * dTime );
	}
}