#include "NNPooManager.h"
#include "NNPoo_A.h"

NNPooManager* NNPooManager::m_pInstance = nullptr;

NNPooManager* NNPooManager::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNPooManager();
	}

	return m_pInstance;
}

void NNPooManager::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

NNPooManager::NNPooManager(void)
{
}


NNPooManager::~NNPooManager(void)
{
}
 
void NNPooManager::MakePoo( PooType WhichPoo, NNPoint birdPosition )
{
	// agebreak : 각각 다른 클래스로 상속을 받을 필요가 있을까? 
	// 이런 경우에는 객체의 속성만이 다르지 않을까? 
	// 공부 해볼것 : 팩토리 패턴
	switch ( WhichPoo )
	{
	case POO_A:
		NNPoo_A* newPoo;
		newPoo = new NNPoo_A();
		m_Poo_A.push_back( newPoo );
		newPoo->SetPosition( birdPosition );
		AddChild( newPoo );
		break;
// 	case POO_B:
// 		break;
// 	case POO_C:
// 		break;
// 	case POO_D:
// 		break;
	default:
		break;
	}
}

void NNPooManager::Move( float dTime )
{
	// agebreak : auto 키워드를 이용하여, 훤씬 간결하게 만들 수 있음.
	std::list< NNPoo_A* >::iterator poo_A_Iter = m_Poo_A.begin();
	for( poo_A_Iter = m_Poo_A.begin(); poo_A_Iter != m_Poo_A.end(); ++poo_A_Iter )
	{
		(*poo_A_Iter) -> Move( dTime );
	}
}

void NNPooManager::RemoveCheck()
{

}