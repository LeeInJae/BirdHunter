#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"

NNGameScene::NNGameScene(void )
{
	m_Map = new NNMap_A;
	m_Character = new NNPlayerCharacter;
	m_Bird	=	new NNBird_A;

	AddChild( m_Map );
	AddChild( m_Character );
	AddChild( m_Bird );
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
	
	MovePlayerCharacter( dTime );
	MoveBird( dTime );
}

void NNGameScene::Render()
{
	NNScene::Render();
}

void NNGameScene::MovePlayerCharacter( float dTime )
{
	m_Character -> Move( dTime );
}

void NNGameScene::MoveBird( float dTime )
{
	m_Bird -> Move( dTime );
}