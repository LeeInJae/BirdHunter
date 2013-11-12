#include "NNBird_A.h"
#include "BHDefine.h"
#include "NNGameScene.h"

NNBird_A::NNBird_A(void)
{
	m_BirdSpeed = INIT_BIRD_A_SPEED;
	InitBirdDirection();
	m_SumTime = 0;
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
	AddChild( m_pBird );
}

void NNBird_A::Move( float dTime )
{
	NNBird::Move( dTime );
	
	//review ¹ÞÀ» °Í
	/////////////////////////
	m_SumTime += dTime;
	
	if( m_SumTime >= 0.5)
	{
		//MakePoo();
		m_SumTime = 0;
	}
}