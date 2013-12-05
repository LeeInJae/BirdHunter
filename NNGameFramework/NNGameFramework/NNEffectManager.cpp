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
void NNEffectManager::MakeBirdBulletCrashEffect(NNPoint birdPosition, BIRD_PROPERTY birdProperty, float scaleX )
{
	NNBirdBulletCrashEffect* newHitEffect;
	newHitEffect = new NNBirdBulletCrashEffect();
	
	if( scaleX == -1)
	{
		birdPosition.SetX( birdPosition.GetX() - birdProperty.imageWidth );
	}
	newHitEffect->SetPosition( birdPosition.GetX() + birdProperty.imageWidth * 0.5,birdPosition.GetY() + birdProperty.imageHeight * 0.5 );
// 	if( birdProperty.goingDirection == LEFT_GO )
// 	{
// 		newHitEffect->SetPosition( birdPosition.GetX() - 50,birdPosition.GetY() - 50 );
// 	}
// 	else
// 	{
// 		newHitEffect->SetPosition( birdPosition.GetX() - 20,birdPosition.GetY() - 50 );
// 	}
// 	
	newHitEffect->SetPosition( birdPosition.GetX() - 50,birdPosition.GetY() - 50 );
	switch( birdProperty.type )
	{
	case BLACK_SMALL_BIRD:
		newHitEffect->SetScale( 1.0f, 1.0f );
		break;

	case ORANGE_SMALL_BIRD:
		newHitEffect->SetScale( 1.0f, 1.0f );
		break;
	case WHITE_SMALL_BIRD:
		newHitEffect->SetScale( 1.0f, 1.0f );
		break;
	case RED_SMALL_BIRD:
		newHitEffect->SetScale( 1.0f, 1.0f );
		break;

	case BLACK_MID_BIRD:
		newHitEffect->SetScale( 1.5f, 1.5f );
		break;
			
		case CARAMEL_MID_BIRD:
			newHitEffect->SetScale( 1.5f, 1.5f );
			break;

		case GREEN_MID_BIRD:
			newHitEffect->SetScale( 1.5f, 1.5f );
			break;
		case	ICE_MID_BIRD:
			newHitEffect->SetScale( 1.5f, 1.5f );
			break;
		case YELLOW_MID_BIRD:
			newHitEffect->SetScale( 1.5f, 1.2f );
			break;
		case BROWN_BIG_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
			break;
		case WHITE_BIG_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
			break;
		case PINK_BIG_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
			break;
		case ITEM_KING_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
			break;
		case RED_OLD_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
			break;
		case GREEN_OLD_BIRD:
			newHitEffect->SetScale( 1.8f, 1.8f );
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
 	pooPosition.SetX( pooPosition.GetX() );
 	pooPosition.SetY( pooPosition.GetY() );
	newHitEffect->SetPosition( pooPosition );
	newHitEffect->SetScale( POO_BULLET_HIT_EFFECT_SCALE_X, POO_BULLET_HIT_EFFECT_SCALE_Y );
	newHitEffect->SetZindex( 0 );
	m_HitEffect.push_back( newHitEffect );
	AddChild( newHitEffect ); 
}
