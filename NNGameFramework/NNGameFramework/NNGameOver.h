#pragma once
#include "NNScene.h"

class NNSprite;
class NNLabel;
class NNGameOver : public NNScene
{
public:
	NNGameOver(void);
	NNGameOver( float timeScore , float waitTime);
	~NNGameOver(void);

	virtual void	Render();
	virtual void	Update( float dTime );

private:
	NNSprite*	m_pBackGround;
	NNLabel*			m_ElapsedPlayTimeLabel;
	wchar_t			m_PlayTimeString[20];
};



