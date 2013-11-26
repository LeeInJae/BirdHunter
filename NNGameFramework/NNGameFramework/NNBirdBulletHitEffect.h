#pragma once
#include "NNObject.h"
#include "BHDefine.h"
class NNSprite;

//새와 총알의 충돌 시 생기는 이펙트 클래스
class NNBirdBulletHitEffect : public NNObject
{
public:
	NNBirdBulletHitEffect(void);
	NNBirdBulletHitEffect(NNPoint birdPosition );
	~NNBirdBulletHitEffect(void);
	void Update( float dTime );
	void Render( );
	int GetCurrentFrame() { return m_CurrentFrame; }
	void SpriteSetPosition(NNPoint birdPosition);
protected:
	float		m_Sumtime;
	int			m_CurrentFrame;
	NNPoint		m_BirdPosition;
	NNSprite*	m_pSprite[ BIRD_BULLET_HIT_EFFECT_SIZE ];
	NNSprite*	m_pCurrentSprite;
};

