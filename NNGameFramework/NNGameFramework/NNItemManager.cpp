#include "NNItemManager.h"
#include "NNPlayerCharacter.h"
#include "NNPlayerCharacterBottom.h"
#include "NNItem.h"
#include "NNSoundManager.h"


NNItemManager* NNItemManager::m_pInstance = nullptr;

NNItemManager::NNItemManager(void) : m_ItemType(ITEM_MAX_NUM)
{
}


NNItemManager::~NNItemManager(void)
{
}

NNItemManager* NNItemManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new NNItemManager();
	}
	return m_pInstance;
}

void NNItemManager::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNItemManager::Update( float dTime )
{
	NNObject::Update( dTime );
	RemoveCheck();
}

void NNItemManager::MakeItem( ITEM_TYPE itemType, NNPoint birdPosition, float scaleX )
{
	ITEM_PROPERTY itemProp;
	itemProp.imageWidth		=	ITEM_WIDTH;
	itemProp.imageHeight	=	ITEM_HEIGHT;
	itemProp.speed			=	ITEM_SPEED;
	itemProp.accel_speed	=	ITEM_ACCEL_SPEED;
	itemProp.zIndex			=	ITEM_ZINDEX;
	itemProp.type			=	itemType;

	switch (itemType)
	{
	case ITEM_DUAL_GUN:
		itemProp.sprite_path = ITEM_DUAL_GUN_SPRITE;
		break;
	case ITEM_FIRE_SHOOTER:
		itemProp.sprite_path = ITEM_FIRE_SHOOTER_SPRITE;
		break;
	case ITEM_SHOT_GUN:
		itemProp.sprite_path = ITEM_SHOT_GUN_SPRITE;
		break;
	case ITEM_CLEANER:
		itemProp.sprite_path = ITEM_CLEANER_SPRITE;
		break;
	case ITEM_SHIELD:
		itemProp.sprite_path = ITEM_SHIELD_SPRITE;
		break;
	case ITEM_MAX_NUM:
		break;
	default:
		break;
	}

	NNItem* newItem;
	newItem = new NNItem();
	newItem->SetProperty(itemProp);
	
	( scaleX == 1) ?
		newItem->SetPosition(birdPosition.GetX() - 50, birdPosition.GetY() + 20 ) :
		newItem->SetPosition(birdPosition.GetX() - 50, birdPosition.GetY() + 20 );

	m_ItemList.push_back(newItem);
	AddChild(newItem);
}

bool NNItemManager::HitCheck( NNPlayerCharacter* player )
{
	if(m_ItemList.empty())
		return false;

	std::list< NNItem* >::iterator item_Iter = m_ItemList.begin();

	struct HIT_RECT item_rect, player_rect;

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

	for( item_Iter = m_ItemList.begin(); item_Iter != m_ItemList.end(); )
	{
		auto pitem_Iter = *item_Iter;

		item_rect.left	=	pitem_Iter->GetPositionX();
		item_rect.right	=	pitem_Iter->GetPositionX() + pitem_Iter->GetWidth();
		item_rect.up	=	pitem_Iter->GetPositionY();
		item_rect.down	=	pitem_Iter->GetPositionY() + pitem_Iter->GetHeight();

		hitCheck = false;

		if( !item_rect.HitCheck( player_rect ) )
		{
			++item_Iter;
			continue;
		}
		else
		{
			printf("%d", pitem_Iter->GetItemType());
			SetItemType(pitem_Iter->GetItemType());

	//		if( pitem_Iter->GetItemType() == ITEM_CLEANER )
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_ItemGetSound[pitem_Iter->GetItemType()]);

			auto pItem = *item_Iter;
			item_Iter = m_ItemList.erase( item_Iter );


			RemoveChild(pItem, true);
			return true;
		}
	}
	return false;
}

void NNItemManager::RemoveCheck( void )
{
	std::list <NNItem*>::iterator item_Iter = m_ItemList.begin();

	for (item_Iter = m_ItemList.begin(); item_Iter != m_ItemList.end();)
	{
		if ((*item_Iter)->GetPositionY() >= RESOLUTION_HEIGHT - (*item_Iter)->GetHeight())
		{
			auto pItem = *item_Iter;

			item_Iter = m_ItemList.erase( item_Iter );
			RemoveChild(pItem, true);
		}
		else
		{
			++item_Iter;
		}
	}
}