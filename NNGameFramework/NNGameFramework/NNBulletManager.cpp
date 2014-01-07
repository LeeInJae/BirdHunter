#include "NNBulletManager.h"
#include "NNBird.h"
#include "NNBirdFactory.h"
#include "NNPooManager.h"
#include "NNBirdBulletCrashEffect.h"
#include "NNPoo.h"
#include "NNEffectManager.h"
#include "NNSoundManager.h"
#include "NNItemManager.h"

NNBulletManager* NNBulletManager::m_pInstance = nullptr;

NNBulletManager* NNBulletManager::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNBulletManager();
	}

	return m_pInstance;
}

void NNBulletManager::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

NNBulletManager::NNBulletManager(void) : m_AmmoLeft(10000)
{
	srand((unsigned)time(NULL));
}


NNBulletManager::~NNBulletManager(void)
{
}

void NNBulletManager::MakeBullet( BULLET_TYPE type, NNPoint PlayerPosition )
{
	if (m_AmmoLeft > 0)
	{
		BULLET_PROPERTY bullet_property;
		NNBullet* newBullet; 
		newBullet = new NNBullet();

		switch ( type )
		{
		case NORMAL_BULLET:
			bullet_property.imageHeight		=	NORMAL_BULLET_HEIGHT;
			bullet_property.imageWidth		=	NORMAL_BULLET_WIDTH;
			bullet_property.speed			=	NORMAL_BULLET_SPEED;
			bullet_property.sprite_path		=	NORMAL_BULLET_SPRITE;
			bullet_property.zIndex			=	NORMAL_BULLET_ZINDEX;
			bullet_property.type			=	NORMAL_BULLET;
			NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_NormalGunShot[rand()%NNSoundManager::GetInstance()->SE_NormalGunShot.size()]);
			break;
		default:
			break;
		}

		bullet_property.position.SetPoint( PlayerPosition.GetX()+ GUN_WIDTH, PlayerPosition.GetY() );
		newBullet->SetBulletProperty( bullet_property);
		newBullet->SetPosition( PlayerPosition.GetX()+ GUN_WIDTH, PlayerPosition.GetY() );
		m_Bullet.push_back( newBullet );
		AddChild( newBullet );
		--m_AmmoLeft;
	}
}

void NNBulletManager::Update( float dTime )
{
	NNObject::Update( dTime ); //자식 업데이트
	RemoveCheck();
	HitCheck();
}

void NNBulletManager::RemoveCheck()
{
	std::list< NNBullet* >::iterator bullet_Iter = m_Bullet.begin();

	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end(); )
	{
		if( (*bullet_Iter)->GetPositionY() <= WINDOW_HEIGHT_UP_EDGE )
		{
			auto pBullet = *bullet_Iter;

			// 리스트에서 삭제. 반환값은 다음 원소이다.
			//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
			bullet_Iter =  m_Bullet.erase( bullet_Iter );	

			// 객체 해제
			RemoveChild(pBullet,true);
			++m_AmmoLeft;
		}
		else
		{
			++bullet_Iter;
		}
	}
}

void NNBulletManager::HitCheck()
{

	//Bird & Bullet Hitcheck
	std::list< NNBullet* >::iterator bullet_Iter = m_Bullet.begin();
	std::list< NNBird* >::iterator bird_Iter;
	std::list< NNBird* >& bird_list = NNBirdFactory::GetInstance()->GetBirdList();

	struct HIT_RECT bird_rect, bullet_rect;

	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end();  )
	{
		auto pBullet_Iter = *bullet_Iter;

		bool hitCheck = false;

		bullet_rect.left	=	pBullet_Iter->GetPositionX();
		bullet_rect.right	=	pBullet_Iter->GetPositionX() + pBullet_Iter->GetSpriteWidth();
		bullet_rect.up		=	pBullet_Iter->GetPositionY();
		bullet_rect.down	=	pBullet_Iter->GetPositionY() + pBullet_Iter->GetSpriteHeight();

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
					
					NNItemManager::GetInstance()->MakeItem(static_cast<ITEM_TYPE>(rand()%ITEM_MAX_NUM), pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
					
					//NNItemManager::GetInstance()->MakeItem(ITEM_DUAL_GUN, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
					//NNItemManager::GetInstance()->MakeItem(ITEM_FIRE_SHOOTER, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
					
					//NNItemManager::GetInstance()->MakeItem(ITEM_SHOT_GUN, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
					
					//NNItemManager::GetInstance()->MakeItem(ITEM_SHIELD, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
					//NNItemManager::GetInstance()->MakeItem(ITEM_CLEANER, pBird_Iter->GetPosition(), pBird_Iter->GetScaleX() );
				}
				

				NNEffectManager::GetInstance()->MakeBirdBulletCrashEffect( pBird_Iter->GetPosition(), pBird_Iter->GetBirdProperty(), scaleX );
				bird_Iter = bird_list.erase( bird_Iter );
				NNBirdFactory::GetInstance()->RemoveChild( pBird_Iter, true ); 
				NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_BirdDie[rand()%NNSoundManager::GetInstance()->SE_BirdDie.size()]);
				++m_AmmoLeft;

				break;
			}
		}

		if( hitCheck )
		{
			bullet_Iter = m_Bullet.erase( bullet_Iter );
			RemoveChild( pBullet_Iter, true );
		}
		else
		{
			++bullet_Iter;
		}
	}

	//bullet & poo hitcheck

	std::list< NNPoo* >::iterator poo_Iter;
	std::list< NNPoo* >& poo_list = NNPooManager::GetInstance()->GetPooList();

	struct HIT_RECT poo_rect;

	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end();  )
	{
		bool hitCheck = false;
		auto pBullet_Iter = *bullet_Iter;

		bullet_rect.left	=	pBullet_Iter->GetPositionX();
		bullet_rect.right	=	pBullet_Iter->GetPositionX() + pBullet_Iter->GetSpriteWidth();
		bullet_rect.up		=	pBullet_Iter->GetPositionY();
		bullet_rect.down	=	pBullet_Iter->GetPositionY() + pBullet_Iter->GetSpriteHeight();

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

				++m_AmmoLeft;
				break;
			}
		}

		if( hitCheck )
		{
			bullet_Iter = m_Bullet.erase( bullet_Iter );
			RemoveChild( pBullet_Iter, true );
		}
		else
		{
			++bullet_Iter;
		}
	}
}