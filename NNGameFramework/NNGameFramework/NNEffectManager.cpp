#include "NNEffectManager.h"
#include "BHDefine.h"
#include "NNBirdBulletHitEffect.h"
#include "NNPooBulletHitEffect.h"
#include "NNHitEffect.h"

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
	NNObject::Update( dTime );
 	RemoveHitEffectCheck();
}

void NNEffectManager::MakeBirdBulletHitEffect( NNPoint birdPosition, GOING_DIRECTION dir )
{
	NNBirdBulletHitEffect* newHitEffect;
	NNPoint hitEffectPosition = birdPosition;

	hitEffectPosition.SetY( birdPosition.GetY() - BIRD_BULLET_HIT_EFFECT_BALANCE_Y );
	hitEffectPosition.SetX( birdPosition.GetX() - BIRD_BULLET_HIT_EFFECT_BALANCE_X );

// 	( dir == RIGHT_GO)	? hitEffectPosition.SetX( birdPosition.GetX() - BIRD_BULLET_HIT_EFFECT_BALANCE_X ) 
// 							: hitEffectPosition.SetX( birdPosition.GetX() - 2*BIRD_BULLET_HIT_EFFECT_BALANCE_X );

	// agebreak : 생성된 히트이펙트는 어디서 해제해 주는가??
	newHitEffect = new NNBirdBulletHitEffect( hitEffectPosition );
	newHitEffect->SetZindex( 0 );
	m_BirdBulletHitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}

void NNEffectManager::MakePooBulletHitEffect( NNPoint pooPosition )
{
	NNPooBulletHitEffect* newHitEffect;
	NNPoint hitEffectPosition = pooPosition;
	// agebreak : 생성된 히트이펙트는 어디서 해제해 주는가??
	newHitEffect = new NNPooBulletHitEffect( hitEffectPosition );
	newHitEffect->SetZindex( 0 );
	m_PooBulletHitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}

void NNEffectManager::RemoveHitEffectCheck()
{
	// Check BirdBulletHitEffect
	for( auto hitEffect_Iter = m_BirdBulletHitEffect.begin(); hitEffect_Iter != m_BirdBulletHitEffect.end(); )
	{
		if(  (*hitEffect_Iter)->GetCurrentFrame() >= BIRD_BULLET_HIT_EFFECT_SIZE - 1 )
		{
			auto pHitEffect = *hitEffect_Iter;

			hitEffect_Iter = m_BirdBulletHitEffect.erase( hitEffect_Iter );
			RemoveChild( pHitEffect, true );
		}
		else
		{
			++hitEffect_Iter;
		}
	}
	// Check PooBulletHitEffect
	for( auto hitEffect_Iter = m_PooBulletHitEffect.begin(); hitEffect_Iter != m_PooBulletHitEffect.end(); )
	{
		if(  (*hitEffect_Iter)->GetCurrentFrame() >= POO_BULLET_HIT_EFFECT_SIZE - 1 )
		{
			auto pHitEffect = *hitEffect_Iter;

			hitEffect_Iter = m_PooBulletHitEffect.erase( hitEffect_Iter );
			RemoveChild( pHitEffect, true );
		}
		else
		{
			++hitEffect_Iter;
		}
	}
}


/*
void NNEffectManager::MakeHitEffect( NNPoint birdPosition )
{
	NNHitEffect* newHitEffect;
	NNPoint hitEffectPosition = birdPosition;

	// agebreak : 생성된 히트이펙트는 어디서 해제해 주는가??
	newHitEffect = new NNHitEffect();
	birdPosition.SetX( birdPosition.GetX() - 60 );
	birdPosition.SetY( birdPosition.GetY() - 60 );
	newHitEffect->SetPosition( birdPosition );
	newHitEffect->SetZindex( 0 );
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}
*/