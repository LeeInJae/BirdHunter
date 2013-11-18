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


	// agebreak : 각각 다른 클래스로 상속을 받을 필요가 있을까? 
	// 이런 경우에는 객체의 속성만이 다르지 않을까? 
	// 공부 해볼것 : 팩토리 패턴


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
	// agebreak : auto 키워드를 이용하여, 훤씬 간결하게 만들 수 있음.
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
	//반복자 이용 리스트에서 원소 삭제하는 것 에러 질문.(삭제하고 난 뒤 반복자가 바뀌는 듯)
	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		if( (*poo_Iter)->GetPositionY() >= RESOLUTION_HEIGHT - (*poo_Iter)->GetSpriteHeight() )
		{
			auto pBullet = *poo_Iter;

			// 리스트에서 삭제. 반환값은 다음 원소이다.
			//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
			poo_Iter =  m_Poo.erase( poo_Iter );	

			// 객체 해제
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
