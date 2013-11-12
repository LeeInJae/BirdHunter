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
	~NNBird(void);
	
	void	SetBirdSpeed( int speed )	{ m_BirdSpeed = speed; }
	int		GetBirdSpeed()				{ return m_BirdSpeed; }
	
	void	SetBirdDirection( GoingDirection newDirection ) { m_BirdDirection = newDirection; }
	GoingDirection GetBirdDirection() { return m_BirdDirection; }
	
	NNSprite* GetBirdSprite( ) { return m_pBird; }

	// agebreak : Move �Լ��� �ƴ϶� Update()�� �������̵� �Ұ�. 
	// Update�� �ڵ����� Object���� ȣ��Ǳ� ������ �߰� ȣ���� �ʿ䰡 ����
	void Move( float dTime );

protected:
	int		m_BirdSpeed;
	GoingDirection m_BirdDirection;
	float		m_Toggle;
	bool	m_DeadCheck;
	bool	m_CheckByBullet;
	NNSprite* m_pBird; //�� �� �̹����� ��������
};