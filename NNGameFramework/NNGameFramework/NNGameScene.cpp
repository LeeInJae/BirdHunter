#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"

NNGameScene::NNGameScene(void )
{
	m_pMap = NNSprite::Create( L"Image/map.png" );
	m_pMap -> SetImageWidth( RESOLUTION_WIDTH );
	m_pMap -> SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap ->SetZindex( 0 );

	m_pCharacter.m_pChar = NNSprite::Create( L"Image/character.png" );
	m_pCharacter.m_pChar -> SetImageWidth( 100 );
	m_pCharacter.m_pChar -> SetImageHeight( 100 );
	m_pCharacter.m_pChar -> SetZindex( 1 );
	m_pCharacter.m_pChar -> SetPosition( 350, 500 );


	AddChild( m_pMap );
	AddChild( m_pCharacter.m_pChar );
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
}

void NNGameScene::Render()
{
	NNScene::Render();
}