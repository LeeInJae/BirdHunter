#pragma once

#include "NNBird.h"

class NNBird_A : public NNBird
{
public:
	NNBird_A(void);
	~NNBird_A(void);
	void Move( float dTime );
private:
	void InitBirdDirection();
//	void BirdUpdate( float dTime );
};

