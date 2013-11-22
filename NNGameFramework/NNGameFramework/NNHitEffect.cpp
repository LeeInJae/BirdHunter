#include "NNHitEffect.h"
#include "NNAnimation.h"


NNHitEffect::NNHitEffect(void)
{
	m_Animation = NNAnimation::Create( 8, L"Image/GREEN_BIRD_DIE_001.png",
		L"Image/GREEN_BIRD_DIE_002.png", 
		L"Image/GREEN_BIRD_DIE_003.png", 
		L"Image/GREEN_BIRD_DIE_004.png",
		L"Image/GREEN_BIRD_DIE_005.png",
		L"Image/GREEN_BIRD_DIE_006.png",
		L"Image/GREEN_BIRD_DIE_007.png",
		L"Image/GREEN_BIRD_DIE_008.png"
		);

	// �� 4�� �ִϸ��̼�
	// �� ���� �ؽ��� ��, �ڰ� ���

// 	m_Animation->SetPosition( NNPoint(50.f,50.f) );
// 	m_Animation->SetZindex( 0 );
	// ��� ���� ����
	m_LifeTime = 0.f;
	AddChild( m_Animation );
}

NNHitEffect::~NNHitEffect(void)
{
}

void NNHitEffect::Update( float dTime )
{
//	NNObject::Update( dTime );
	m_LifeTime += dTime;
}

// void NNHitEffect::Render()
// {
//  	NNObject::Render( );
// }