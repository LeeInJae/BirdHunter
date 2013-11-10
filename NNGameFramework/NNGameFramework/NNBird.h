#pragma once
#include "NNObject.h"
#include "NNSprite.h"

//BirdCLass, Object�� ��ӹް�, has a Poo

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
	
	NNSprite* GetBirdSprite() { return m_pBird; }
	virtual void Move( float dTime );

protected:
	int		m_BirdSpeed;
	GoingDirection m_BirdDirection;
	NNSprite* m_pBird; //�� �� �̹��� 2�� ����
	NNSprite* m_pLeftBird;
	NNSprite* m_pRightBird;
	//bool	m_CheckEdge;
};