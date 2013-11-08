#pragma once
#include "NNScene.h"

class NNSprite;

class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );

protected:
	NNSprite* m_pMap;
	NNSprite* m_pCharacter;

	virtual void Render();
	virtual void Update( float dTime );
};

