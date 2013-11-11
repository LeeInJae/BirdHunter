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
	NNSprite* GetPooSprite() { return m_pPoo; }

protected:
	bool m_CheckByPlayer;
	bool m_CheckByBullet;

	NNSprite*	m_pPoo;
	int			m_PooSpeed;
	int			m_PooLife;
};