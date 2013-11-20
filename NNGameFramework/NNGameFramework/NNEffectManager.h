#pragma once
#include "NNObject.h"
#include "NNHitEffect.h"

class NNEffectManager : public NNObject
{
public:
	static NNEffectManager* GetInstance();
	static void ReleaseInstance();

	void Release();
	void Update( float dTime );
	void MakeHitEffect( NNPoint birdPosition );
	std::list< NNHitEffect* >& GetHitEffectList(){ return m_HitEffect; }

private:
	NNEffectManager(void);
	~NNEffectManager(void);

	void RemoveHitEffectCheck();
	static NNEffectManager* m_pInstance;
	std::list< NNHitEffect* > m_HitEffect;
};