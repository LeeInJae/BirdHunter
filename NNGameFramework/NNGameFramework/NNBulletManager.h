#pragma once
#include "NNObject.h"
#include "NNPoint.h"
#include "BHDefine.h"
#include "NNHitEffect.h"
#include "NNBullet.h"

//�Ѿ��� ���� �� �浹üũ ���� �����ϴ� �Ŵ���
class NNBulletManager : public NNObject
{
public:
	static NNBulletManager* GetInstance();
	static void				ReleaseInstance();
	void					MakeBullet( BULLET_TYPE type, NNPoint PlayerPosition );
	void					Update( float dTime );
	
	std::list< NNBullet* >& GetBulletList() { return m_BulletList; }

private:
	NNBulletManager(void);
	~NNBulletManager(void);

	void RemoveCheck();
	void HitCheck();
	static NNBulletManager* m_pInstance;

	std::list< NNBullet* > m_BulletList;

};