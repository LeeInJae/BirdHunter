#include "NNPooManager.h"
#include "BHDefine.h"
#include "NNPlayerCharacter.h"
#include "NNPoo.h"
#include "NNGameScene.h"
#include "NNEffectManager.h"
#include "NNSoundManager.h"


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
 
void NNPooManager::MakePoo( BIRD_TYPE WhichBird, NNPoint birdPosition )
{
	POO_PROPERTY poo_Property;

	switch ( WhichBird )
	{
	case BLACK_SMALL_BIRD:
		poo_Property.imageHeight	=	BLACK_SMALL_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	BLACK_SMALL_BIRD_POO_WIDTH;
		poo_Property.speed			=	BLACK_SMALL_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	BLACK_SMALL_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	BLACK_SMALL_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	BLACK_SMALL_BIRD_POO_ZINDEX;
		poo_Property.type			=	BLACK_SMALL_BIRD_POO;
		break;
	case ORANGE_SMALL_BIRD:
		poo_Property.imageHeight	=	ORANGE_SMALL_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	ORANGE_SMALL_BIRD_POO_WIDTH;
		poo_Property.speed			=	ORANGE_SMALL_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	ORANGE_SMALL_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	ORANGE_SMALL_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	ORANGE_SMALL_BIRD_POO_ZINDEX;
		poo_Property.type			=	ORANGE_SMALL_BIRD_POO;
		break;
	case WHITE_SMALL_BIRD:
		poo_Property.imageHeight	=	WHITE_SMALL_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	WHITE_SMALL_BIRD_POO_WIDTH;
		poo_Property.speed			=	WHITE_SMALL_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	WHITE_SMALL_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	WHITE_SMALL_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	WHITE_SMALL_BIRD_POO_ZINDEX;
		poo_Property.type			=	WHITE_SMALL_BIRD_POO;
		break;
	case RED_SMALL_BIRD:
		poo_Property.imageHeight	=	RED_SMALL_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	RED_SMALL_BIRD_POO_WIDTH;
		poo_Property.speed			=	RED_SMALL_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	RED_SMALL_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	RED_SMALL_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	RED_SMALL_BIRD_POO_ZINDEX;
		poo_Property.type			=	RED_SMALL_BIRD_POO;
		break;
	case BLACK_MID_BIRD:
		poo_Property.imageHeight	=	BLACK_MID_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	BLACK_MID_BIRD_POO_WIDTH;
		poo_Property.speed			=	BLACK_MID_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	BLACK_MID_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	BLACK_MID_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	BLACK_MID_BIRD_POO_ZINDEX;
		poo_Property.type			=	BLACK_MID_BIRD_POO;
		break;
	case CARAMEL_MID_BIRD:
		poo_Property.imageHeight	=	CARAMEL_MID_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	CARAMEL_MID_BIRD_POO_WIDTH;
		poo_Property.speed			=	CARAMEL_MID_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	CARAMEL_MID_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	CARAMEL_MID_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	CARAMEL_MID_BIRD_POO_ZINDEX;
		poo_Property.type			=	CARAMEL_MID_BIRD_POO;
		break;
	case GREEN_MID_BIRD:
		poo_Property.imageHeight	=	GREEN_MID_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	GREEN_MID_BIRD_POO_WIDTH;
		poo_Property.speed			=	GREEN_MID_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	GREEN_MID_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	GREEN_MID_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	GREEN_MID_BIRD_POO_ZINDEX;
		poo_Property.type			=	GREEN_MID_BIRD_POO;
		break;
	case ICE_MID_BIRD:
		poo_Property.imageHeight	=	ICE_MID_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	ICE_MID_BIRD_POO_WIDTH;
		poo_Property.speed			=	ICE_MID_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	ICE_MID_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	ICE_MID_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	ICE_MID_BIRD_POO_ZINDEX;
		poo_Property.type			=	ICE_MID_BIRD_POO;
		break;
	case YELLOW_MID_BIRD:
		poo_Property.imageHeight	=	YELLOW_MID_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	YELLOW_MID_BIRD_POO_WIDTH;
		poo_Property.speed			=	YELLOW_MID_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	YELLOW_MID_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	YELLOW_MID_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	YELLOW_MID_BIRD_POO_ZINDEX;
		poo_Property.type			=	YELLOW_MID_BIRD_POO;
		break;
	case BROWN_BIG_BIRD:
		poo_Property.imageHeight	=	BROWN_BIG_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	BROWN_BIG_BIRD_POO_WIDTH;
		poo_Property.speed			=	BROWN_BIG_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	BROWN_BIG_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	BROWN_BIG_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	BROWN_BIG_BIRD_POO_ZINDEX;
		poo_Property.type			=	BROWN_BIG_BIRD_POO;
		break;
	case WHITE_BIG_BIRD:
		poo_Property.imageHeight	=	WHITE_BIG_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	WHITE_BIG_BIRD_POO_WIDTH;
		poo_Property.speed			=	WHITE_BIG_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	WHITE_BIG_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	WHITE_BIG_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	WHITE_BIG_BIRD_POO_ZINDEX;
		poo_Property.type			=	WHITE_BIG_BIRD_POO;
		break;
	case PINK_BIG_BIRD:
		poo_Property.imageHeight	=	PINK_BIG_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	PINK_BIG_BIRD_POO_WIDTH;
		poo_Property.speed			=	PINK_BIG_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	PINK_BIG_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	PINK_BIG_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	PINK_BIG_BIRD_POO_ZINDEX;
		poo_Property.type			=	PINK_BIG_BIRD_POO;
		break;
	case ITEM_KING_BIRD:
		poo_Property.imageHeight	=	ITEM_KING_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	ITEM_KING_BIRD_POO_WIDTH;
		poo_Property.speed			=	ITEM_KING_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	ITEM_KING_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	ITEM_KING_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	ITEM_KING_BIRD_POO_ZINDEX;
		poo_Property.type			=	ITEM_KING_BIRD_POO;
		break;
	case RED_OLD_BIRD:
		poo_Property.imageHeight	=	RED_OLD_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	RED_OLD_BIRD_POO_WIDTH;
		poo_Property.speed			=	RED_OLD_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	RED_OLD_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	RED_OLD_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	RED_OLD_BIRD_POO_ZINDEX;
		poo_Property.type			=	RED_OLD_BIRD_POO;
		break;
	case GREEN_OLD_BIRD:
		poo_Property.imageHeight	=	GREEN_OLD_BIRD_POO_HEIGHT;
		poo_Property.imageWidth		=	GREEN_OLD_BIRD_POO_WIDTH;
		poo_Property.speed			=	GREEN_OLD_BIRD_POO_SPEED;
		poo_Property.accel_speed	=	GREEN_OLD_BIRD_POO_ACCEL_SPEED;
		poo_Property.sprite_path	=	GREEN_OLD_BIRD_POO_SPRITE;
		poo_Property.zIndex			=	GREEN_OLD_BIRD_POO_ZINDEX;
		poo_Property.type			=	GREEN_OLD_BIRD_POO;
		break;
	default:
		break;
	}

	NNPoo* newPoo;
	newPoo = new NNPoo();
	newPoo->SetProperty( poo_Property );
	newPoo->SetPosition( birdPosition );
	m_Poo.push_back( newPoo );
	AddChild( newPoo );
}

void NNPooManager::Update( float dTime )
{
	NNObject::Update( dTime );
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
	if(m_Poo.empty())
		return false;

	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	//poo & player hitcheck
	struct HIT_RECT poo_rect, player_rect;

	bool hitCheck;
	ATTACK_STATUS attackStats =player->GetAttackStatus();
	switch ( attackStats )
	{
	case NORMAL:
		player_rect.left	=	player->GetPositionX() + 10;
		player_rect.right	=	player_rect.left + 45;
		player_rect.up		=	player->GetPositionY() + 63;
		player_rect.down	=	player_rect.up + 71;
		break;

	case DUAL_GUN:
		player_rect.left	=	player->GetPositionX();
		player_rect.right	=	player_rect.left + 45;
		player_rect.up		=	player->GetPositionY() + 13;
		player_rect.down	=	player_rect.up + 71;
		break;
	default:
		break;
	}

	player_rect.left	=	player->GetPositionX() + 10;
	player_rect.right	=	player_rect.left + 45;
	player_rect.up		=	player->GetPositionY() + 63;
	player_rect.down	=	player_rect.up + 50;

	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		auto pPoo_Iter = *poo_Iter;

		poo_rect.left	=	pPoo_Iter->GetPositionX();
		poo_rect.right	=	pPoo_Iter->GetPositionX() + pPoo_Iter->GetSpriteWidth();
		poo_rect.up		=	pPoo_Iter->GetPositionY();
		poo_rect.down	=	pPoo_Iter->GetPositionY() + pPoo_Iter->GetSpriteHeight();

		hitCheck = false;

		if( !poo_rect.HitCheck( player_rect ) )
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

bool NNPooManager::HitCheckByShield( NNAnimation* shield )
{
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	struct HIT_RECT poo_rect, shield_rect;

	shield_rect.left	=	shield->GetPositionX() - 3;
	shield_rect.right	=	shield_rect.left + 106;
	shield_rect.up		=	shield->GetPositionY();
	shield_rect.down	=	shield_rect.up + 110;

	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		auto pPoo_Iter = *poo_Iter;

		poo_rect.left	=	pPoo_Iter->GetPositionX();
		poo_rect.right	=	pPoo_Iter->GetPositionX() + pPoo_Iter->GetSpriteWidth();
		poo_rect.up		=	pPoo_Iter->GetPositionY();
		poo_rect.down	=	pPoo_Iter->GetPositionY() + pPoo_Iter->GetSpriteHeight();


		if( !poo_rect.HitCheck( shield_rect ) )
		{
			++poo_Iter;
			continue;
		}
		else
		{
			if (shield->IsVisible())
			{
				NNEffectManager::GetInstance()->MakePooBulletCrashEffect( pPoo_Iter->GetPosition() );
				NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_PooBoom[rand()%NNSoundManager::GetInstance()->SE_PooBoom.size()]);
				RemoveChild(pPoo_Iter);
			}
			return true;
		}
	}
	return false;
}

void NNPooManager::RemoveAll()
{
	std::list< NNPoo* >::iterator poo_Iter = m_Poo.begin();

	//poo & bound hitcheck
	for( poo_Iter = m_Poo.begin(); poo_Iter != m_Poo.end(); )
	{
		auto pBullet = *poo_Iter;
		// 리스트에서 삭제. 반환값은 다음 원소이다.
		//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
		poo_Iter =  m_Poo.erase( poo_Iter );	
		// 객체 해제
		RemoveChild(pBullet, true);
	}
}



