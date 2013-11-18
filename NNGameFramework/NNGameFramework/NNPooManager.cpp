#include "NNPooManager.h"
#include "NNPoo_A.h"
#include "BHDefine.h"
#include "NNPlayerCharacter.h"

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

NNPooManager::NNPooManager(void) : m_LandedPoo(0)
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
	case NORMAL_POO:
		poo_Property.setImageHeight = NORMAL_POO_HEIGHT;
		poo_Property.setImageWidth	= NORMAL_POO_WIDTH;
		poo_Property.speed			= NORMAL_POO_SPEED;
		poo_Property.sprite_path	= NORMAL_POO_SPRITE;
		poo_Property.zindex			= NORMAL_POO_ZINDEX;
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

	//poo & bound hitcheck
	//�ݺ��� �̿� ����Ʈ���� ���� �����ϴ� �� ���� ����.(�����ϰ� �� �� �ݺ��ڰ� �ٲ�� ��)
	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		if( (*poo_Iter)->GetPositionY() >= RESOLUTION_HEIGHT - (*poo_Iter)->GetSpriteHeight() )
		{
			auto pBullet = *poo_Iter;

			// ����Ʈ���� ����. ��ȯ���� ���� �����̴�.
			//�����ϰ� �ְ�, -> ���� �����ϰ�  �׻� �����̵Ǿ�� ��
			poo_Iter =  m_Poo.erase( poo_Iter );	

			// ��ü ����
			RemoveChild(pBullet, true);
			++m_LandedPoo;
		}
		else
		{
			++poo_Iter;
		}
	}

	

}

bool NNPooManager::HitCheckByPlayer( NNPlayerCharacter* player )
{
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	//poo & player hitcheck
	struct Hit_Rect poo_rect, player_rect;

	bool hitCheck;

	player_rect.left	=	player->GetPositionX() + PLAYER_SPRITE_REAL_EDGE;
	player_rect.right	=	player->GetPositionX() + player->GetSpriteWidth() - PLAYER_SPRITE_REAL_EDGE;
	player_rect.up		=	player->GetPositionY() + PLAYER_SPRITE_REAL_EDGE;
	player_rect.down	=	player->GetPositionY() + player->GetSpriteHeight() - PLAYER_SPRITE_REAL_EDGE;

	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		auto pPoo_Iter = *poo_Iter;

		poo_rect.left	=	pPoo_Iter->GetPositionX();
		poo_rect.right	=	pPoo_Iter->GetPositionX() + pPoo_Iter->GetSpriteWidth();
		poo_rect.up		=	pPoo_Iter->GetPositionY();
		poo_rect.down	=	pPoo_Iter->GetPositionY() + pPoo_Iter->GetSpriteHeight();

		hitCheck = false;

		if( poo_rect.right < player_rect.left || poo_rect.down < player_rect.up || poo_rect.left	> player_rect.right	||	poo_rect.up > player_rect.down )
		{
			++poo_Iter;
			continue;
		}
		else
		{
			return true;
			//poo_Iter = m_Poo.erase( poo_Iter );
			//RemoveChild( pPoo_Iter, true );
			//getchar();

			//bullet_Iter = m_Bullet.erase( bullet_Iter );
			//RemoveChild( pBullet_Iter, true );
		}

		//}
		//if( !hitCheck )
// 		{
// 			++bullet_Iter;
// 		}
	}
	return false;
}
