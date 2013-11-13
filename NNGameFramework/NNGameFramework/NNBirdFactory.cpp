#include "NNBirdFactory.h"

NNBirdFactory* NNBirdFactory::m_pInstance = nullptr;

NNBirdFactory::NNBirdFactory(void)
{

}

NNBirdFactory::~NNBirdFactory(void)
{

}

NNBirdFactory* NNBirdFactory::GetInstance()
{
	if( m_pInstance == nullptr )
	{
		m_pInstance = new NNBirdFactory();
		return m_pInstance;
	}
	return m_pInstance;
}

void NNBirdFactory::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNBirdFactory::MakeBird( BirdType type )
{
	NNPoint BirdSetPosition;

	BIRD_PROPERTY bird_Property;

	BirdSetPosition.SetX( (float) (rand() % BIRD_SET_MAX_WIDTH ) );
	BirdSetPosition.SetY( (float) (rand() % BIRD_SET_MAX_HEIGHT) );

	int checkDirection = rand() % 2;

	( checkDirection == 0 ) ? bird_Property.goingDirection = LEFT_GO : bird_Property.goingDirection = RIGHT_GO;

	switch ( type )
	{
	case NORMAL_BIRD:
		if( bird_Property.goingDirection == LEFT_GO )
			bird_Property.sprite_path =  NORMAL_BIRD_LEFT_SPRITE;
		else
			bird_Property.sprite_path = NORMAL_BIRD_RIGHT_SPRITE;

		bird_Property.speed = NORMAL_BIRD_SPEED;
		bird_Property.setImageHeight = NORMAL_BIRD_HEIGHT;
		bird_Property.setImageWidth = NORMAL_BIRD_WIDTH;
		bird_Property.zindex = 2;

		NNBird* p_newBird;

		p_newBird = new NNBird();
		p_newBird->SetBirdProperty( bird_Property );
		p_newBird->SetPosition( BirdSetPosition );
		m_Bird.push_back( p_newBird );
		
		AddChild( p_newBird );

		break;
	//case Bird_B:
		//break;
	//case Bird_C:
		//break;
	default:
		break;
	}
}

void NNBirdFactory::Move( float dTime )
{
	if( !m_Bird.empty() )
	{
		std::list< NNBird* >::iterator bird_A_Iter = m_Bird.begin();
		for( bird_A_Iter = m_Bird.begin(); bird_A_Iter != m_Bird.end(); ++bird_A_Iter )
		{
			(*bird_A_Iter) -> Move( dTime );
		}
	}
	RemoveCheck();
}

void NNBirdFactory::RemoveCheck() //충돌체크 구현하면서 없애 주어야 함
{
// 	for (auto& iter=m_Bird_A.begin(); iter!=m_Bird_A.end(); iter++ )
// 	{
// 		if (1)
// 		{
// 			m_Bird_A.erase( iter );
// 			RemoveChild(*iter, true);
// 			break;
// 		}
// 	}
}
