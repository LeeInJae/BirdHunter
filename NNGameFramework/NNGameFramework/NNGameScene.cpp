#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"

NNGameScene::NNGameScene(void )
{
	m_Map = new NNMap_A();
	m_Character = new NNPlayerCharacter();
	m_Bird	=	new NNBird_A();

	m_SumTime = 0;

	AddChild( m_Map );
	AddChild( m_Character );
	AddChild( m_Bird );
	AddChild( NNPooManager::GetInstance() );
	AddChild( NNBulletManager::GetInstance() );
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
	

	m_SumTime += dTime;
	
// 	if( m_SumTime >= 5 )
// 	{
// 		NNPoint birdPosition = (m_Bird-> GetPosition() );
// 
// 		m_PooManager->MakePoo( POO_A, birdPosition );
// 		m_SumTime = 0;
// 	}


	// agebreak : Move()가 아니라 각각 클래스에서 Update()를 오버라이딩하면, 
	// 부모 오브젝트에서 자동으로 호출되기 때문에, 따로 이렇게 Move를 처리해주지 않아도 됨. 

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
	// agebreak : 포인터 연산자(->)를 사용할때는 공백을 뛰우지 않음!
	m_Character -> Move( dTime );
}

void NNGameScene::MoveBird( float dTime )
{
	m_Bird -> Move( dTime );
}

void NNGameScene::MovePoo( float dTime )
{
	NNPooManager::GetInstance() -> Move( dTime );
}

void NNGameScene::MoveBullet( float dTime )
{
	NNBulletManager::GetInstance() -> Move( dTime );
}