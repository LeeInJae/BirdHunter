#pragma once
#include "NNScene.h"
#include <vector>
#include "BHDefine.h"


class NNPlayerCharacter;
class NNMap_A;
class NNPooManager;
class NNMapManager;
class NNLabel;
class NNSprite;
class NNSoundManager;


struct BIRD_BORN_TIME
{
	BIRD_TYPE	birdType;
	float		bornTime;
	float		bornCoolTime;
};

//���� ������ ����ǰ� �ִ� ȭ��( ���� �� Ŭ����)
class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );
	
protected:

	NNMapManager*		m_Map;
	NNPlayerCharacter*	m_Character;
	NNPooManager*		m_PooManager;

	NNLabel*			m_TimeLabel;
	NNLabel*			m_ElapsedPlayTimeLabel;
	NNLabel*			m_PollutionLabel;
	NNLabel*			m_GameOverLabel;
	NNLabel*			m_FPSLabel;
	NNLabel*			m_AmmoLabel;

	NNSprite*			m_LandedPoo1;
	NNSprite*			m_LandedPoo2;
	NNSprite*			m_LandedPoo3;


	virtual void	Render();
	virtual void	UIUpdate( float dTime );
	virtual void	Update( float dTime );
	void			UIInit();
	
	float			m_SumTime;
	
	wchar_t			m_PlayTimeString[20];
	wchar_t			m_LandedPooString[20];
	wchar_t			m_FPSString[200];
	wchar_t			m_GameOverString[20];
	wchar_t			m_AmmoString[20];

private:
	bool m_CheckGameOver;
	bool m_CheckGameStart;
	bool m_CheckElapsedTenSec;
	BIRD_BORN_TIME m_BirdBornCheckArray[ BIRD_ALL_NUMBER ];
	float			m_PauseTime;
	float			m_GameSceneStartTime;
};