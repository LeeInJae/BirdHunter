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
	if( GetPositionY() >= 0 )  // 0으로 수정해야함. 
	{
		SetPosition( GetPositionX(), GetPositionY() - m_BulletSpeed * dTime );
	}
}