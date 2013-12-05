#include "NNEffectManager.h"
#include "BHDefine.h"
#include "NNPooBulletCrashEffect.h"
#include "NNBird.h"

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
 	RemoveEffectCheck();
}

void NNEffectManager::RemoveEffectCheck()
{
	// Check BirdBulletHitEffect Remove, PooBulletHitEffect Remove
	for( auto hitEffect_Iter = m_HitEffect.begin(); hitEffect_Iter != m_HitEffect.end(); )
	{
		if(  (*hitEffect_Iter)->CheckLifeTime() )
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

//void NNEffectManager::MakeBirdBulletCrashEffect( NNPoint birdPosition )
void NNEffectManager::MakeBirdBulletCrashEffect( NNBird bird )
{
	NNBirdBulletCrashEffect* newHitEffect;

	newHitEffect = new NNBirdBulletCrashEffect();
	newHitEffect->SetPosition( bird.GetPosition() );
	newHitEffect->SetCenter( bird.GetSpriteWidth(), bird.GetSpriteHeight() );
	newHitEffect->SetZindex( 0 );
	
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}

void NNEffectManager::MakePooBulletCrashEffect( NNPoint pooPosition )
{
	NNPooBulletCrashEffect* newHitEffect;

	newHitEffect = new NNPooBulletCrashEffect();
 	pooPosition.SetX( pooPosition.GetX() );
 	pooPosition.SetY( pooPosition.GetY() );
	newHitEffect->SetPosition( pooPosition );
	newHitEffect->SetScale( POO_BULLET_HIT_EFFECT_SCALE_X, POO_BULLET_HIT_EFFECT_SCALE_Y );
	newHitEffect->SetZindex( 0 );
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}
