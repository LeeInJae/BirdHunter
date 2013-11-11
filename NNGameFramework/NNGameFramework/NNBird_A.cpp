#include "NNBird_A.h"
#include "BHDefine.h"
#include "NNGameScene.h"


NNBird_A::NNBird_A(void)
{
	m_BirdSpeed = INIT_BIRD_A_SPEED;
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
}

void NNBird_A::Move( float dTime )
{
	NNBird::Move( dTime );
	
	MakePoo();
	std::list< NNPoo_A* >::iterator pooIter;

	for( pooIter = m_Bird_A_Poo.begin(); pooIter != m_Bird_A_Poo.end(); ++pooIter )
	{
		(*pooIter)->Move( dTime );
	}
}

void NNBird_A::MakePoo()
{
	NNPoo_A* newPoo = new NNPoo_A;
	NNPoint nowBirdPosition = m_pBird->GetPosition();
	newPoo->SetPosition( nowBirdPosition );
	newPoo->SetZindex( 4 );
	m_Bird_A_Poo.push_back( newPoo );
}

NNSprite* NNBird_A::GetPooSprite()
{
	std::list< NNPoo_A* >::iterator pooIter;
	for( pooIter = m_Bird_A_Poo.begin(); pooIter != m_Bird_A_Poo.end(); ++pooIter )
	{
		return (*pooIter)->GetPooSprite();
	}
	return false;
}
