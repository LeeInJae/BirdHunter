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
	// agebreak : ���� �ٸ� Ŭ������ ����� ���� �ʿ䰡 ������? 
	// �̷� ��쿡�� ��ü�� �Ӽ����� �ٸ��� ������? 
	// ���� �غ��� : ���丮 ����
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
	// agebreak : auto Ű���带 �̿��Ͽ�, �;� �����ϰ� ���� �� ����.
	std::list< NNPoo_A* >::iterator poo_A_Iter = m_Poo_A.begin();
	for( poo_A_Iter = m_Poo_A.begin(); poo_A_Iter != m_Poo_A.end(); ++poo_A_Iter )
	{
		(*poo_A_Iter) -> Move( dTime );
	}
}

void NNPooManager::RemoveCheck()
{

}