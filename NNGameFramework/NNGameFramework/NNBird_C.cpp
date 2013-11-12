#include "NNBird_C.h"
#include "BHDefine.h"


NNBird_C::NNBird_C(void)
{
	m_BirdSpeed = INIT_BIRD_A_SPEED;
	InitBirdDirection();
}

NNBird_C::~NNBird_C(void)
{
}

void NNBird_C::InitBirdDirection()
{
	int checkDirection = rand() % 2;

	NNPoint BirdSetPosition;
	BirdSetPosition.SetX( (float) (rand() % 800) );
	BirdSetPosition.SetY( (float) (rand() % 50) );

	( checkDirection == 0 ) ? m_BirdDirection = LEFT_GO : m_BirdDirection = RIGHT_GO;


	if( m_BirdDirection == LEFT_GO )
		m_pBird = NNSprite::Create( L"Image/BIRD_C_LEFT.png" );
	else
		m_pBird = NNSprite::Create( L"Image/BIRD_C_RIGHT.png" );

	SetPosition( BirdSetPosition );

	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );	
	SetZindex( 2 );
	AddChild( m_pBird );
}

void NNBird_C::Move( float dTime )
{
	NNBird::Move( dTime );
}