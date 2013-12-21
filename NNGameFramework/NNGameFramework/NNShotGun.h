#pragma once
#include "nneffect.h"

class NNSprite;

class NNShotGun :
	public NNEffect
{
public:
	NNShotGun(void);
	~NNShotGun(void);

	void	Update( float dTime );

private:
	float	m_ShotGunSpeed ;
	float	m_AccelSpeed;
	NNSprite* m_CheckBox;
};

