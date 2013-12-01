#pragma once
#include "NNObject.h"
#include "NNPoint.h"
#include "BHDefine.h"
#include "NNBirdBulletCrashEffect.h"
#include "NNBullet.h"

//총알의 생성 및 충돌체크 등을 관리하는 매니져
class NNBulletManager : public NNObject
{
public:
	static NNBulletManager* GetInstance();
	static void				ReleaseInstance();
	void					MakeBullet( BULLET_TYPE type, NNPoint PlayerPosition );
	void					Update( float dTime );
	int						GetAmmoLeft(){return m_AmmoLeft;}
	
	std::list< NNBullet* >& GetBulletList() { return m_Bullet; }

private:
	NNBulletManager(void);
	~NNBulletManager(void);

	void RemoveCheck();
	void HitCheck();
	static NNBulletManager* m_pInstance;

	int m_AmmoLeft;
	std::list< NNBullet* > m_Bullet;
};