#include "NNHitEffect.h"


NNHitEffect::NNHitEffect(void)
{
	m_Animation = NNAnimation::Create( 4, L"Image/HitEffect/hit01.png",
		L"Image/HitEffect/hit02.png", 
		L"Image/HitEffect/hit03.png", 
		L"Image/HitEffect/hit04.png");

	// 총 4장 애니메이션
	// 맨 앞이 텍스쳐 수, 뒤가 경로

	//m_Animation->SetPosition( NNPoint(50.f,50.f) );

	// 행렬 연산 먹힘

	AddChild( m_Animation );
}


NNHitEffect::~NNHitEffect(void)
{
}

void NNHitEffect::Render()
{
	NNScene::Render();
}
void NNHitEffect::Update( float eTime )
{
	NNScene::Update( eTime );
}

void NNHitEffect::AnimationSetPosition( NNPoint animationPosition )
{
	m_Animation->SetPosition( animationPosition );
}