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

	float	GetSpriteHeight()			{ return m_BirdProperty.imageHeight; }
	float	GetSpriteWidth()			{ return m_BirdProperty.imageWidth; }
	GOING_DIRECTION GetBirdDirection()	{ return m_BirdProperty.goingDirection; }
	float GetSumTime()					{ return m_SumTime; }
	BIRD_TYPE	GetBirdType()			{ return m_BirdProperty.type; }
	BIRD_PROPERTY	GetBirdProperty()		{ return m_BirdProperty; }
	void	Update( float dTime );

protected:
	float			m_SumTime;

	BIRD_PROPERTY	m_BirdProperty;

	float			m_BirdSpeed;
	float			m_MakePooCoolTime;

	GOING_DIRECTION	m_BirdDirection;
	BIRD_TYPE		m_Type;
	POO_TYPE		m_PooType;	
	float			m_SpriteHeight;
	float			m_SpriteWidth;
	//NNSprite*		m_pBird;
	NNAnimation*	m_pBird;
	int				m_Zindex;

};