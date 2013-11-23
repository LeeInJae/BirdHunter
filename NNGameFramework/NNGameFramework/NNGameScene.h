#pragma once
#include "NNScene.h"
#include <vector>

class NNPlayerCharacter;
class NNMap_A;
class NNPooManager;
class NNMapManager;
class NNLabel;
class NNSprite;
class NNSound;
class NNAudioSystem;

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

	NNLabel*			m_PlayTimeLabel;
	NNLabel*			m_LandedPooLabel;
	NNLabel*			m_GameOverLabel;
	NNLabel*			m_FPSLabel;

	NNAudioSystem*			m_AudioPlayer;
	NNSound*				m_GameStartSE;
	std::vector<NNSound*>	m_BirdDieSE;

	virtual void	Render();
	virtual void	UIUpdate( float dTime );
	virtual void	Update( float dTime );
	void			UIInit();
	void			MovePlayerCharacter( float dTime );
	void			MoveBird( float dTime );
	void			MovePoo( float dTime );
	void			MoveBullet( float dTime );
	float			m_SumTime;
	
	wchar_t			m_PlayTimeString[20];
	wchar_t			m_LandedPooString[20];
	wchar_t			m_FPSString[200];
	wchar_t			m_GameOverString[20];

private:
	bool m_CheckGameOver;
};