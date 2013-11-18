#include "NNBulletManager.h"
#include "NNBird.h"
#include "NNBirdFactory.h"


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

NNBulletManager::NNBulletManager(void)
{
}


NNBulletManager::~NNBulletManager(void)
{
}

void NNBulletManager::MakeBullet( BulletType type, NNPoint PlayerPosition )
{
	Bullet_PROPERTY bullet_property;

	switch ( type )
	{
	case NORMAL_BULLET:
		bullet_property.setImageHeight	=	NORMAL_BULLET_HEIGHT;
		bullet_property.setImageWidth	=	NORMAL_BULLET_WIDTH;
		bullet_property.speed			=	NORMAL_BULLET_SPEED;
		bullet_property.sprite_path		=	NORMAL_BULLET_SPRITE;
		bullet_property.zindex			=	NORMAL_BULLET_ZINDEX;
		bullet_property.type			=	NORMAL_BULLET;

		NNBullet* newBullet;
		newBullet = new NNBullet();

		newBullet->SetBulletProperty( bullet_property);
		newBullet -> SetPosition( PlayerPosition.GetX()+ GUN_WIDTH, PlayerPosition.GetY()  );
		m_Bullet.push_back( newBullet );
		AddChild( newBullet );

		break;
	default:
		break;
	}

}

void NNBulletManager::Update( float dTime )
{
	std::list< NNBullet* >::iterator bullet_Iter = m_Bullet.begin();
	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end(); ++bullet_Iter )
	{
		(*bullet_Iter) -> Update( dTime );
	}
	RemoveCheck();
}

void NNBulletManager::RemoveCheck()
{
	std::list< NNBullet* >::iterator bullet_Iter = m_Bullet.begin();
	
	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end(); )
	{
		if( (*bullet_Iter) -> GetPositionY() <= WINDOW_HEIGHT_UP_EDGE )
		{
 			auto pBullet = *bullet_Iter;

			// 리스트에서 삭제. 반환값은 다음 원소이다.
			//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
			bullet_Iter =  m_Bullet.erase( bullet_Iter );	

			// 객체 해제
			RemoveChild(pBullet,true);
		}
		else
		{
			++bullet_Iter;
		}
	}

	std::list< NNBird* >::iterator bird_Iter;
	std::list< NNBird* >& bird_list = NNBirdFactory::GetInstance()->GetBirdList();

	struct Hit_Rect bird_rect, bullet_rect;

	bool hitCheck;

  	for( bullet_Iter = m_Bullet.begin(); bullet_Iter != m_Bullet.end();  )
	{
		auto pBullet_Iter = *bullet_Iter;

		bullet_rect.left	=	pBullet_Iter->GetPositionX();
		bullet_rect.right	=	pBullet_Iter->GetPositionX() + pBullet_Iter->GetSpriteWidth();
		bullet_rect.up	=	pBullet_Iter->GetPositionY();
		bullet_rect.down	=	pBullet_Iter->GetPositionY() + pBullet_Iter->GetSpriteHeight();

		hitCheck = false;

		for( bird_Iter = bird_list.begin(); bird_Iter != bird_list.end(); )
		{
			auto pBird_Iter = *bird_Iter;

			bird_rect.left	=	pBird_Iter->GetPositionX();
			bird_rect.right	=	pBird_Iter->GetPositionX() + pBird_Iter->GetSpriteWidth();
			bird_rect.up	=	pBird_Iter->GetPositionY();
			bird_rect.down	=	pBird_Iter->GetPositionY() + pBird_Iter->GetSpriteHeight();

			if( bird_rect.right < bullet_rect.left || bird_rect.down < bullet_rect.up || bird_rect.left	> bullet_rect.right	||	bird_rect.up > bullet_rect.down )
			{
				++bird_Iter;
				continue;
			}
			else
			{
				bird_Iter = bird_list.erase( bird_Iter );
				NNBirdFactory::GetInstance()->RemoveChild( pBird_Iter, true );
				
				bullet_Iter = m_Bullet.erase( bullet_Iter );
				RemoveChild( pBullet_Iter );
				hitCheck = true;

				break;
			}
			
		}
		if( !hitCheck )
		{
			++bullet_Iter;
		}
	}
}
