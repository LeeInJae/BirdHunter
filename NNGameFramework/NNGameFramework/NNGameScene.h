#pragma once
#include "NNScene.h"
#include <vector>
#include "BHDefine.h"

class NNAnimation;
class NNPlayerCharacter;
class NNPlayerCharacterBottom;
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

//실제 게임이 실행되고 있는 화면( 게임 씬 클래스)
class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );
	
protected:

	NNMapManager*				m_Map;
	NNPlayerCharacter*			m_Character;
	NNPlayerCharacterBottom*	m_CharacterBottom;
	NNPooManager*				m_PooManager;
		
	NNLabel*			m_ElapsedPlayTimeLabel;
	NNLabel*			m_GameOverLabel;
	NNLabel*			m_FPSLabel;
	NNLabel*			m_AmmoLabel;

	NNSprite*			m_LandedPoo1;
	NNSprite*			m_LandedPoo2;
	NNSprite*			m_LandedPoo3;

	NNSprite*			m_GameOver;

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
	bool			m_CheckGameOver;
	bool			m_CheckGameStart;
	bool			m_CheckElapsedTenSec;
	BIRD_BORN_TIME	m_BirdBornCheckArray[ BIRD_ALL_NUMBER ];
	float			m_PauseTime;
	float			m_GameSceneStartTime;
	float			m_AppearTime;

	bool			m_CheckLodingAddChild;
	bool			m_CheckPlayingAddChild;
	NNAnimation*	m_PlayerCharacterAppear;
	NNAnimation*	m_PlayerCharacterDie;
};