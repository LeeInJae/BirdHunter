#include "NNFire.h"
#include "NNAnimation.h"
#include "BHDefine.h"
#include "NNBird.h"
#include "NNBirdFactory.h"
#include "NNItemManager.h"
#include "NNEffectManager.h"
#include "NNSoundManager.h"
#include "NNPoo.h"
#include "NNPooManager.h"
#include "NNSprite.h"


NNFire::NNFire(void)
{
	m_LifeTime = 0.07f * 15;
	m_ElapsedTime = 0;
	m_FireSpeed = 10;
	m_AccelSpeed  = 5;
	m_Animation = NNAnimation::Create
		( 
		0.05, 52*2,52*2,15,
		FIRE01,FIRE02,FIRE03,FIRE04,FIRE05,FIRE06,FIRE07,FIRE08,FIRE09,FIRE10,
		FIRE11,FIRE12,FIRE13,FIRE14,FIRE15 );
	m_Animation->SetFrameTime( 0.07f);
	m_CheckBox=NNSprite::Create(L"Image/RECT.png");
	//AddChild(m_CheckBox);
	AddChild(m_Animation);
}

NNFire::~NNFire(void)
{
}

void NNFire::Update( float dTime )
{
	NNEffect::Update( dTime );

	
	//////////////////////////////////
	//Bird & Bullet Hitcheck
	std::list< NNBird* >::iterator bird_Iter;
	std::list< NNBird* >& bird_list = NNBirdFactory::GetInstance()->GetBirdList();

	struct HIT_RECT bird_rect, bullet_rect;


	bool hitCheck = false;

	bullet_rect.left	=	GetPositionX() + 25;
	bullet_rect.right	=	bullet_rect.left + 54;
	bullet_rect.up		=	GetPositionY() + 16;
	bullet_rect.down	=	bullet_rect.up + 100;
	///////////
	if( GetPositionY() >= WINDOW_HEIGHT_UP_EDGE - 25  ) 
	{
		SetPosition( GetPositionX(), GetPositionY() - m_FireSpeed * dTime );
	}
	else if( GetPositionY() < WINDOW_HEIGHT_UP_EDGE - 25  || bullet_rect.up <= WINDOW_HEIGHT_UP_EDGE )
	{
		RemoveChild(m_Animation, true);
		return;
	}

	m_FireSpeed += m_AccelSpeed;
	/////////
// 	m_CheckBox->SetImageWidth( 54 );
// 	m_CheckBox->SetImageHeight( 73 );
// 
// 	m_CheckBox->SetPosition(bullet_rect.left, bullet_rect.up	 );
	for( bird_Iter = bird_list.begin(); bird_Iter != bird_list.end(); )
	{
		auto pBird_Iter = *bird_Iter;

		if( pBird_Iter->GetScaleX() == 1)
		{
			bird_rect.left	=	pBird_Iter->GetPositionX();
			bird_rect.right	=	pBird_Iter->GetPositionX() + pBird_Iter->GetSpriteWidth();
			bird_rect.up	=	pBird_Iter->GetPositionY();
			bird_rect.down	=	pBird_Iter->GetPositionY() + pBird_Iter->GetSpriteHeight();
		}
		else
		{
			bird_rect.left	=	pBird_Iter->GetPositionX() - pBird_Iter->GetSpriteWidth();
			bird_rect.right	=	pBird_Iter->GetPositionX();
			bird_rect.up	=	pBird_Iter->GetPositionY();
			bird_rect.down	=	pBird_Iter->GetPositionY() + pBird_Iter->GetSpriteHeight();
		}
		if( !bullet_rect.HitCheck( bird_rect ) )
		{
			++bird_Iter;
			continue;
		}
		else
		{
			hitCheck = true;
			float scaleX = pBird_Iter->GetScaleX();

			if( pBird_Iter->GetBirdType() == ITEM_KING_BIRD )
			{
				NNItemManager::GetInstance()->MakeItem(ITEM_DUAL_GUN, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
			}


			NNEffectManager::GetInstance()->MakeBirdBulletCrashEffect( pBird_Iter->GetPosition(), pBird_Iter->GetBirdProperty(), scaleX );
			bird_Iter = bird_list.erase( bird_Iter );
			NNBirdFactory::GetInstance()->RemoveChild( pBird_Iter, true ); 
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_BirdDie[rand()%NNSoundManager::GetInstance()->SE_BirdDie.size()]);
			//++m_AmmoLeft;
			break;
		}
	}

	//bullet & poo hitcheck

	std::list< NNPoo* >::iterator poo_Iter;
	std::list< NNPoo* >& poo_list = NNPooManager::GetInstance()->GetPooList();

	struct HIT_RECT poo_rect;

	//bool hitCheck = false;

// 	bullet_rect.left	=	GetPositionX() + 15;
// 	bullet_rect.right	=	GetPositionX() + 26*2;
// 	bullet_rect.up		=	GetPositionY() + 17;
// 	bullet_rect.down	=	GetPositionY() + 22*2;

	for( poo_Iter = poo_list.begin(); poo_Iter != poo_list.end(); )
	{
		auto pPoo_Iter = *poo_Iter;

		poo_rect.left	=	pPoo_Iter->GetPositionX();
		poo_rect.right	=	pPoo_Iter->GetPositionX() + pPoo_Iter->GetSpriteWidth();
		poo_rect.up		=	pPoo_Iter->GetPositionY();
		poo_rect.down	=	pPoo_Iter->GetPositionY() + pPoo_Iter->GetSpriteHeight();

		if( !bullet_rect.HitCheck( poo_rect ) )
		{
			++poo_Iter;
			continue;
		} 
		else
		{
			hitCheck = true;

			NNEffectManager::GetInstance()->MakePooBulletCrashEffect( pPoo_Iter->GetPosition() );

			poo_Iter = poo_list.erase( poo_Iter );
			NNPooManager::GetInstance()->RemoveChild( pPoo_Iter, true );
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_PooBoom[rand()%NNSoundManager::GetInstance()->SE_PooBoom.size()]);

			break;
		}
	}
	RemoveCheck();
}

void NNFire::RemoveCheck()
{

}
