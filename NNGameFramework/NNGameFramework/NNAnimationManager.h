#pragma once
#include "NNObject.h"

class NNAnimationManager : public NNObject
{
public:
	static NNAnimationManager* GetInstance();
	static void ReleaseInstance();

private:
	NNAnimationManager(void);
	~NNAnimationManager(void);
	static NNAnimationManager* m_pInstance;
};

