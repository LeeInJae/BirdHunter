#pragma once
#include "NNScene.h"
#include "NNPlayerCharacter.h"
#include "NNBird_A.h"
#include "NNBIRD_B.h"
#include "NNMap_A.h"
#include "NNPooManager.h"

class NNLabel;
class NNSprite;
//class NNPlayerCharacter; 왜이렇게 하면 안되지?
//헤더파일 추가하니까 됨
//리뷰 받을 것

// agebreak : CPP에 헤더 파일을 추가할것. 전방 선언하고 cpp에서 헤더파일을 추가하지 않으면, 참조할 수 없음

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

	NNLabel*			m_PlayTimeLabel;
	NNLabel*			m_LandedPooLabel;

	virtual void Render();
	virtual void Update( float dTime );
	void MovePlayerCharacter( float dTime );
	void MoveBird( float dTime );
	void MovePoo( float dTime );
	void MoveBullet( float dTime );
	float m_SumTime;
	wchar_t m_PlayTimeString[20];
	wchar_t m_LandedPooString[20];
};