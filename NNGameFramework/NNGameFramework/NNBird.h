#pragma once
#include "NNObject.h"
#include "NNSprite.h"

//BirdCLass, Object를 상속받고, has a Poo

 enum GoingDirection
 {
 	LEFT_GO,
 	RIGHT_GO,
};

class NNBird : public NNObject
{
public:
	NNBird(void);
	virtual ~NNBird(void);
	
	void	SetBirdSpeed( int speed )	{ m_BirdSpeed = speed; }
	int		GetBirdSpeed()				{ return m_BirdSpeed; }
	
	void	SetBirdDirection( GoingDirection newDirection ) { m_BirdDirection = newDirection; }
	GoingDirection GetBirdDirection() { return m_BirdDirection; }
	
	NNSprite* GetBirdSprite( ) { return m_pBird; }
	void Move( float dTime );

protected:
	int		m_BirdSpeed;
	GoingDirection m_BirdDirection;
	int		m_Toggle;
	bool	m_DeadCheck;
	NNSprite* m_pBird; //좌 우 이미지는 반전으로
};