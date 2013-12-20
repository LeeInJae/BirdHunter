
#ifdef _DEBUG

#include "AnimationSample.h"

AnimationSample::AnimationSample()
{
	m_Animation = NNAnimation::Create( 2, L"Image/ITEM_BIRD_A.png",
		L"Image/ITEM_BIRD_B.png"
		);

	// �� 6�� �ִϸ��̼�
	// �� ���� �ؽ��� ��, �ڰ� ���

	m_Animation->SetPosition( NNPoint(50.f,50.f) );

	// ��� ���� ����
	 
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