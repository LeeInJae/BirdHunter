#include "NNEffectManager.h"
#include "BHDefine.h"

NNEffectManager* NNEffectManager::m_pInstance = nullptr;

NNEffectManager::NNEffectManager(void)
{
}


NNEffectManager::~NNEffectManager(void)
{
}

NNEffectManager* NNEffectManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new NNEffectManager();
	}
	return m_pInstance;
}

void NNEffectManager::ReleaseInstance()
{
	if( m_pInstance != NULL )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNEffectManager::Update( float dTime ) //시간체크 후 소멸.
{
	for( auto hitEffect_Iter : m_HitEffect )
	{
		hitEffect_Iter->Update( dTime );
	}
	RemoveHitEffectCheck();
}

void NNEffectManager::MakeHitEffect( NNPoint birdPosition )
{
	NNHitEffect* newEffect;
	newEffect = new NNHitEffect();
	newEffect->SetPosition( birdPosition );
	newEffect->SetScale(HIT_EFFECT_SCALE_X, HIT_EFFECT_SCALE_Y);
	newEffect->SetZindex( 0 );
	m_HitEffect.push_back( newEffect );
	AddChild( newEffect ); 
}

void NNEffectManager::RemoveHitEffectCheck()
{
	for( auto hitEffect_Iter = m_HitEffect.begin(); hitEffect_Iter != m_HitEffect.end(); )
	{
		if(  (*hitEffect_Iter)->GetLifeTime() >= HIT_EFFECT_LIFETIME )
		{
			auto pHitEffect = *hitEffect_Iter;

			hitEffect_Iter = m_HitEffect.erase( hitEffect_Iter );
			RemoveChild( pHitEffect, true );
		}
		else
		{
			++hitEffect_Iter;
		}
	}
}