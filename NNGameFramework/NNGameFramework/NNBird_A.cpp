#include "NNBird_A.h"
#include "BHDefine.h"


NNBird_A::NNBird_A(void)
{
	m_BirdSpeed = INIT_BIRD_A_SPEED;
// 	m_pBird[0] = NNSprite::Create( L"Image/Bird_A_Left.png" );
// 	m_pBird[1] = NNSprite::Create( L"Image/Bird_A_Right.png" );
	m_pLeftBird = NNSprite::Create( L"Image/Bird_A_LEFT.png" );
	m_pRightBird = NNSprite::Create( L"Image/Bird_A_RIGHT.png" );
	
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
	
	m_pLeftBird->SetPosition( BirdSetPosition );
	m_pLeftBird->SetImageHeight( BIRD_HEIGHT );
	m_pLeftBird->SetImageWidth( BIRD_WIDTH );
	m_pLeftBird->SetZindex( 3 );

	m_pRightBird->SetPosition( BirdSetPosition );
	m_pRightBird->SetImageHeight( BIRD_HEIGHT );
	m_pRightBird->SetImageWidth( BIRD_WIDTH );
	m_pRightBird->SetZindex( 3 );

	( checkDirection == 0 ) ? m_BirdDirection = LEFT_GO : m_BirdDirection = RIGHT_GO;

	m_pBird = nullptr;
	if( m_BirdDirection == LEFT_GO )
		*m_pBird = *m_pLeftBird;
		//m_pBird = NNSprite::Create( L"Image/Bird_A_Left.png" );
	else
		*m_pBird = *m_pRightBird;
		//m_pBird = NNSprite::Create( L"Image/Bird_A_Right.png" );

	/*
	m_pBird->SetPosition( BirdSetPosition );
	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );
	m_pBird->SetZindex( 3 );
	*/
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
