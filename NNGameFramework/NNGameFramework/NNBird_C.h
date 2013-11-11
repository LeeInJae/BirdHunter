#pragma once
#include "NNBird.h"

class NNBird_C : public NNBird
{
public:
	NNBird_C(void);
	~NNBird_C(void);
	void Move( float dTime );
private:
	void InitBirdDirection();
};

