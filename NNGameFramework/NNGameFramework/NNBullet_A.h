#pragma once
#include "NNBullet.h"

class NNBullet_A : public NNBullet
{

public:
	NNBullet_A(void);
	~NNBullet_A(void);
	void Move( float dTime );
};