#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;

//몬스터 '새' 클래스

class NNBird : public NNObject
{
public:
	NNBird(void);
	~NNBird(void);
	
	void	SetBirdProperty( BIRD_PROPERTY &bird_property );

	float	GetSpriteHeight()	{ return m_SpriteHeight; }
	float	GetSpriteWidth()	{ return m_SpriteWidth; }
	GOING_DIRECTION GetBirdDirection() { return m_BirdDirection; }
	void	Update( float dTime );

protected:
	float			m_Toggle;
	float			m_SumTime;
	int				m_BirdSpeed;
	GOING_DIRECTION	m_BirdDirection;
	float			m_SpriteHeight;
	float			m_SpriteWidth;
	NNSprite*		m_pBird;
	BIRD_TYPE		m_Type;
	int				m_Zindex;
};