#pragma once
#include "NNObject.h"
#include "NNHitEffect.h"
#include "BHDefine.h"
#include "NNBirdBulletHitEffect.h"
#include "NNPooBulletHitEffect.h"

//����Ʈ���� �����ϴ� ����Ʈ �Ŵ���
class NNEffectManager : public NNObject
{
public:
	static NNEffectManager* GetInstance();
	static void ReleaseInstance();

	void Release();
	void Update( float dTime );
	void MakeBirdBulletHitEffect( NNPoint birdPosition, GOING_DIRECTION dir );
	void MakePooBulletHitEffect( NNPoint pooPosition );
	
	//void MakeHitEffect( NNPoint birdPosition, GOING_DIRECTION dir );
	
	std::list< NNBirdBulletHitEffect* >& GetHitEffectList(){ return m_BirdBulletHitEffect; }
private:
	NNEffectManager(void);
	~NNEffectManager(void);

	void RemoveHitEffectCheck();
	static NNEffectManager* m_pInstance;
	std::list< NNBirdBulletHitEffect* > m_BirdBulletHitEffect;
	std::list< NNPooBulletHitEffect* > m_PooBulletHitEffect;
	
	std::list< NNHitEffect* > m_HitEffect;
};