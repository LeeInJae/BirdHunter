
#pragma once

#include "NNObject.h"

/* */
/* NNScene
/* SceneDirector�� ��ϵ� �� �ִ� Scene ���
/* */

class NNScene : virtual public NNObject
{
public:
	NNScene(){}
	virtual ~NNScene(){}

public:
	static NNScene* Create() { 
		NNScene* pInstance = new NNScene();
		return pInstance;
	}

	void Render(){}
	void Update( float dTime ){}
};