#pragma once
#include "NNBirdBulletCrashEffect.h"
#include "NNEffect.h"
#include "BHDefine.h"

//���� �Ѿ��� �浹 ����Ʈ Ŭ����
class NNBirdBulletCrashEffect : public NNEffect
{
public:
	NNBirdBulletCrashEffect(void);
	NNBirdBulletCrashEffect( BIRD_TYPE type );
	virtual ~NNBirdBulletCrashEffect(void);
};