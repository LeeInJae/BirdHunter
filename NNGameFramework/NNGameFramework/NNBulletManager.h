#pragma once
#include "NNObject.h"
#include "NNPoint.h"
#include "BHDefine.h"
#include "NNBullet_A.h"

class NNBulletManager : public NNObject
{
public:
	static NNBulletManager* GetInstance();
	static void				ReleaseInstance();
	void MakeBullet( BulletType type, NNPoint PlayerPosition );
	void Update( float dTime );
	std::list< NNBullet* > GetBulletList() { return m_Bullet; }

private:
	NNBulletManager(void);
	~NNBulletManager(void);

	void RemoveCheck();
	static NNBulletManager* m_pInstance;

	std::list< NNBullet* > m_Bullet;
};