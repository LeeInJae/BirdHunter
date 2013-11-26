#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;

// agebreak : 클래스위에는 클래스의 설명을 주석하는 다는것이 좋다
class NNBird : public NNObject
{
public:
	NNBird(void);
	~NNBird(void);
	
	void	SetBirdProperty( BIRD_PROPERTY bird_property );	// agebreak : 구조체를 인자로 받는 경우에는 참조로 받는것이 좋다. 

	float	GetSpriteHeight()	{ return m_SpriteHeight; }
	float	GetSpriteWidth()	{ return m_SpriteWidth; }
	GoingDirection GetBirdDirection() { return m_BirdDirection; }
	void	Update( float dTime );

protected:
	float			m_Toggle;
	float			m_SumTime;
	int				m_BirdSpeed;
	GoingDirection	m_BirdDirection;
	float			m_SpriteHeight;
	float			m_SpriteWidth;
	NNSprite*		m_pBird; //좌 우 이미지는 반전으로
	BirdType		m_Type;
	int				m_Zindex;
};