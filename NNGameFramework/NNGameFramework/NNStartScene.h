#pragma once
#include "NNScene.h"
#include "BHDefine.h"

class NNSprite;

class NNStartScene :	public NNScene
{
public:
	NNStartScene(void);
	~NNStartScene(void);

	NNCREATE_FUNC( NNStartScene );
	virtual void	Render();
	virtual void	Update( float dTime );
	float GetStartSceneSumTime() { return m_Sumtime; }
private:
	NNSprite*		m_pBackGround;
	NNSprite*		m_pStartString[ START_STRING_NUMBER ];
	float			m_Sumtime;
};

