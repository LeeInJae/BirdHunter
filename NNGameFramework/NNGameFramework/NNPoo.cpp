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
	m_Poo->SetPosition( BirdPosition );
}

void NNPoo::Move( float dTime )
{
	NNPoint nowPooPosition = m_Poo->GetPosition();

	if( nowPooPosition.GetY() <= 600 ) 
	{
		m_Poo -> SetPosition( nowPooPosition.GetX, nowPooPosition.GetY() + m_PooSpeed * dTime );
	}
}