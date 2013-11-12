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
	switch ( type )
	{
	case Bullet_A:
		NNBullet_A* newBullet;
		newBullet = new NNBullet_A();
		newBullet -> SetPosition( PlayerPosition );
		m_Bullet_A.push_back( newBullet );
		AddChild( newBullet );
		break;
	default:
		break;
	}

}

void NNBulletManager::Move( float dTime )
{
	std::list< NNBullet_A* >::iterator bullet_A_Iter = m_Bullet_A.begin();
	for( bullet_A_Iter = m_Bullet_A.begin(); bullet_A_Iter != m_Bullet_A.end(); ++bullet_A_Iter )
	{
		(*bullet_A_Iter) -> Move( dTime );
	}
	RemoveCheck();
}

void NNBulletManager::RemoveCheck()
{
	std::list< NNBullet_A* >::iterator bullet_A_Iter = m_Bullet_A.begin();
	
	//반복자 이용 리스트에서 원소 삭제하는 것 에러 질문.(삭제하고 난 뒤 반복자가 바뀌는 듯)
	for( bullet_A_Iter = m_Bullet_A.begin(); bullet_A_Iter != m_Bullet_A.end(); )
	{
		if( (*bullet_A_Iter) -> GetPositionY() <= 0 )
		{
			auto pBullet = *bullet_A_Iter;

			// 리스트에서 삭제. 반환값은 다음 원소이다.
			//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
			bullet_A_Iter =  m_Bullet_A.erase( bullet_A_Iter );	

			// 객체 해제
			RemoveChild(pBullet);
		}
		else
		{
			++bullet_A_Iter;
		}
	}
}
