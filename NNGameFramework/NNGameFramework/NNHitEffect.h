#pragma once
#include "NNAnimation.h"
#include "NNScene.h"

class NNHitEffect : public NNScene
{
public:
	NNHitEffect(void);
	virtual ~NNHitEffect(void);
	void AnimationSetPosition( NNPoint animationPosition );
	void Render();
	void Update( float eTime );

private:
	NNAnimation* m_Animation;
};

