
#ifdef _DEBUG

#include "CameraSample.h"

CameraSample::CameraSample()
{
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);
	GetCamera().SetZoom( 2.f ); // �� 2��

	// ī�޶� ȭ���� �߽����� �� 0.f, 0.f�� ȭ���� �߾����� ���Ե�

	m_Sprite = NNSprite::Create(L"Resources/Texture/walk_0.png");
	AddChild(m_Sprite);
}
CameraSample::~CameraSample()
{

}

void CameraSample::Render()
{
	NNScene::Render();
}
void CameraSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif