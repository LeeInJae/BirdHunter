#include "NNBird.h"
#include "BHDefine.h"


NNBird::NNBird(void)
{
	firstCheck = 0;
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
			if( firstCheck == 0)
			{
				m_pBird -> SetScaleX( -1 );
				++firstCheck;
			}
			else
			{
				m_pBird -> SetScaleX( 1 );
				firstCheck = 0;
			}

			m_BirdDirection = RIGHT_GO;
		}
	}
	else
	{
		m_pBird -> SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
		if( BirdNowPoint.GetX() >= RESOLUTION_WIDTH )
		{
			//m_pBird -> SetPosition( RESOLUTION_WIDTH, BirdNowPoint.GetY() );
			if( firstCheck == 0)
			{
				m_pBird -> SetScaleX( -1 );
				++firstCheck;
			}
			else
			{
				m_pBird -> SetScaleX( 1 );
				firstCheck = 0;
			}
			m_BirdDirection = LEFT_GO;
		}
	}
}
  