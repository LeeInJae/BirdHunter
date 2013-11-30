#pragma once
#include "NNObject.h"
#include "NNBirdBulletCrashEffect.h"
#include "BHDefine.h"

//����Ʈ���� �����ϴ� ����Ʈ �Ŵ���
class NNEffectManager : public NNObject
{
public:
	static NNEffectManager* GetInstance();
	static void ReleaseInstance();

	void Release();
	void Update( float dTime );
	
	void MakeBirdBulletCrashEffect( NNPoint birdPosition );
	void MakePooBulletCrashEffect( NNPoint pooPosition );

	std::list< NNEffect* >& GetEffectList(){ return m_HitEffect; }
private:
	NNEffectManager(void);
	~NNEffectManager(void);

	void RemoveEffectCheck();
	static NNEffectManager* m_pInstance;
	std::list< NNEffect* > m_HitEffect;
};