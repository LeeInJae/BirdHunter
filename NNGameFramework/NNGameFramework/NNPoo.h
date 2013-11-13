#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"


class NNPoo : public NNObject
{
public:
	NNPoo(void);
	~NNPoo(void);

	void SetPoo( NNPoint BirdPosition );
	void SetProperty( POO_PROPERTY poo_property );
	void Update( float dTime );

protected:
	bool m_CheckByPlayer;
	bool m_CheckByBullet;

	NNSprite*	m_pPoo;
	int			m_PooSpeed;
	int			m_PooLife;
};