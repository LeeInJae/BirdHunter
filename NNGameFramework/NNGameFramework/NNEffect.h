#pragma once
#include "NNObject.h"

class NNAnimation;

class NNEffect : public NNObject
{

public:
	NNEffect(void);
	~NNEffect(void);
	bool CheckLifeTime();
	void Update( float dTime );
protected:
	NNAnimation*	m_Animation;
	float			m_ElapsedTime;
	float			m_LifeTime;
};

