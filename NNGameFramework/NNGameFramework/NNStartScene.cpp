#include "NNStartScene.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNGameScene.h"
#include "NNSoundManager.h"

NNStartScene::NNStartScene(void)
{
	NNPoint	position;

	m_pBackGround=NNSprite::Create( BACKGROUND_SPRITE );
	m_pBackGround->SetImageWidth( RESOLUTION_WIDTH );
	m_pBackGround->SetImageHeight( RESOLUTION_HEIGHT );
	m_pBackGround->SetZindex( BACKGROUND_ZINDEX );

// 	NNSoundManager::GetInstance()->Play(NNSoundManager::GetInstance()->SE_SystemSound[GAMESTART]);
	NNSoundManager::GetInstance()->PlayAndGetChannel
		(NNSoundManager::GetInstance()->SE_SystemSound[STARTSCENEBGM], 
		&NNSoundManager::GetInstance()->m_BgmChannel);



// 	m_pTitle=NNSprite::Create( TITLE_SPRITE );
// 	m_pTitle->SetImageWidth( TITLE_WIDTH );
// 	m_pTitle->SetImageHeight( TITLE_HEIGHT );
// 	position.SetX( 0 );
// 	position.SetY( RESOLUTION_HEIGHT * 0.5 );
// 	m_pTitle->SetPosition( position );
// 	m_pTitle->SetZindex( TITLE_ZINDEX );

	m_pFilter = NNSprite::Create( TITLE_FILTER_SPRITE );
	m_pFilter->SetImageWidth( TITLE_FILTER_WIDTH );
	m_pFilter->SetImageHeight( TITLE_FILTER_HEIGHT );
	m_pFilter->SetZindex( TITLE_FILTER_ZINDEX );
	m_pFilter->SetOpacity( 0.5f );

	m_pStartString[ 0 ] = NNSprite::Create( STRING_P );
	m_pStartString[ 1 ] = NNSprite::Create( STRING_R );
	m_pStartString[ 2 ] = NNSprite::Create( STRING_E );
	m_pStartString[ 3 ] = NNSprite::Create( STRING_S );
	m_pStartString[ 4 ] = NNSprite::Create( STRING_S );
	m_pStartString[ 5 ] = NNSprite::Create( STRING_A );
	m_pStartString[ 6 ] = NNSprite::Create( STRING_N );
	m_pStartString[ 7 ] = NNSprite::Create( STRING_Y );
	m_pStartString[ 8 ] = NNSprite::Create( STRING_K );
	m_pStartString[ 9 ] = NNSprite::Create( STRING_E );
	m_pStartString[ 10 ] = NNSprite::Create( STRING_Y );

	float space = 0.f;

	for( int i=0; i<START_STRING_NUMBER; ++i )
	{
		m_pStartString[ i ]->SetImageHeight( START_STRING_HEIGHT );
		m_pStartString[ i ]->SetImageWidth( START_STRING_WIDTH );

		NNPoint position;

		( i == 5 || i == 8 ) ? space += 80.f : space += 40.f;

		position.SetX( RESOLUTION_WIDTH * 0.12f + space );
		position.SetY( RESOLUTION_HEIGHT - START_STRING_HEIGHT * 1.5f );
		m_pStartString[ i ]->SetPosition( position );
		m_pStartString[ i ]->SetZindex( START_STRING_ZINDEX );

		AddChild( m_pStartString[ i ] );
	}
	AddChild( m_pBackGround );
	AddChild( m_pFilter );
	//AddChild( m_pTitle );
	m_Sumtime	=	0;	
}


NNStartScene::~NNStartScene(void)
{
}

void NNStartScene::Render()
{
	NNScene::Render();
}

void NNStartScene::Update( float dTime )
{
	NNSoundManager::GetInstance()->Update(dTime);
	NNScene::Update( dTime );


	if ( m_Sumtime <= 1.0f )
	{
		m_Sumtime += dTime;
		for( int i=0; i<START_STRING_NUMBER; ++i )
		{
			NNPoint temp;
			temp.SetX( m_pStartString[i]->GetPositionX());
			temp.SetY( m_pStartString[i]->GetPositionY() - m_Sumtime*0.1f);
			m_pStartString[ i ]->SetPosition( temp );
		}
	}

	if( NNInputSystem::GetInstance()->PressedKeyCheck() )
	{
 		NNSoundManager::GetInstance()->Stop(NNSoundManager::GetInstance()->m_BgmChannel);
		NNSceneDirector::GetInstance()->ChangeScene( new NNGameScene() );
  		return;
	}
}