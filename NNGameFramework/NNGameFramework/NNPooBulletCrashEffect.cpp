#include "NNPooBulletCrashEffect.h"
#include "NNAnimation.h"
#include "BHDefine.h"


NNPooBulletCrashEffect::NNPooBulletCrashEffect(void)
{
	m_LifeTime = POO_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME * POO_BULLET_HIT_EFFECT_SIZE;
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
	m_Animation->SetFrameTime( POO_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME );
	AddChild( m_Animation );
}

NNPooBulletCrashEffect::~NNPooBulletCrashEffect(void)
{
}