#pragma once

#include "NNBird.h"
#include "NNPoo_A.h"
#include <list>

class NNBird_A : public NNBird
{
public:
	NNBird_A(void);
	~NNBird_A(void);
	void Move( float dTime );
private:
	void		InitBirdDirection();
	float m_SumTime;
};