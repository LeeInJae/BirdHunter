#include "NNPoo_A.h"
#include "BHDefine.h"

NNPoo_A::NNPoo_A(void)
{
	m_PooSpeed = POO_A_SPEED;
	m_pPoo = NNSprite::Create( L"Image/poo.png" );
	m_pPoo -> SetImageWidth( POO_A_WIDTH );
	m_pPoo -> SetImageHeight( POO_A_HEIGHT );
	m_pPoo -> SetZindex( 3 );
	AddChild( m_pPoo );
}


NNPoo_A::~NNPoo_A(void)
{
}

void NNPoo_A::Move( float dTime )
{
	NNPoo::Move( dTime );
}