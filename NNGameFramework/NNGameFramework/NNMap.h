#pragma once
#include "NNScene.h"

class NNSprite;

class NNMap : public NNScene
{
public:
	NNMap(void);
	~NNMap(void);
	
	NNCREATE_FUNC( NNMap );

protected:
	NNSprite* m_pMap;
	virtual void Render();
	virtual void Update( float dTime );
};

