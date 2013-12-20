#include "NNEffect.h"


NNEffect::NNEffect(void)
{
}


NNEffect::~NNEffect(void)
{
}

bool NNEffect::CheckLifeTime()
{
	if( m_ElapsedTime >= m_LifeTime )
		return true;
	return false;
}

void NNEffect::Update( float dTime )
{
	NNObject::Update( dTime );
	m_ElapsedTime += dTime;
}