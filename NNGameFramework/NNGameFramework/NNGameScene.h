#pragma once
#include "NNScene.h"
#include "NNPlayerCharacter.h"

class NNSprite;
//class NNPlayerCharacter; 왜이렇게 하면 안되지?
//헤더파일 추가하니까 됨
//리뷰 받을 것

class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );

protected:
	NNSprite* m_pMap;
	NNPlayerCharacter m_pCharacter;
	
	virtual void Render();
	virtual void Update( float dTime );
	void MovePlayerCharacter( float dTime );
};

