#pragma once
#include "NNSprite.h"
#include "NNObject.h"


class NNPoo : public NNObject
{
public:
	NNPoo(void);
	virtual ~NNPoo(void);

	void SetPoo( NNPoint BirdPosition );
	void Move( float dTime );
private:
	bool m_CheckByPlayer;
	bool m_CheckByBullet;

	NNSprite*	m_Poo;
	int			m_PooSpeed;
	int			m_PooLife;
};