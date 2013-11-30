#include "NNPooBulletCrashEffect.h"
#include "NNAnimation.h"
#include "BHDefine.h"


NNPooBulletCrashEffect::NNPooBulletCrashEffect(void)
{
	m_LifeTime = POO_BULLET_HIT_EFFECT_LIFETIME;
	m_ElapsedTime = 0;

	m_Animation = NNAnimation::Create
		( 
		6, 
		POO_BULLET_HIT_EFFECT_SPRITE1,
		POO_BULLET_HIT_EFFECT_SPRITE2,
		POO_BULLET_HIT_EFFECT_SPRITE3,
		POO_BULLET_HIT_EFFECT_SPRITE4,
		POO_BULLET_HIT_EFFECT_SPRITE5,
		POO_BULLET_HIT_EFFECT_SPRITE6
		);

	AddChild( m_Animation );
}

NNPooBulletCrashEffect::~NNPooBulletCrashEffect(void)
{
}