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
}

void NNBird_A::Move( float dTime )
{
	NNBird::Move( dTime );
	
	//review ¹ÞÀ» °Í
	/////////////////////////
	m_SumTime += dTime;
	if( m_SumTime >= 0.5)
	{
		MakePoo();
		m_SumTime = 0;
	}

// 	while(1)
// 	{
// 		bool flag = false;
// 
// 		std::list< NNPoo_A* >::iterator pooIter;
// 		for( pooIter = m_Bird_A_Poo.begin(); pooIter != m_Bird_A_Poo.end(); ++pooIter )
// 		{
// 			if ( (( (*pooIter)->GetPooSprite() ) -> GetPositionY() ) >= 100 )
// 			{
// 				m_Bird_A_Poo.erase( pooIter );
// 				flag = true;
// 				break;
// 			}
// 		}
// 
// 		if( flag == false )
// 		{
// 			break;
// 		}
// 	}
	std::list< NNPoo_A* >::iterator pooIter;
	for( pooIter = m_Bird_A_Poo.begin(); pooIter != m_Bird_A_Poo.end(); ++pooIter )
	{
		(*pooIter)->Move( dTime );
	}
	////////////////////////////////////
}

void NNBird_A::MakePoo()
{
	NNPoo_A* newPoo = new NNPoo_A;
	
	NNPoint nowBirdPosition = m_pBird->GetPosition();
	( newPoo->GetPooSprite() )->SetPosition( nowBirdPosition );
	( newPoo->GetPooSprite() )->SetZindex( 4 );
	m_Bird_A_Poo.push_back( newPoo );

//	delete newPoo;
}

NNSprite* NNBird_A::GetPooSprite()
{
	if( m_Bird_A_Poo.empty())
		return false;
	return (m_Bird_A_Poo.back())->GetPooSprite();

	return false;
}

bool NNBird_A::IsCheckPooEdge()
{
	return false;
}