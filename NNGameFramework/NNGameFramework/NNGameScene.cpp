#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"

NNGameScene::NNGameScene(void )
{
	m_Map = new NNMap_A;
	m_Character = new NNPlayerCharacter;
	m_PooManager = new NNPooManager;
	m_Bird	=	new NNBird_A;

	m_SumTime = 0;

	AddChild( m_Map );
	AddChild( m_Character );
	AddChild( m_Bird );
	AddChild( m_PooManager );
	AddChild( NNBulletManager::GetInstance() );
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
	

	m_SumTime += dTime;
	
	if( m_SumTime >= 5 )
	{
		NNPoint birdPosition = (m_Bird-> GetPosition() );

		m_PooManager->MakePoo( POO_A, birdPosition );
		m_SumTime = 0;
	}

	MovePlayerCharacter( dTime );
	MoveBullet( dTime );
	MoveBird( dTime );
	MovePoo( dTime );
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

void NNGameScene::MovePoo( float dTime )
{
	m_PooManager -> Move( dTime );
}

void NNGameScene::MoveBullet( float dTime )
{
	NNBulletManager::GetInstance()->Move( dTime );
}