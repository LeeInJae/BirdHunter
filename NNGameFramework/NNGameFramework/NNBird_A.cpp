#include "NNBird_A.h"
#include "BHDefine.h"


NNBird_A::NNBird_A(void)
{
	m_BirdSpeed = INIT_BIRD_A_SPEED;
// 	m_pBird[0] = NNSprite::Create( L"Image/Bird_A_Left.png" );
// 	m_pBird[1] = NNSprite::Create( L"Image/Bird_A_Right.png" );
	
	//m_pBird = NNSprite::Create( L"Image/BIRD_A.png" );
	
	//m_pLeftBird = NNSprite::Create( L"Image/Bird_A_LEFT.png" );
	//m_pRightBird = NNSprite::Create( L"Image/Bird_A_RIGHT.png" );
	
	InitBirdDirection();
}

NNBird_A::~NNBird_A(void)
{
}

void NNBird_A::InitBirdDirection()
{
	int checkDirection = rand() % 2;
	
	NNPoint BirdSetPosition;
	BirdSetPosition.SetX( (float) (rand() % 800) );
	BirdSetPosition.SetY( (float) (rand() % 50) );
	
		( checkDirection == 0 ) ? m_BirdDirection = LEFT_GO : m_BirdDirection = RIGHT_GO;

	
	if( m_BirdDirection == LEFT_GO )
		m_pBird = NNSprite::Create( L"Image/BIRD_A_LEFT.png" );
	else
		m_pBird = NNSprite::Create( L"Image/BIRD_A_RIGHT.png" );
	
	m_pBird->SetPosition( BirdSetPosition );
	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );
	m_pBird->SetZindex( 2 );


	/*
	m_pBird->SetPosition( BirdSetPosition );
	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );
	m_pBird->SetZindex( 3 );
	*/
}

void NNBird_A::Move( float dTime )
{
// 	NNPoint BirdNowPoint = m_pBird -> GetPosition();
// 
// 	if( m_BirdDirection == LEFT_GO )
// 	{
// 		m_pBird	-> SetPosition( BirdNowPoint.GetX() - m_BirdSpeed * dTime, BirdNowPoint.GetY() );
// 		if( BirdNowPoint.GetX() <= 0 )
// 		{
// 			//m_pBird	-> SetPosition( 0, BirdNowPoint.GetY() );
// 			m_pBird -> SetScaleX( -1 );
// 			m_BirdDirection = RIGHT_GO;
// 		}
// 	}
// 	else
// 	{
// 		m_pBird -> SetPosition( BirdNowPoint.GetX() + m_BirdSpeed * dTime, BirdNowPoint.GetY() );
// 		if( BirdNowPoint.GetX() >= RESOLUTION_WIDTH )
// 		{
// 			//m_pBird -> SetPosition( RESOLUTION_WIDTH, BirdNowPoint.GetY() );
// 			m_pBird -> SetScaleX( -1);
// 			m_BirdDirection = LEFT_GO;
// 		}
// 	}
	NNBird::Move( dTime );
}

/*
void NNBird_A::BirdUpdate( float dTime )
{
	NNBird::Move( dTime );

	if( m_BirdDirection == LEFT_GO && m_pBird->GetPositionX() <= 0 )
	{
		m_pBird = NNSprite::Create( L"Image/Bird_A_Right.png" );
		m_BirdDirection = RIGHT_GO;
	}
	else if( m_BirdDirection == RIGHT_GO && m_pBird->GetPositionX() >= 800 )
	{
		m_pBird = NNSprite::Create( L"Image/Bird_A_left.png" );
			m_BirdDirection = LEFT_GO;
	}
}*/
