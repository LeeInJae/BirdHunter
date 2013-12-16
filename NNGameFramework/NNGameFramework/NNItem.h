#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNAnimation;
class NNSprite;

class NNItem :
	public NNObject
{
public:
	NNItem(void);
	~NNItem(void);

	void SetItemPosition( NNPoint BirdPosition );
	void SetProperty( ITEM_PROPERTY itemProp);

	void Update( float dTime );
	float GetWidth(void) {return m_Width;}
	float GetHeight(void) {return m_Height;}

private:
	//NNAnimation*	m_ItemAnimation;
	NNSprite*		m_ItemSprite;
	float			m_DropSpeed;
	float			m_DropAccelSpeed;
	int				m_Zindex;
	ITEM_TYPE		m_Type;
	float			m_Width;
	float			m_Height;
};

