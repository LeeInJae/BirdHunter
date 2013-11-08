#include "NNMap.h"
#include "NNSprite.h"


NNMap::NNMap(void)
{
	m_pMap = NNSprite::Create( L"Image/map.png" );
	AddChild( m_pMap );
}


NNMap::~NNMap(void)
{
}

void NNMap::Update( float dTime )
{
	NNScene::Update( dTime );
}

void NNMap::Render()
{
	NNScene::Render();
}