#pragma once
#include "NNBirdBulletCrashEffect.h"
#include "NNEffect.h"
#include "BHDefine.h"

//새와 총알의 충돌 이펙트 클래스
class NNBirdBulletCrashEffect : public NNEffect
{
public:
	NNBirdBulletCrashEffect(void);
	NNBirdBulletCrashEffect( BIRD_TYPE type );
	virtual ~NNBirdBulletCrashEffect(void);
};