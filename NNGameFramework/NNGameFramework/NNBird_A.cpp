#include "NNBird_A.h"
#include "BHDefine.h"
#include "NNPooManager.h"

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
	
// 	NNPoint BirdSetPosition;
// 
// 	// agebreak : 800, 50 이라고 하지 말고, 무엇을 의미하는 값인지 Define을 사용해서 정의할 것
// 	BirdSetPosition.SetX( (float) (rand() % 800) );
// 	BirdSetPosition.SetY( (float) (rand() % 50) );
	
	( checkDirection == 0 ) ? m_BirdDirection = LEFT_GO : m_BirdDirection = RIGHT_GO;
	
	
	if( m_BirdDirection == LEFT_GO )
		m_pBird = NNSprite::Create( L"Image/BIRD_A_LEFT.png" );
	else
		m_pBird = NNSprite::Create( L"Image/BIRD_A_RIGHT.png" );
	
	//SetPosition( BirdSetPosition );

	m_pBird->SetImageHeight( BIRD_HEIGHT );
	m_pBird->SetImageWidth( BIRD_WIDTH );	
	SetZindex( 2 );
	AddChild( m_pBird );
}

void NNBird_A::Move( float dTime )
{
	NNBird::Move( dTime );
	
	//review 받을 것
	/////////////////////////
	m_SumTime += dTime;
	
	if( m_SumTime >= 0.5)
	{
		NNPooManager::GetInstance()->MakePoo( POO_A, GetPosition() );
		m_SumTime = 0;
	}
}