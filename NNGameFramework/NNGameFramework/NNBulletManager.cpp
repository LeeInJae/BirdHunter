#include "NNBulletManager.h"


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
	case Bullet_A:
		bullet_property.setImageHeight	=	NORMAL_BULLET_HEIGHT;
		bullet_property.setImageWidth	=	NORMAL_BULLET_WIDTH;
		bullet_property.speed			=	NORMAL_BULLET_SPEED;
		bullet_property.sprite_path		=	NORMAL_BULLET_SPRITE;
		bullet_property.zindex			=	NORMAL_BULLET_ZINDEX;

		NNBullet* newBullet;
		newBullet = new NNBullet();

		newBullet->SetBulletProperty( bullet_property);
		newBullet -> SetPosition( PlayerPosition );
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
	
	//반복자 이용 리스트에서 원소 삭제하는 것 에러 질문.(삭제하고 난 뒤 반복자가 바뀌는 듯)
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
}
