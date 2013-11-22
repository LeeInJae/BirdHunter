#pragma once
#include "NNAnimation.h"
#include "NNScene.h"

class NNHitEffect : public NNObject
{
public:
	NNHitEffect(void);
	virtual ~NNHitEffect(void);
	void Update( float dTime );
	float GetLifeTime() { return m_LifeTime; }
private:
	NNAnimation* m_Animation;
	float		 m_LifeTime;
};