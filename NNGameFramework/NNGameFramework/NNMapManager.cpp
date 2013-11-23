#include "NNMapManager.h"
#include "NNObject.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNPooManager.h"
#include "NNAudioSystem.h"

NNMapManager* NNMapManager::m_pInstance = nullptr;

NNMapManager::NNMapManager(void) : m_CurrentWarningLV(0), m_PrevWarningLV(0)
{	 
	SetMapContainer();
	SetWarningCount();
	m_pMap=NNSprite::Create( m_MapContainer[0] );
	m_pMap->SetImageWidth( RESOLUTION_WIDTH );
	m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap->SetZindex( 0 );
	AddChild( m_pMap );
}

NNMapManager::~NNMapManager(void)
{
}

NNMapManager* NNMapManager::GetInstance()
{
	if(m_pInstance == nullptr){
		m_pInstance = new NNMapManager;
	}
	return m_pInstance;
}

void NNMapManager::SetMapContainer( void )
{
	m_MapContainer.push_back(MAP_DEFAULT);
	m_MapContainer.push_back(MAP_WARNING_01);
	m_MapContainer.push_back(MAP_WARNING_02);
	m_MapContainer.push_back(MAP_WARNING_03);
	m_MapContainer.push_back(MAP_WARNING_04);
}


void NNMapManager::SetWarningCount( void )
{
	m_WarningCount.push_back(0);
	m_WarningCount.push_back(POLLUTION_WARNING_LV_01);
	m_WarningCount.push_back(POLLUTION_WARNING_LV_02);
	m_WarningCount.push_back(POLLUTION_WARNING_LV_03);
	m_WarningCount.push_back(POLLUTION_WARNING_LV_04);
}

void NNMapManager::Update(float dTime)
{
	pollution = NNPooManager::GetInstance()->GetLandedPoo();
	for (int i= 0; i < m_WarningCount.size(); ++i)
	{
		if (pollution > m_WarningCount[i])
		{
			m_PrevWarningLV = m_CurrentWarningLV;
			m_CurrentWarningLV = i;
		}
	}	
	if (m_PrevWarningLV != m_CurrentWarningLV)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( m_MapContainer[m_CurrentWarningLV] );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
	}

	if (pollution -1 == POLLUTION_WARNING_LV_04)
	{
		NNAudioSystem::GetInstance()->Play(SE_WARNING);
	}

// 	if (m_WarningLV+1 == m_MapContainer.size())
// 	{
// 		NNAudioSystem::GetInstance()->Play(SE_WARNING);
// 	}
// 	else
// 	{
// 		NNAudioSystem::GetInstance()->Stop(SE_WARNING);
// 	}


}


