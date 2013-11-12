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
	if( GetPositionY() <= 600 ) 
	{
		SetPosition( GetPositionX(), GetPositionY() + m_PooSpeed * dTime );
	}
	NNPoint nowPooPosition = m_pPoo->GetPosition();

}