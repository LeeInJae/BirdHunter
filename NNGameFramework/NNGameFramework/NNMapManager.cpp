#include "NNMapManager.h"
#include "NNObject.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNPooManager.h"
#include "NNSoundManager.h"

NNMapManager* NNMapManager::m_pInstance = nullptr;

NNMapManager::NNMapManager(void) : m_CurrentWarningLV(0), m_PrevWarningLV(0), m_WarningFlag(true)
{	 
	SetWarningCount();
	m_MapContainer.push_back(MAP_DEFAULT);
	m_pMap=NNSprite::Create( m_MapContainer[0] );
	m_pMap->SetImageWidth( RESOLUTION_WIDTH );
	m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap->SetZindex( 0 );
	AddChild( m_pMap );
	m_WarningFilter = NNSprite::Create( WARNING_FILTER );
	m_WarningFilter->SetImageWidth(RESOLUTION_WIDTH);
	m_WarningFilter->SetImageHeight(RESOLUTION_HEIGHT);
	m_WarningFilter->SetZindex(1);
	m_WarningFilter->SetOpacity(0);
	AddChild(m_WarningFilter);
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
	m_Pollution = NNPooManager::GetInstance()->GetLandedPoo();
	for (int i= 0; i < (int)m_WarningCount.size(); ++i)
	{
		if (m_Pollution > m_WarningCount[i])
		{
			m_PrevWarningLV = m_CurrentWarningLV;
			m_CurrentWarningLV = i;
		}
	}	
	if (m_PrevWarningLV != m_CurrentWarningLV)
	{
		m_WarningFilter->SetOpacity(0.15f*m_CurrentWarningLV);
	}

	if (m_Pollution -1 == POLLUTION_WARNING_LV_04 && m_WarningFlag)
	{
		m_WarningFlag = false;
		NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_SystemSound[WARNING]);
	}
}


