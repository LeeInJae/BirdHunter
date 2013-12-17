#include "NNItem.h"
#include "NNAnimation.h"
#include "NNSprite.h"
#include "NNPlayerCharacter.h"

NNItem::NNItem(void)
{
}


NNItem::~NNItem(void)
{
}

void NNItem::SetItemPosition( NNPoint BirdPosition )
{
	m_ItemSprite->SetPosition(BirdPosition);
}

void NNItem::SetProperty( ITEM_PROPERTY itemProp )
{
	m_Type = itemProp.type;
	m_DropSpeed = itemProp.speed;
	m_DropAccelSpeed = itemProp.accel_speed;
	m_Width = itemProp.imageWidth;
	m_Height = itemProp.imageHeight;
	m_Zindex = itemProp.zIndex;
	
	//m_ItemAnimation = itemProp.animation;
	m_ItemSprite = NNSprite::Create( itemProp.sprite_path );
	m_ItemSprite->SetImageWidth(m_Width);
	m_ItemSprite->SetImageHeight(m_Height);
	m_ItemSprite->SetZindex(m_Zindex);
	AddChild(m_ItemSprite);
}

void NNItem::Update( float dTime )
{
	if (GetPositionY() <= WINDOW_HEIGHT_DOWN_EDGE )
	{
		SetPosition( GetPositionX(), GetPositionY() + (m_DropSpeed * dTime));
	}
	m_DropSpeed += m_DropAccelSpeed;
}

//bool NNItem::HitCheck( NNPlayerCharacter* player )
//{
// 	struct HIT_RECT item_rect, player_rect;
// 
// 	bool hitCheck;
// 	ATTACK_STATUS attackStats =player->GetAttackStatus();
// 	switch ( attackStats )
// 	{
// 	case NORMAL:
// 		player_rect.left	=	player->GetPositionX() + 10;
// 		player_rect.right	=	player_rect.left + 45;
// 		player_rect.up		=	player->GetPositionY() + 63;
// 		player_rect.down	=	player_rect.up + 71;
// 		break;
// 
// 	case DUAL_GUN:
// 		player_rect.left	=	player->GetPositionX();
// 		player_rect.right	=	player_rect.left + 45;
// 		player_rect.up		=	player->GetPositionY() + 13;
// 		player_rect.down	=	player_rect.up + 71;
// 		break;
// 	default:
// 		break;
// 	}
// 
// 	player_rect.left	=	player->GetPositionX() + 10;
// 	player_rect.right	=	player_rect.left + 45;
// 	player_rect.up		=	player->GetPositionY() + 63;
// 	player_rect.down	=	player_rect.up + 50;
// 
// 	item_rect.left	=	m_ItemSprite->GetPositionX();
// 	item_rect.right	=	m_ItemSprite->GetPositionX() + m_Width;
// 	item_rect.up	=	m_ItemSprite->GetPositionY();
// 	item_rect.down	=	m_ItemSprite->GetPositionY() + m_Height;
// 
// 	hitCheck = false;
// 
// 	if( item_rect.HitCheck( player_rect ) )
// 	{
// 		return true;
// 	}
// 
// 	return false;
//}

