#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"
#include "NNBirdFactory.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include "NNPooManager.h"

NNGameScene::NNGameScene(void )
{
	m_Map = new NNMap_A();
	m_Character = new NNPlayerCharacter();
	//m_Bird	=	new NNBird_A();

	m_SumTime = 0;

	AddChild( m_Map );
	AddChild( m_Character );
	//AddChild( m_Bird );
	AddChild( NNPooManager::GetInstance() );
	AddChild( NNBulletManager::GetInstance() );
	AddChild( NNBirdFactory::GetInstance() );

	m_PlayTimeLabel = NNLabel::Create(L"TIME : ", L"맑은 고딕", 15.f);
	m_PlayTimeLabel->SetPosition(1.f, 1.f);
	AddChild(m_PlayTimeLabel);

	m_LandedPooLabel = NNLabel::Create(L"POLLuTION : ", L"맑은 고딕", 15.f);
	m_LandedPooLabel->SetPosition(1.f, 30.f);
	AddChild(m_LandedPooLabel);
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
 		NNBirdFactory::GetInstance() -> MakeBird( NORMAL_BIRD );
		NNBirdFactory::GetInstance() -> MakeBird( NORMAL_BIRD );
		NNBirdFactory::GetInstance() -> MakeBird( EASY_BIRD );
		m_SumTime = 0;
 	}


	// agebreak : Move()가 아니라 각각 클래스에서 Update()를 오버라이딩하면, 
	// 부모 오브젝트에서 자동으로 호출되기 때문에, 따로 이렇게 Move를 처리해주지 않아도 됨. 

	m_Character->Update( dTime );
	NNBulletManager::GetInstance()-> Update( dTime );
	NNPooManager::GetInstance()-> Update( dTime );
	NNBirdFactory::GetInstance()->Update( dTime );

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"TIME : %0.1f sec", NNApplication::GetInstance()->GetElapsedTime());
	m_PlayTimeLabel->SetString(m_PlayTimeString);

	swprintf_s(m_LandedPooString, _countof(m_LandedPooString), L"POLLUTION : %d ", NNPooManager::GetInstance()->GetLandedPoo());
	m_LandedPooLabel->SetString(m_LandedPooString);
}

void NNGameScene::Render()
{
	NNScene::Render();
}

//  
// void NNGameScene::MovePlayerCharacter( float dTime )
// {
// 	// agebreak : 포인터 연산자(->)를 사용할때는 공백을 뛰우지 않음!
// 	m_Character -> Move( dTime );
// }
// 
// void NNGameScene::MoveBird( float dTime )
// {
// 	NNBirdFactory::GetInstance()->Move( dTime );
// }
// 
// void NNGameScene::MovePoo( float dTime )
// {
// 	NNPooManager::GetInstance() -> Move( dTime );
// }
// 
// void NNGameScene::MoveBullet( float dTime )
// {
// 	NNBulletManager::GetInstance() -> Move( dTime );
// }