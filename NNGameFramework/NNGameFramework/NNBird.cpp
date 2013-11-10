#include "NNBird.h"
#include "BHDefine.h"


NNBird::NNBird(void)
{
}


NNBird::~NNBird(void)
{
}

void NNBird::Move( float dTime )
{
	NNPoint BirdNowPoint = m_pBird -> GetPosition();

	/*
	if( m_BirdDirection == LEFT_GO )
	{
	//	if( BirdNowPoint.GetX() - m_BirdSpeed * dTime >= 0 )
			m_pBird -> SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
			if( BirdNowPoint.GetX() - m_BirdSpeed * dTime <= 0 )
			{
				delete m_pBird;
				m_pBird = NNSprite::Create( L"Image/Bird_A_RIGHT.png" );				
				m_pBird->SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
				m_pBird->SetImageHeight( BIRD_HEIGHT );
				m_pBird->SetImageWidth( BIRD_WIDTH );
				m_pBird->SetZindex( 3 );

				//*m_pBird	= *m_pRightBird;
				//m_pBird = NNSprite::Create( L"Image/Bird_A_Right.png" );
				m_BirdDirection = RIGHT_GO;
			}
	}
	else
	{
	//	if( BirdNowPoint.GetX() + m_BirdSpeed * dTime <= 700 )
			m_pBird -> SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
			if( BirdNowPoint.GetX() + m_BirdSpeed * dTime >= 800 )
			{
				delete m_pBird;
				m_pBird = NNSprite::Create( L"Image/Bird_A_LEFT.png" );				
				m_pBird->SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
				m_pBird->SetImageHeight( BIRD_HEIGHT );
				m_pBird->SetImageWidth( BIRD_WIDTH );
				m_pBird->SetZindex( 3 );

			//	*m_pBird	= *m_pLeftBird;
				//m_pBird = NNSprite::Create( L"Image/Bird_A_Left.png" );
				m_BirdDirection = LEFT_GO;
			}
	}
	*/



	
	if( m_BirdDirection == LEFT_GO )
	{
		//	if( BirdNowPoint.GetX() - m_BirdSpeed * dTime >= 0 )
		m_pBird -> SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
		if( BirdNowPoint.GetX() - m_BirdSpeed * dTime <= 0 )
		{
			m_pRightBird->SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
			m_pRightBird->SetImageHeight( BIRD_HEIGHT );
			m_pRightBird->SetImageWidth( BIRD_WIDTH );
			m_pRightBird->SetZindex( 3 );
			*m_pBird	= *m_pRightBird;
			//m_pBird = NNSprite::Create( L"Image/Bird_A_Right.png" );
			m_BirdDirection = RIGHT_GO;
		}
	}
	else
	{
		//	if( BirdNowPoint.GetX() + m_BirdSpeed * dTime <= 700 )
		m_pBird -> SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
		if( BirdNowPoint.GetX() + m_BirdSpeed * dTime >= 800 )
		{
			m_pLeftBird->SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
			m_pLeftBird->SetImageHeight( BIRD_HEIGHT );
			m_pLeftBird->SetImageWidth( BIRD_WIDTH );
			m_pLeftBird->SetZindex( 3 );
			*m_pBird	= *m_pLeftBird;
			//m_pBird = NNSprite::Create( L"Image/Bird_A_Left.png" );
			m_BirdDirection = LEFT_GO;
		}
	}
	
}
