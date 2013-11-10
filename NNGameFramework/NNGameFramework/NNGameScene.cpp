#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"

NNGameScene::NNGameScene(void )
{
	m_pMap = NNSprite::Create( L"Image/map.png" );
	m_pMap -> SetImageWidth( RESOLUTION_WIDTH );
	m_pMap -> SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap ->SetZindex( 0 );

	AddChild( m_pMap );
	AddChild( m_Character.GetCharacterSprite() );
	AddChild( m_Bird.GetBirdSprite() );

}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
	//printf(" %f ", dTime );
	//dTime의 활용 질문하기
	MovePlayerCharacter( dTime );
	MoveBird( dTime );
}

void NNGameScene::Render()
{
	NNScene::Render();
}

void NNGameScene::MovePlayerCharacter( float dTime )
{
	m_Character.Move( dTime );
}

void NNGameScene::MoveBird( float dTime )
{
	m_Bird.Move( dTime );
}
