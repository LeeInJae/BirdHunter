#pragma once
#include "NNSprite.h"
#include "NNObject.h"

class NNMap : public NNObject
{
public:
	NNMap(void);
	~NNMap(void);
	
protected:
	NNSprite* m_pMap;
};