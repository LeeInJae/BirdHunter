#pragma once
#include "NNObject.h"
#include "NNHitEffect.h"
#include "BHDefine.h"
#include "NNBirdBulletHitEffect.h"
#include "NNPooBulletHitEffect.h"

class NNEffectManager : public NNObject
{
public:
	static NNEffectManager* GetInstance();
	static void ReleaseInstance();

	void Release();
	void Update( float dTime );
	void MakeBirdBulletHitEffect( NNPoint birdPosition, int birdWidth, int birdHeight, GoingDirection dir );
	void MakePooBulletHitEffect( NNPoint pooPosition, int pooWidth, int pooHeight);
	//std::list< NNHitEffect* >& GetHitEffectList(){ return m_HitEffect; }
	std::list< NNBirdBulletHitEffect* >& GetHitEffectList(){ return m_BirdBulletHitEffect; }
private:
	NNEffectManager(void);
	~NNEffectManager(void);

	void RemoveHitEffectCheck();
	static NNEffectManager* m_pInstance;
	std::list< NNBirdBulletHitEffect* > m_BirdBulletHitEffect;
	std::list< NNPooBulletHitEffect* > m_PooBulletHitEffect;
//	std::list< NNHitEffect* > m_HitEffect;
};