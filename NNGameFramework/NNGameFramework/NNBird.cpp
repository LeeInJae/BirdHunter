#include "NNBird.h"
#include "BHDefine.h"


NNBird::NNBird(void)
{
	m_Toggle = -1;
	m_DeadCheck = false;
	m_CheckByBullet = false;
}


NNBird::~NNBird(void)
{
}

void NNBird::Move( float dTime )
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
}
  