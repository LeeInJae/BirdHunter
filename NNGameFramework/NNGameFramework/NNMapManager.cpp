#include "NNMapManager.h"
#include "NNObject.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNPooManager.h"

NNMapManager* NNMapManager::m_pInstance = nullptr;

NNMapManager::NNMapManager(void) : m_CurrentWarningLV(0)
{	
	m_pMap=NNSprite::Create( MAP_DEFAULT_SPRITE );
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

void NNMapManager::Update(float dTime)
{

	// agebreak : 코드 리팩토링 필요
	int pollution = NNPooManager::GetInstance()->GetLandedPoo();
	
	if (pollution > POLLUTION_WARNING_LV_04 && m_CurrentWarningLV != POLLUTION_WARNING_LV_04)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( L"Image/mapWarning004.png" );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
		m_CurrentWarningLV = POLLUTION_WARNING_LV_04;
	}
	else if (pollution > POLLUTION_WARNING_LV_03 && m_CurrentWarningLV != POLLUTION_WARNING_LV_03)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( L"Image/mapWarning003.png" );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
		m_CurrentWarningLV = POLLUTION_WARNING_LV_03;
	}
	else if (pollution > POLLUTION_WARNING_LV_02 && m_CurrentWarningLV != POLLUTION_WARNING_LV_02)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( L"Image/mapWarning002.png" );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
		m_CurrentWarningLV = POLLUTION_WARNING_LV_02;
	}
	else if (pollution > POLLUTION_WARNING_LV_01 && m_CurrentWarningLV != POLLUTION_WARNING_LV_01)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( L"Image/mapWarning001.png" );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
		m_CurrentWarningLV = POLLUTION_WARNING_LV_01;
	}
	else if (pollution < POLLUTION_WARNING_LV_01 && m_CurrentWarningLV != 0)
	{
		RemoveChild(m_pMap);
		m_pMap = NNSprite::Create( L"Image/map.png" );
		m_pMap->SetImageWidth( RESOLUTION_WIDTH );
		m_pMap->SetImageHeight( RESOLUTION_HEIGHT );
		m_pMap->SetZindex( 0 );
		AddChild( m_pMap );
		m_CurrentWarningLV = 0;
	}
}