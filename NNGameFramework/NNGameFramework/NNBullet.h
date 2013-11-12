#pragma once
#include "NNSprite.h"
#include "NNObject.h"

class NNBullet : public NNObject
{

public:
	NNBullet(void);
	~NNBullet(void);
	void Move( float dTime );
	NNSprite* GetBullet() { return m_pBullet; }
protected:
	bool		m_CheckByPoo;
	bool		m_CheckByBird;

	int			m_BulletSpeed;
	NNSprite*	m_pBullet;
};