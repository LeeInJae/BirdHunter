#pragma once
#include "NNAnimation.h"
#include "NNScene.h"


//새와 총알의 충돌 이펙트 클래스
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