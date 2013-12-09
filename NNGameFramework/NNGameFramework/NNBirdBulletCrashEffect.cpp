#include "NNBirdBulletCrashEffect.h"
#include "NNAnimation.h"
#include "BHDefine.h"

NNBirdBulletCrashEffect::NNBirdBulletCrashEffect( void )
{
	m_LifeTime = BIRD_BULLET_HIT_EFFECT_SIZE * BIRD_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME;
	m_ElapsedTime = 0;

	m_Animation = NNAnimation::Create
		( 
		8, 
		BIRD_BULLET_HIT_EFFECT_SPRITE1,
		BIRD_BULLET_HIT_EFFECT_SPRITE2,
		BIRD_BULLET_HIT_EFFECT_SPRITE3,
		BIRD_BULLET_HIT_EFFECT_SPRITE4,
		BIRD_BULLET_HIT_EFFECT_SPRITE5,
		BIRD_BULLET_HIT_EFFECT_SPRITE6,
		BIRD_BULLET_HIT_EFFECT_SPRITE7,
		BIRD_BULLET_HIT_EFFECT_SPRITE8
		);

	m_Animation->SetFrameTime( BIRD_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME );
	AddChild( m_Animation );
}

NNBirdBulletCrashEffect::~NNBirdBulletCrashEffect(void)
{
}