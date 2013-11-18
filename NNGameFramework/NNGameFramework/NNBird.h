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
//	void	SetBird( BirdType bir_type );

	float GetSpriteHeight() { return m_SpriteHeight; }
	float GetSpriteWidth() { return m_SpriteWidth; }
	
	//void			SetBirdDirection( GoingDirection newDirection ) { m_BirdDirection = newDirection; }
	//GoingDirection	GetBirdDirection() { return m_BirdDirection; }
	
	//NNSprite* GetBirdSprite( ) { return m_pBird; }

	// agebreak : Move �Լ��� �ƴ϶� Update()�� �������̵� �Ұ�. 
	// Update�� �ڵ����� Object���� ȣ��Ǳ� ������ �߰� ȣ���� �ʿ䰡 ����

	//void Move( float dTime );
	void Update( float dTime );
protected:
	float			m_Toggle;
	float			m_SumTime;

	//BIRD_PROPERTY	m_BirdProperty;

	int				m_BirdSpeed;
	GoingDirection	m_BirdDirection;
	float			m_SpriteHeight;
	float			m_SpriteWidth;
	NNSprite*		m_pBird; //�� �� �̹����� ��������
	BirdType		m_Type;
	int				m_Zindex;
};