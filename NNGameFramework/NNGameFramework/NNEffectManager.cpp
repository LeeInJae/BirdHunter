#include "NNEffectManager.h"
#include "BHDefine.h"
#include "NNBirdBulletHitEffect.h"
#include "NNPooBulletHitEffect.h"

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
	// agebreak : AddChild를 했으면, 부모의 Update를 호출하면 되지 않는가??

	// Update BirdBulletHitEffect
	for( auto hitEffect_Iter : m_BirdBulletHitEffect )
	{
		hitEffect_Iter->Update( dTime );
	}

	// Update PooBulletHitEffect
	for( auto hitEffect_Iter : m_PooBulletHitEffect )
	{
		hitEffect_Iter->Update( dTime );
	}
	RemoveHitEffectCheck();
}

void NNEffectManager::MakeBirdBulletHitEffect( NNPoint birdPosition, int birdWidth, int birdHeight, GoingDirection dir )
{
	NNBirdBulletHitEffect* newHItEffect;
//	newHItEffect = new NNBirdBulletHitEffect( birdPosition );

	NNPoint hitEffectPosition = birdPosition;

	if( dir == RIGHT_GO)
	{
		hitEffectPosition.SetX( birdPosition.GetX() - Bird_Bullet_HIT_EFFECT_BALACE_X );
		hitEffectPosition.SetY( birdPosition.GetY() - Bird_Bullet_HIT_EFFECT_BALACE_Y );
	}
	else
	{
		hitEffectPosition.SetX( birdPosition.GetX() - 2*Bird_Bullet_HIT_EFFECT_BALACE_X );
		hitEffectPosition.SetY( birdPosition.GetY() - Bird_Bullet_HIT_EFFECT_BALACE_Y );
	}

	// agebreak : 생성된 히트이펙트는 어디서 해제해 주는가??
	newHItEffect = new NNBirdBulletHitEffect( hitEffectPosition );
	//newHItEffect->SetPosition( hitEffectPosition );
	//newHItEffect->SetScale( Bird_Bullet_HIT_EFFECT_SCALE_X, Bird_Bullet_HIT_EFFECT_SCALE_Y );
	newHItEffect->SetZindex( 0 );
	m_BirdBulletHitEffect.push_back( newHItEffect );
	AddChild( newHItEffect ); 
}

void NNEffectManager::RemoveHitEffectCheck()
{
	// Check BirdBulletHitEffect
	for( auto hitEffect_Iter = m_BirdBulletHitEffect.begin(); hitEffect_Iter != m_BirdBulletHitEffect.end(); )
	{
		if(  (*hitEffect_Iter)->GetCurrentFrame() >= Bird_Bullet_HiT_Effect_Size - 1 )
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
		if(  (*hitEffect_Iter)->GetCurrentFrame() >= Poo_Bullet_HiT_Effect_Size - 1 )
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
// 	for( auto hitEffect_Iter = m_HitEffect.begin(); hitEffect_Iter != m_HitEffect.end(); )
// 	{
// 		if(  (*hitEffect_Iter)->GetLifeTime() >= HIT_EFFECT_LIFETIME )
// 		{
// 			auto pHitEffect = *hitEffect_Iter;
// 
// 			hitEffect_Iter = m_HitEffect.erase( hitEffect_Iter );
// 			RemoveChild( pHitEffect, true );
// 		}
// 		else
// 		{
// 			++hitEffect_Iter;
// 		}
// 	}
}

void NNEffectManager::MakePooBulletHitEffect( NNPoint pooPosition, int pooWidth, int pooHeight )
{
	NNPooBulletHitEffect* newHItEffect;
	NNPoint hitEffectPosition = pooPosition;

// 	hitEffectPosition.SetX( pooPosition.GetX() - HIT_EFFECT_BALACE_X );
// 	hitEffectPosition.SetX( pooPosition.GetY() - HIT_EFFECT_BALACE_Y );
	
	// agebreak : 생성된 히트이펙트는 어디서 해제해 주는가??
	newHItEffect = new NNPooBulletHitEffect( hitEffectPosition );
	//newHItEffect->SetPosition( hitEffectPosition );
	//newHItEffect->SetScale( Poo_Bullet_HIT_EFFECT_SCALE_X, Poo_Bullet_HIT_EFFECT_SCALE_Y );
	newHItEffect->SetZindex( 0 );
	m_PooBulletHitEffect.push_back( newHItEffect );
	AddChild( newHItEffect ); 
}