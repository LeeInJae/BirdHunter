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

protected:
	bool m_CheckByPlayer;
	bool m_CheckByBullet;

	NNSprite*	m_pPoo;
	int			m_PooSpeed;
	int			m_PooLife;
};