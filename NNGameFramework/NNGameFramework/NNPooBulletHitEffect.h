#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;

// ¶Ë°ú ÃÑ¾ËÀÇ È÷Æ® ÀÌÆåÆ® Å¬·¡½º
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
	NNSprite*	m_pSprite[POO_BULLET_HIT_EFFECT_SIZE];
	NNSprite*	m_pCurrentSprite;
};

