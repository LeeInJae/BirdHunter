#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;

class NNPooBulletHitEffect : public NNObject
{
public:
	NNPooBulletHitEffect(void);
	NNPooBulletHitEffect(NNPoint pooPosition);
	~NNPooBulletHitEffect(void);
public:
	void Update( float dTime );
	void Render( );
	int	 GetCurrentFrame() { return m_CurrentFrame; }
	void SpriteSetPosition(NNPoint pooPosition);
protected:
	float		m_Sumtime;
	int			m_CurrentFrame;
	NNPoint		m_PooPosition;
	NNSprite*	m_pSprite[Poo_Bullet_HiT_Effect_Size];
	NNSprite*	m_pCurrentSprite;
};

