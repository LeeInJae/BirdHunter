#include "NNGameScene.h"
#include "NNSprite.h"
#include "BHDefine.h"
#include "NNInputSystem.h"

NNGameScene::NNGameScene(void )
{
	m_pMap = NNSprite::Create( L"Image/map.png" );
	m_pMap -> SetImageWidth( RESOLUTION_WIDTH );
	m_pMap -> SetImageHeight( RESOLUTION_HEIGHT );
	m_pMap ->SetZindex( 0 );

	AddChild( m_pMap );
	AddChild( m_Character.GetCharacterSprite() );
	AddChild( m_Bird.GetBirdSprite() );
	if( m_Bird.GetPooSprite() )
		AddChild( m_Bird.GetPooSprite() );
}


NNGameScene::~NNGameScene(void)
{
}

void NNGameScene::Update( float dTime )
{
	NNScene::Update( dTime );
	//printf(" %f ", dTime );
	//dTime�� Ȱ�� �����ϱ�
	
	if( m_Bird.GetPooSprite() )
		AddChild( m_Bird.GetPooSprite() );

// 	while(1)
// 	{
// 		bool flag = false;
// 
// 		std::list< NNPoo_A* >::iterator pooIter;
// 		for( pooIter = m_Bird.m_Bird_A_Poo.begin(); pooIter != m_Bird.m_Bird_A_Poo.end(); ++pooIter )
// 		{
// 			if ( (( (*pooIter)->GetPooSprite() ) -> GetPositionY() ) >= 100 )
// 			{
// 				RemoveChild( (*pooIter)->GetPooSprite(), true );
// 				m_Bird.m_Bird_A_Poo.erase( pooIter );
// 				flag = true;
// 				break;
// 			}
// 		}
// 
// 		if( flag == false )
// 		{
// 			break;
// 		}
// 	}
	MovePlayerCharacter( dTime );
	MoveBird( dTime );
}

void NNGameScene::Render()
{
	NNScene::Render();
}

void NNGameScene::MovePlayerCharacter( float dTime )
{
	m_Character.Move( dTime );
}

void NNGameScene::MoveBird( float dTime )
{
	m_Bird.Move( dTime );
}