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
	NNBullet_A* newBullet;
	newBullet = new NNBullet_A;
	newBullet -> SetPosition( PlayerPosition );
	m_Bullet_A.push_back( newBullet );
	AddChild( newBullet );
}

void NNBulletManager::Move( float dTime )
{
	std::list< NNBullet_A* >::iterator bullet_A_Iter = m_Bullet_A.begin();
	for( bullet_A_Iter = m_Bullet_A.begin(); bullet_A_Iter != m_Bullet_A.end(); ++bullet_A_Iter )
	{
		(*bullet_A_Iter) -> Move( dTime );
	}
}