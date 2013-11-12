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
	// agebreak : 600 같은 상수를 사용하지 말것, 명확하게 Define해서 사용할 것.
	if( GetPositionY() <= 600 ) 
	{
		SetPosition( GetPositionX(), GetPositionY() + m_PooSpeed * dTime );
	}
	NNPoint nowPooPosition = m_pPoo->GetPosition();

}