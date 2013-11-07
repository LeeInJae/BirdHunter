
#pragma once

#include "NNObject.h"
#include "NNCamera.h"

/* */
/* NNScene
/* SceneDirector�� ��ϵ� �� �ִ� Scene ���
/* */

class NNScene : virtual public NNObject
{
public:
	NNScene();
	virtual ~NNScene();

	static NNScene* Create();

	virtual void Render();
	virtual void Update( float dTime );

	NNCamera& GetCamera() { return m_Camera; }

protected:
	NNCamera m_Camera;
};