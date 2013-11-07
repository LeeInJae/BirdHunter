#include "C2DFighterScene.h"
#include "NNSprite.h"
#include <wchar.h>


C2DFighterScene::C2DFighterScene(void)
{
	m_currentTime = 0.0f;
	m_pCurrentBG = NULL;
	m_pCurrentChar = NULL;

	CreateBG();
	CreateChar();
}


C2DFighterScene::~C2DFighterScene(void)
{
}

void C2DFighterScene::Render()
{
	NNObject::Render();
	
	if(m_pCurrentBG != NULL)
		m_pCurrentBG->Render();

	if(m_pCurrentChar)
		m_pCurrentChar->Render();
}

void C2DFighterScene::Update( float dTime )
{
	NNObject::Update(dTime);

	m_currentTime += dTime;
	int nFrame = 15 * 0.05 * m_currentTime;

	m_pCurrentBG = m_pBG[nFrame % 16];
	m_pCurrentChar = m_pChar[nFrame % 115];
}

void C2DFighterScene::CreateBG()
{
	WCHAR wszBuf[16] = {0,};
	for(int i = 0; i < 16; ++i)
	{
		swprintf_s(wszBuf, L"Frame%d.png",i);
		m_pBG[i] = NNSprite::Create(wszBuf);
		m_pBG[i]->SetImageWidth(1280);
		m_pBG[i]->SetImageHeight(720);
	}

	m_pCurrentBG = m_pBG[0];
}

void C2DFighterScene::CreateChar()
{
	WCHAR wszBuf[32] = {0,};
	for(int i = 0; i < 115; ++i)
	{
		swprintf_s(wszBuf, L"EA2_Frame%d.png",i);
		m_pChar[i] = NNSprite::Create(wszBuf);
		m_pChar[i]->SetImageWidth(1280);
		m_pChar[i]->SetImageHeight(720);
	}

	m_pCurrentChar = m_pChar[0];
}
