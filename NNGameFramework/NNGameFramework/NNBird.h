#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "BHDefine.h"



class NNBird : public NNObject
{
public:
	NNBird(void);
	~NNBird(void);
	
	void	SetBirdProperty( BIRD_PROPERTY bird_property );
	void	SetBirdSpeed( int speed )	{ m_BirdSpeed = speed; }
	int		GetBirdSpeed()				{ return m_BirdSpeed; }
	
	//void			SetBirdDirection( GoingDirection newDirection ) { m_BirdDirection = newDirection; }
	//GoingDirection	GetBirdDirection() { return m_BirdDirection; }
	
	//NNSprite* GetBirdSprite( ) { return m_pBird; }

	// agebreak : Move 함수가 아니라 Update()를 오버라이딩 할것. 
	// Update는 자동으로 Object에서 호출되기 때문에 추가 호출할 필요가 없음

	//void Move( float dTime );
	void Update( float dTime );
protected:
	int				m_BirdSpeed;
	GoingDirection	m_BirdDirection;
	float			m_Toggle;
	float			m_SumTime;
	bool			m_DeadCheck;
	bool			m_CheckByBullet;
	NNSprite*		m_pBird; //좌 우 이미지는 반전으로

};