#pragma once
#include "NNObject.h"
#include "NNBirdBulletCrashEffect.h"
#include "BHDefine.h"

class NNBird;

//이펙트들을 관리하는 이펙트 매니져
class NNEffectManager : public NNObject
{
public:
	static NNEffectManager* GetInstance();
	static void ReleaseInstance();

	void Release();
	void Update( float dTime );
	void MakeBirdBulletCrashEffect(NNPoint birdPosition, BIRD_PROPERTY birdProperty, float scaleX );
	//void MakeBirdBulletCrashEffect( NNPoint birdPosition );
	void MakePooBulletCrashEffect( NNPoint pooPosition );
	void MakeAmorEffect( NNPoint playerPos, ATTACK_STATUS status, bool isLeft );
	std::list< NNEffect* >& GetEffectList(){ return m_HitEffect; }
private:
	NNEffectManager(void);
	~NNEffectManager(void);

	void RemoveEffectCheck();
	static NNEffectManager* m_pInstance;
	std::list< NNEffect* > m_HitEffect;
};