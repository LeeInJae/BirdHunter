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
	if( GetPositionY() >= 0 )  // 0���� �����ؾ���. 
	{
		SetPosition( GetPositionX(), GetPositionY() - m_BulletSpeed * dTime );
	}
}