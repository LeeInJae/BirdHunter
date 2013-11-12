#include "NNPoo_A.h"
#include "BHDefine.h"

// agebreak : Poo 역시 단지 속성만 다른것이 아닌가? 이것을 상속으로 구현을 해야 할까?
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