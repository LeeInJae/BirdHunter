#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"


class NNPoo : public NNObject
{
public:
	NNPoo(void);
	~NNPoo(void);

	void SetPoo( NNPoint BirdPosition );
	void SetProperty( POO_PROPERTY poo_property );
	
	void Update( float dTime );
	float GetSpriteHeight() { return m_SpriteHeight; }
	float GetSpriteWidth() { return m_SpriteWidth; }

protected:
	NNSprite*	m_pPoo;
	int			m_PooSpeed;
	int			m_PooLife;
	int			m_Zindex;
	PooType		m_Type;
	float		m_SpriteHeight;
	float		m_SpriteWidth;
};