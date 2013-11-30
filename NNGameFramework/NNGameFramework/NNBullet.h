#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"

// 플레이어가 발사하는 총알 클래스
class NNBullet : public NNObject
{

public:
	NNBullet(void);
	~NNBullet(void);
	void Update( float dTime );
	NNSprite* GetBullet() { return m_pBullet; }
	void SetBulletProperty( BULLET_PROPERTY bullet_property);
	float GetSpriteHeight() { return m_SpriteHeight; }
	float GetSpriteWidth() { return m_SpriteWidth; }

protected:
	float			m_BulletSpeed;
	NNSprite*	m_pBullet;
	float		m_SpriteHeight;
	float		m_SpriteWidth;
	BULLET_TYPE	m_Type;
};