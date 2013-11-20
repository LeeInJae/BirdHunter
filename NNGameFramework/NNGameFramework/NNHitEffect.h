#pragma once
#include "NNAnimation.h"
#include "NNScene.h"

class NNHitEffect : public NNScene
{
public:
	NNHitEffect(void);
	virtual ~NNHitEffect(void);
	void AnimationSetPosition( NNPoint animationPosition );
	void Update( float dTime );
	float GetLifeTime() { return m_LifeTime; }
	void Render();

	
private:
	NNAnimation* m_Animation;
	float		 m_LifeTime;
};

