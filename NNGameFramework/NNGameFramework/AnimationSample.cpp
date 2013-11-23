
#ifdef _DEBUG

#include "AnimationSample.h"

AnimationSample::AnimationSample()
{
	m_Animation = NNAnimation::Create( 2, L"Image/ITEM_BIRD_A.png",
		L"Image/ITEM_BIRD_B.png"
		);

	// 총 6장 애니메이션
	// 맨 앞이 텍스쳐 수, 뒤가 경로

	m_Animation->SetPosition( NNPoint(50.f,50.f) );

	// 행렬 연산 먹힘
	 
	AddChild( m_Animation );
}
AnimationSample::~AnimationSample()
{

}

void AnimationSample::Render()
{
	NNScene::Render();
}
void AnimationSample::Update( float eTime )
{
	NNScene::Update( eTime );
}

#endif