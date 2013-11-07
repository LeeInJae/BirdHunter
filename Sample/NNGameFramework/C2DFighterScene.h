#pragma once
#include "NNScene.h"

class NNSprite;

class C2DFighterScene : public NNScene
{
public:
	C2DFighterScene(void);
	~C2DFighterScene(void);

	virtual void Render();
	virtual void Update( float dTime );

protected:
	void CreateBG();
	void CreateChar();


protected:
	NNSprite*	m_pBG[16];
	NNSprite*	m_pCurrentBG;
	float		m_currentTime;
	NNSprite*	m_pChar[200];
	NNSprite*	m_pCurrentChar;

};

