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

	NNPoint BirdNowPoint = m_pBird -> GetPosition();

	if( m_BirdDirection == LEFT_GO )
	{
		m_pBird	-> SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
		if( BirdNowPoint.GetX() <= 0 )
		{
			//m_pBird	-> SetPosition( 0, BirdNowPoint.GetY() );
			//���� �������� �Ź� ���� �Ǳ� ������ �����ư��� -1,1: GetScaleX�� ����
			m_pBird -> SetScaleX( m_Toggle );
			m_Toggle *= -1;
			m_BirdDirection = RIGHT_GO;
		}
	}
	else
	{
		m_pBird -> SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
		if( BirdNowPoint.GetX() >= RESOLUTION_WIDTH )
		{
			//m_pBird -> SetPosition( RESOLUTION_WIDTH, BirdNowPoint.GetY() );
			m_pBird -> SetScaleX(  m_Toggle );
			m_Toggle *= -1;
			m_BirdDirection = LEFT_GO;
		}
	}
}
  