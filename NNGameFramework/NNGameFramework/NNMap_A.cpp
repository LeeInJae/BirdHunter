#include "NNMap_A.h"
#include "BHDefine.h"
#include "NNObject.h"


NNMap_A::NNMap_A( void )
{
	m_pMap = NNSprite::Create( L"Image/map.png" );
	m_pMap -> SetImageWidth( RESOLUTION_WIDTH );
	m_pMap -> SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap ->SetZindex( 0 );
	AddChild( m_pMap );
}


NNMap_A::~NNMap_A(void)
{
}
