#pragma once
#include "NNScene.h"
#include "NNPlayerCharacter.h"
#include "NNBird_A.h"
#include "NNBIRD_B.h"
#include "NNMap_A.h"
#include "NNPooManager.h"

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
	NNMap_A*			m_Map;
	NNPlayerCharacter*	m_Character;
	NNBird_A*			m_Bird;
	
	NNPooManager*		m_PooManager;
	virtual void Render();
	virtual void Update( float dTime );
	void MovePlayerCharacter( float dTime );
	void MoveBird( float dTime );
	void MovePoo( float dTime );
	void MoveBullet( float dTime );
	float m_SumTime;
};