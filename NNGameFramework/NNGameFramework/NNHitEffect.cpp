#include "NNHitEffect.h"
#include "NNAnimation.h"

NNHitEffect::NNHitEffect( void )
{
	m_Animation = NNAnimation::Create( 8, 
		L"BIRD_BULLET_HIT_EFFECT_SPRITE1",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE2",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE3",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE4",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE5",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE6",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE7",
		L"BIRD_BULLET_HIT_EFFECT_SPRITE8"
		);

	m_LifeTime = 0.f;
	AddChild( m_Animation );
}

NNHitEffect::~NNHitEffect(void)
{
}

void NNHitEffect::Update( float dTime )
{
	NNObject::Update( dTime ); //ADDCHILD한 놈의 업데이트
	m_LifeTime += dTime;

// 	m_Animation->SetVisible( true );
// 
// 	else
// 
// 	m_Animation->SetVisible( false );
// 
// 	m_Animation->Set
}
