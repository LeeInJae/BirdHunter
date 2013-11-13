#include "NNPooManager.h"
#include "NNPoo_A.h"
#include "BHDefine.h"

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
	POO_PROPERTY poo_Property;


	// agebreak : ���� �ٸ� Ŭ������ ����� ���� �ʿ䰡 ������? 
	// �̷� ��쿡�� ��ü�� �Ӽ����� �ٸ��� ������? 
	// ���� �غ��� : ���丮 ����


	switch ( WhichPoo )
	{
	case POO_A:
		poo_Property.setImageHeight = NORMAL_BIRD_POO_HEIGHT;
		poo_Property.setImageWidth	= NORMAL_BIRD_POO_WIDTH;
		poo_Property.speed			= NORMAL_BIRD_SPEED;
		poo_Property.sprite_path	= NORMAL_BIRD_POO_SPRITE;
		poo_Property.zindex			= NORMAL_BIRD_POO_ZINDEX;
		NNPoo* newPoo;
		newPoo = new NNPoo();
		newPoo->SetProperty( poo_Property );
		newPoo->SetPosition( birdPosition );
		m_Poo.push_back( newPoo );
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

void NNPooManager::Update( float dTime )
{
	// agebreak : auto Ű���带 �̿��Ͽ�, �;� �����ϰ� ���� �� ����.
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();
	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); ++poo_Iter )
	{
		(*poo_Iter) -> Update( dTime );
	}
	RemoveCheck();
}

void NNPooManager::RemoveCheck()
{
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	//�ݺ��� �̿� ����Ʈ���� ���� �����ϴ� �� ���� ����.(�����ϰ� �� �� �ݺ��ڰ� �ٲ�� ��)
	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		if( (*poo_Iter) -> GetPositionY() >= RESOLUTION_HEIGHT - NORMAL_BIRD_POO_HEIGHT )
		{
			auto pBullet = *poo_Iter;

			// ����Ʈ���� ����. ��ȯ���� ���� �����̴�.
			//�����ϰ� �ְ�, -> ���� �����ϰ�  �׻� �����̵Ǿ�� ��
			poo_Iter =  m_Poo.erase( poo_Iter );	

			// ��ü ����
			RemoveChild(pBullet);
		}
		else
		{
			++poo_Iter;
		}
	}
}