#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"

//새가 누는 똥을 정의하는 클래스
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
	float		m_PooSpeed;
	float		m_PooAccelSpeed;
	int			m_PooLife;
	int			m_Zindex;
	POO_TYPE	m_Type;
	float		m_SpriteHeight;
	float		m_SpriteWidth;
};