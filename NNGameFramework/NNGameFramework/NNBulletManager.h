#pragma once
#include "NNObject.h"
#include "NNPoint.h"
#include "BHDefine.h"
#include "NNBullet_A.h"

// enum BulletType
// {
// 	Bullet_A,
// 	Bullet_B,
// 	Bullet_C,
// };

class NNBulletManager : public NNObject
{
public:
	static NNBulletManager* GetInstance();
	static void				ReleaseInstance();
	void MakeBullet( BulletType type, NNPoint PlayerPosition );
	void Move( float dTime );

private:
	NNBulletManager(void);
	~NNBulletManager(void);

	void RemoveCheck();
	static NNBulletManager* m_pInstance;

	std::list< NNBullet_A* > m_Bullet_A;
};