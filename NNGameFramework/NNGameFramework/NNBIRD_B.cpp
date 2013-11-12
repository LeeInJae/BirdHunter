#include "NNBIRD_B.h"
#include "BHDefine.h"


NNBIRD_B::NNBIRD_B(void)
{
	m_BirdSpeed = INIT_BIRD_B_SPEED;
	InitBirdDirection();
}


NNBIRD_B::~NNBIRD_B(void)
{

}

void NNBIRD_B::InitBirdDirection()
{
	int checkDirection = rand() % 2;

	NNPoint BirdSetPosition;
	BirdSetPosition.SetX( (float) (rand() % 800) );
	BirdSetPosition.SetY( (float) (rand() % 50) );

	( checkDirection == 0 ) ? m_BirdDirection = LEFT_GO : m_BirdDirection = RIGHT_GO;


	if( m_BirdDirection == LEFT_GO )
		m_pBird = NNSprite::Create( L"Image/BIRD_B_LEFT.png" );
	else
		m_pBird = NNSprite::Create( L"Image/BIRD_B_RIGHT.png" );

	SetPosition( BirdSetPosition );

	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );	
	SetZindex( 2 );
	AddChild( m_pBird );

// 	m_pBird->SetPosition( BirdSetPosition );
// 	m_pBird->SetImageHeight( BIRD_HEIGHT );
// 	m_pBird->SetImageWidth( BIRD_WIDTH );
// 	m_pBird->SetZindex( 2 );
}

void NNBIRD_B::Move( float dTime )
{
	NNBird::Move( dTime );
}
