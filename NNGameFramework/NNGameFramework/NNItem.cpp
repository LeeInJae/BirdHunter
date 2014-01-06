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


