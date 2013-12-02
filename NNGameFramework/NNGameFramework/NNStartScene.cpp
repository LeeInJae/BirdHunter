#include "NNStartScene.h"
#include "BHDefine.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNGameScene.h"

NNStartScene::NNStartScene(void)
{
	m_pBackGround=NNSprite::Create( BACKGROUND_SPRITE );
	m_pBackGround->SetImageWidth( RESOLUTION_WIDTH );
	m_pBackGround->SetImageHeight( RESOLUTION_HEIGHT );
	m_pBackGround->SetZindex( BACKGROUND_ZINDEX );

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
	NNScene::Update( dTime );
	

	if ( m_Sumtime <= 2 )
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
		NNSceneDirector::GetInstance()->ChangeScene( NNGameScene::Create() );
	}
}
