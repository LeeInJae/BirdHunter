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

	m_pCharacter.m_pChar = NNSprite::Create( L"Image/character.png" );
	m_pCharacter.m_pChar -> SetImageWidth( PLAYER_WIDTH );
	m_pCharacter.m_pChar -> SetImageHeight( PLAYER_HEIGHT );
	m_pCharacter.m_pChar -> SetZindex( 1 );
	m_pCharacter.m_pChar -> SetPosition( PLAYER_POSITION_X, PLAYER_POSITION_Y );


	AddChild( m_pMap );
	AddChild( m_pCharacter.m_pChar );
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
}

void NNGameScene::Render()
{
	NNScene::Render();
}

void NNGameScene::MovePlayerCharacter( float dTime )
{
	NNPoint CharacterNowPoint = m_pCharacter.m_pChar -> GetPosition();

	switch( NNInputSystem::GetInstance() -> CheckWhichPressedKey() )
	{
	case LEFT:
		if( CharacterNowPoint.GetX() - m_pCharacter.GetPlayerSpeed() * dTime >= 0 )
			m_pCharacter.m_pChar -> SetPosition( CharacterNowPoint.GetX() - m_pCharacter.GetPlayerSpeed() * dTime, CharacterNowPoint.GetY() );
		break;

	case RIGHT:
		if( CharacterNowPoint.GetX() + m_pCharacter.GetPlayerSpeed() * dTime <= 700 )
			m_pCharacter.m_pChar -> SetPosition( CharacterNowPoint.GetX() + m_pCharacter.GetPlayerSpeed() * dTime, CharacterNowPoint.GetY() );
		break;
	default:
		break;
	}
	
	//m_pCharacter.m_Direction = NNInputSystem::GetInstance -> GetDirection();
}
