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
	BirdSetPosition.SetX( (float) (rand() % 800) );
	BirdSetPosition.SetY( (float) (rand() % 50) );

	switch ( type )
	{
	case Bird_A:
		NNBird_A* newBird;
		newBird = new NNBird_A();
		newBird->SetPosition( BirdSetPosition );
				

		m_Bird_A.push_back( newBird );
		AddChild( newBird );
		break;
	case Bird_B:
		break;
	case Bird_C:
		break;
	default:
		break;
	}
}

void NNBirdFactory::Move( float dTime )
{
	if( m_Bird_A.empty() )
	{
		std::list< NNBird_A* >::iterator bird_A_Iter = m_Bird_A.begin();
		for( bird_A_Iter = m_Bird_A.begin(); bird_A_Iter != m_Bird_A.end(); ++bird_A_Iter )
		{
			(*bird_A_Iter) -> Move( dTime );
		}
	}
	RemoveCheck();
}

void NNBirdFactory::RemoveCheck() //충돌체크 구현하면서 없애 주어야 함
{
	for (auto& iter=m_Bird_A.begin(); iter!=m_Bird_A.end(); iter++ )
	{
		if (1)
		{
			m_Bird_A.erase( iter );
			RemoveChild(*iter, true);
			break;
		}
	}
}
