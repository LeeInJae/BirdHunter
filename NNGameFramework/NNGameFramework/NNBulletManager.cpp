#include "NNBulletManager.h"
#include "NNBird.h"
#include "NNBirdFactory.h"
#include "NNPooManager.h"
#include "NNBirdBulletCrashEffect.h"
#include "NNPoo.h"
#include "NNEffectManager.h"
#include "NNSoundManager.h"

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

		newBullet->SetBulletProperty( bullet_property);
		newBullet->SetPosition( PlayerPosition.GetX()+ GUN_WIDTH, PlayerPosition.GetY() );
		m_Bullet.push_back( newBullet );
		AddChild( newBullet );
		--m_AmmoLeft;
	}
}

void NNBulletManager::Update( float dTime )
{
	NNObject::Update( dTime ); //�ڽ� ������Ʈ
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

			// ����Ʈ���� ����. ��ȯ���� ���� �����̴�.
			//�����ϰ� �ְ�, -> ���� �����ϰ�  �׻� �����̵Ǿ�� ��
			bullet_Iter =  m_Bullet.erase( bullet_Iter );	

			// ��ü ����
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

			bird_rect.left	=	pBird_Iter->GetPositionX();
			bird_rect.right	=	pBird_Iter->GetPositionX() + pBird_Iter->GetSpriteWidth();
			bird_rect.up	=	pBird_Iter->GetPositionY();
			bird_rect.down	=	pBird_Iter->GetPositionY() + pBird_Iter->GetSpriteHeight();


			switch( pBird_Iter->GetBirdType() )
			{
			case	BLACK_SMALL_BIRD:
				bird_rect.left	-=	25.f;
				bird_rect.right	=	bird_rect.left + 20.f;
				bird_rect.down -= 10.f;
				break;
			case	ORANGE_SMALL_BIRD:
				bird_rect.left	-=	30.f;
				bird_rect.right	=	bird_rect.left + 28.f;
				bird_rect.down -= 10.f;
				break;
			case	WHITE_SMALL_BIRD:
				bird_rect.left	-=	20.f;
				bird_rect.right	=	bird_rect.left + 30.f;
				bird_rect.down -= 10.f;
				break;
			case	RED_SMALL_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 50.f;
				bird_rect.down -= 10.f;
				break;
			case	BLACK_MID_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 35.f;
				bird_rect.down -= 20.f;
				break;
			case	CARAMEL_MID_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 35.f;
				bird_rect.down -= 20.f;
				break;
			case	GREEN_MID_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 35.f;
				bird_rect.down -= 20.f;
				break;
			case	ICE_MID_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 35.f;
				bird_rect.down -= 20.f;
				break;
			case	YELLOW_MID_BIRD:
				bird_rect.left	-=	45.f;
				bird_rect.right	=	bird_rect.left + 35.f;
				bird_rect.down -= 30.f;
				break;
			case	BROWN_BIG_BIRD:
				bird_rect.left	-=	70.f;
				bird_rect.right	=	bird_rect.left + 65.f;
				bird_rect.down -= 30.f;
				break;
			case	WHITE_BIG_BIRD:
				bird_rect.left	-=	70.f;
				bird_rect.right	=	bird_rect.left + 60.f;
				bird_rect.down -= 30.f;
				break;
			case	PINK_BIG_BIRD:
				bird_rect.left	-=	75.f;
				bird_rect.right	=	bird_rect.left + 65.f;
				bird_rect.down -= 30.f;
				break;
			case	ITEM_KING_BIRD:
				bird_rect.left	-=	75.f;
				bird_rect.right	=	bird_rect.left + 65.f;
				bird_rect.down -= 30.f;
				break;
			case	RED_OLD_BIRD:
				bird_rect.left	-=	65.f;
				bird_rect.right	=	bird_rect.left + 55.f;
				bird_rect.down -= 20.f;
				break;
			case	GREEN_OLD_BIRD:
				bird_rect.left	-=	65.f;
				bird_rect.right	=	bird_rect.left + 55.f;
				bird_rect.down -= 20.f;
				break;
			default:
				break;
			}

			if( !bullet_rect.HitCheck( bird_rect ) )
			{
				++bird_Iter;
				continue;
			}
			else
			{
				hitCheck = true;
				NNEffectManager::GetInstance()->MakeBirdBulletCrashEffect( pBird_Iter->GetPosition() );
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