#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNBulletManager.h"
#include "NNBirdFactory.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include "NNPooManager.h"
#include <assert.h>
#include "NNMapManager.h"

NNGameScene::NNGameScene(void )
{
	m_CheckGameOver = false;
	m_Character = new NNPlayerCharacter();

	m_SumTime = 0;

	AddChild( NNMapManager::GetInstance() );
	AddChild( m_Character );
	AddChild( NNPooManager::GetInstance() );
	AddChild( NNBulletManager::GetInstance() );
	AddChild( NNBirdFactory::GetInstance() );

	m_PlayTimeLabel = NNLabel::Create(L"TIME : ", L"맑은 고딕", 15.f);
	m_PlayTimeLabel->SetPosition(1.f, 1.f);
	AddChild(m_PlayTimeLabel);

	m_LandedPooLabel = NNLabel::Create(L"POLLUTION : ", L"맑은 고딕", 15.f);
	m_LandedPooLabel->SetPosition(1.f, 30.f);
	AddChild(m_LandedPooLabel);

	m_FPSLabel = NNLabel::Create(L"FPS : ", L"맑은 고딕", 15.f);
	m_FPSLabel->SetPosition(670.f, 1.f);
	AddChild(m_FPSLabel);
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	if(m_CheckGameOver)
		return;

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

	if( NNPooManager::GetInstance()->HitCheckByPlayer( m_Character ) )
	{ 
		m_GameOverLabel = NNLabel::Create(L"GameOver ", L"맑은 고딕", 50.f);
		m_GameOverLabel->SetPosition(RESOLUTION_WIDTH * 0.5f, RESOLUTION_HEIGHT * 0.5f );
		m_GameOverLabel->SetCenter(800,400); // agebreak : 이건 왜 상수인가?
		AddChild(m_GameOverLabel);
		m_CheckGameOver = true;
		//assert( !m_CheckGameOver );
		//getchar();
	}
	

	// agebreak : 업데이트 두번 호출 버그!!
	m_Character->Update( dTime );
	NNBulletManager::GetInstance()-> Update( dTime );
	NNPooManager::GetInstance()-> Update( dTime );
	NNBirdFactory::GetInstance()->Update( dTime );

	NNMapManager::GetInstance()->Update( dTime );

	// agebreak : UI 출력은 따로 함수로 분리해서 호출할것

	swprintf_s(m_PlayTimeString, _countof(m_PlayTimeString), L"TIME : %0.1f sec", NNApplication::GetInstance()->GetElapsedTime());
	m_PlayTimeLabel->SetString(m_PlayTimeString);

	swprintf_s(m_LandedPooString, _countof(m_LandedPooString), L"POLLUTION : %d ", NNPooManager::GetInstance()->GetLandedPoo());
	m_LandedPooLabel->SetString(m_LandedPooString);

	swprintf_s(m_FPSString, _countof(m_FPSString), L"FPS : %0.1f ", NNApplication::GetInstance()->GetFPS());
	m_FPSLabel->SetString(m_FPSString);
}

void NNGameScene::Render()
{
	NNScene::Render();
	if( m_CheckGameOver )
	{
		//getchar();
	}
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