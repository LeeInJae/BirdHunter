#pragma once
#include "NNScene.h"
#include "NNPlayerCharacter.h"
#include "NNBird_A.h"
#include "NNBIRD_B.h"
#include "NNMap_A.h"
#include "NNPooManager.h"

class NNMapManager;
class NNLabel;
class NNSprite;
//class NNPlayerCharacter; ���̷��� �ϸ� �ȵ���?
//������� �߰��ϴϱ� ��
//���� ���� ��

// agebreak : CPP�� ��� ������ �߰��Ұ�. ���� �����ϰ� cpp���� ��������� �߰����� ������, ������ �� ����

class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );
	
protected:

	NNMapManager*		m_Map;
	NNPlayerCharacter*	m_Character;
	NNBird_A*			m_Bird;
	NNPooManager*		m_PooManager;

	NNLabel*			m_PlayTimeLabel;
	NNLabel*			m_LandedPooLabel;
	NNLabel*			m_GameOverLabel;
	NNLabel*			m_FPSLabel;

	virtual void Render();
	virtual void Update( float dTime );
	void MovePlayerCharacter( float dTime );
	void MoveBird( float dTime );
	void MovePoo( float dTime );
	void MoveBullet( float dTime );
	float m_SumTime;
	
	wchar_t m_PlayTimeString[20];
	wchar_t m_LandedPooString[20];
	wchar_t m_FPSString[200];
	wchar_t	m_GameOverString[20];

private:
	bool m_CheckGameOver;
};