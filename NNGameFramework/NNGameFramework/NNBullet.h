#pragma once
#include "NNSprite.h"
#include "NNObject.h"
#include "BHDefine.h"

// �÷��̾ �߻��ϴ� �Ѿ� Ŭ����
class NNBullet : public NNObject
{

public:
	NNBullet(void);
	~NNBullet(void);
	void Update( float dTime );
	NNSprite* GetBullet() { return m_pBullet; }
	void SetBulletProperty( BULLET_PROPERTY bullet_property);
	float GetSpriteHeight() { return m_BulletProperty.imageHeight; }
	float GetSpriteWidth() { return m_BulletProperty.imageWidth; }

protected:
	BULLET_PROPERTY	m_BulletProperty;
	NNSprite*	m_pBullet;

	BULLET_TYPE	m_Type;
};