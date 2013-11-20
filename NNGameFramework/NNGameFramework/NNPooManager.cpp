#include "NNPooManager.h"
#include "BHDefine.h"
#include "NNPlayerCharacter.h"
#include "NNPoo.h"

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
	default:
		break;
	}
}

void NNPooManager::Update( float dTime )
{
	for( auto poo_Iter : m_Poo )
	{
		poo_Iter->Update( dTime );
	}
	RemoveCheck();
}

void NNPooManager::RemoveCheck()
{
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	//poo & bound hitcheck
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
		}
	}
	return false;
}
