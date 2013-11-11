#include "NNPoo.h"


NNPoo::NNPoo(void)
{
	m_CheckByBullet = false;
	m_CheckByPlayer = false;
}


NNPoo::~NNPoo(void)
{
}

void NNPoo::SetPoo( NNPoint BirdPosition )
{
	m_pPoo->SetPosition( BirdPosition );
}

void NNPoo::Move( float dTime )
{
	NNPoint nowPooPosition = m_pPoo->GetPosition();

	if( nowPooPosition.GetY() <= 600 ) 
	{
		m_pPoo -> SetPosition( nowPooPosition.GetX(), nowPooPosition.GetY() + m_PooSpeed * dTime );
	}
}