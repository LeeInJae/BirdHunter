#include "NNAnimationManager.h"

NNAnimationManager* NNAnimationManager::m_pInstance = nullptr;

NNAnimationManager::NNAnimationManager(void)
{
}


NNAnimationManager::~NNAnimationManager(void)
{
}

NNAnimationManager* NNAnimationManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new NNAnimationManager();
	}
	return m_pInstance;
}

void NNAnimationManager::ReleaseInstance()
{
	if( m_pInstance != NULL )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
