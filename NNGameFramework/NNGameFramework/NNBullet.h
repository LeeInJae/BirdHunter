#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"

class NNBullet : public NNObject
{

public:
	NNBullet(void);
	~NNBullet(void);
	void Update( float dTime );
	NNSprite* GetBullet() { return m_pBullet; }
	void SetBulletProperty( Bullet_PROPERTY bullet_property);
	float GetSpriteHeight() { return m_SpriteHeight; }
	float GetSpriteWidth() { return m_SpriteWidth; }

protected:
	
	bool		m_CheckByPoo;
	bool		m_CheckByBird;
	int			m_BulletSpeed;
	NNSprite*	m_pBullet;
	float		m_SpriteHeight;
	float		m_SpriteWidth;
	BulletType	m_Type;
};