#include "NNEffectManager.h"
#include "BHDefine.h"
#include "NNPooBulletCrashEffect.h"
#include "NNBird.h"
#include "NNFire.h"
#include "NNShotGun.h"

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
void NNEffectManager::MakeBirdBulletCrashEffect(NNPoint birdPosition, BIRD_PROPERTY birdProperty, float scaleX )
{
	NNBirdBulletCrashEffect* newHitEffect;
	newHitEffect = new NNBirdBulletCrashEffect(birdProperty.type);

	if( scaleX == -1)
	{
		birdPosition.SetX( birdPosition.GetX() - birdProperty.imageWidth );
	}
	newHitEffect->SetPosition( birdPosition.GetX() + birdProperty.imageWidth * 0.5f ,birdPosition.GetY() + birdProperty.imageHeight * 0.5f );

	newHitEffect->SetPosition( birdPosition.GetX() - 40.f ,birdPosition.GetY() - 40.f );

	switch( birdProperty.type )
	{
	case BLACK_SMALL_BIRD:
	case ORANGE_SMALL_BIRD:
	case WHITE_SMALL_BIRD:
	case RED_SMALL_BIRD:
		newHitEffect->SetScale( 0.8f, 0.8f );
		break;

	case BLACK_MID_BIRD:
	case CARAMEL_MID_BIRD:
	case GREEN_MID_BIRD:
	case ICE_MID_BIRD:
	case YELLOW_MID_BIRD:
		newHitEffect->SetScale( 1.0f, 1.0f );
		break;

	case BROWN_BIG_BIRD:
	case WHITE_BIG_BIRD:
	case PINK_BIG_BIRD:
	case ITEM_KING_BIRD:
	case RED_OLD_BIRD:
	case GREEN_OLD_BIRD:
		newHitEffect->SetScale( 1.3f, 1.3f );
		break;

	default:
		break;
	}
	newHitEffect->SetZindex( 0 );
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}

void NNEffectManager::MakePooBulletCrashEffect( NNPoint pooPosition )
{
	NNPooBulletCrashEffect* newHitEffect;

	newHitEffect = new NNPooBulletCrashEffect();
	pooPosition.SetX( pooPosition.GetX() - 30.f);
	pooPosition.SetY( pooPosition.GetY() - 30.f);
	newHitEffect->SetPosition( pooPosition );
	newHitEffect->SetScale( POO_BULLET_HIT_EFFECT_SCALE_X, POO_BULLET_HIT_EFFECT_SCALE_Y );
	newHitEffect->SetZindex( 0 );
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}

void NNEffectManager::MakeAmorEffect( NNPoint playerPos, ATTACK_STATUS status, bool isLeft )
{
	switch ( status )
	{
	case FIRE:
		NNFire* newEffect1;

		newEffect1 = new NNFire();
		( isLeft ) ? playerPos.SetX( playerPos.GetX() + 5.f) : playerPos.SetX( playerPos.GetX() - 25.f);

		playerPos.SetY( playerPos.GetY() - 80.f);
		newEffect1->SetPosition( playerPos );
		//newEffect1->SetScale( 2.f, 10.f );
		newEffect1->SetZindex( 0 );
		m_HitEffect.push_back( newEffect1 );
		AddChild( newEffect1 ); 
		break;

	case SHOT_GUN:
		NNShotGun* newEffect2;

		newEffect2 = new NNShotGun();
		( isLeft ) ? playerPos.SetX( playerPos.GetX() - 10.f) : playerPos.SetX( playerPos.GetX() - 45.f);

		playerPos.SetY( playerPos.GetY() - 280.f);
		newEffect2->SetPosition( playerPos );
		//newEffect1->SetScale( 2.f, 10.f );
		newEffect2->SetZindex( 0 );
		m_HitEffect.push_back( newEffect2 );
		AddChild( newEffect2 ); 
		break;
// 	case LIGHT:
// 		NNLight* newEffect2;
// 
// 		newEffect2 = new NNLight();
// 
// 		( isLeft ) ? playerPos.SetX( playerPos.GetX() + 23.f) : playerPos.SetX( playerPos.GetX() + 10.f);
// 
// 		playerPos.SetY( playerPos.GetY() - 450.f);
// 		newEffect2->SetPosition( playerPos );
// 		newEffect2->SetScale( 2.f, 1.8f );
// 		newEffect2->SetZindex( 0 );
// 		m_HitEffect.push_back( newEffect2 );
// 		AddChild( newEffect2 ); 
// 		break;
	default:
		break;
	}
}