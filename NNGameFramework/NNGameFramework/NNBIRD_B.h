#pragma once
#include "NNBird.h"

class NNBIRD_B : public NNBird
{
public:
	NNBIRD_B(void);
	~NNBIRD_B(void);
	void Move( float dTime );
private:
	void InitBirdDirection();
};

