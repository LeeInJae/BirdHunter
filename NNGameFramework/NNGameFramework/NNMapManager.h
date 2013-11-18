#pragma once
#include "NNObject.h"

class NNSprite;

class NNMapManager :
	public NNObject
{
public:
	static NNMapManager* GetInstance();
	~NNMapManager(void);
	void Update(float dTime);

protected:
	NNMapManager(void);


	NNSprite* m_pMap;

private:
	static NNMapManager* m_pInstance;
};

