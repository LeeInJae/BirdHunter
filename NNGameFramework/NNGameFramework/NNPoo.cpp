#include "NNPoo.h"
#include "BHDefine.h"


NNPoo::NNPoo(void)
{
	
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
}

void NNPoo::SetProperty( POO_PROPERTY poo_property )
{
	m_CheckByBullet = false;
	m_CheckByPlayer = false;

	m_PooSpeed = poo_property.speed;
	m_pPoo = NNSprite::Create( poo_property.sprite_path );
	m_pPoo -> SetImageWidth( poo_property.setImageWidth );
	m_pPoo -> SetImageHeight( poo_property.setImageHeight );
	m_pPoo -> SetZindex( poo_property.zindex );
	AddChild( m_pPoo );
}
