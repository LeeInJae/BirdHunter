#include "NNBirdFactory.h"
#include "NNBullet.h"
#include "NNBulletManager.h"

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
	NNBird* p_newBird;
	BIRD_PROPERTY bird_Property;

	BirdSetPosition.SetX( (float) (rand() % BIRD_SET_MAX_WIDTH ) );
	BirdSetPosition.SetY( (float) (rand() % BIRD_SET_MAX_HEIGHT) );

	int checkDirection = rand() % 2;

	( checkDirection == 0 ) ? bird_Property.goingDirection = LEFT_GO : bird_Property.goingDirection = RIGHT_GO;

	// agebreak : 코드 리팩토링!
	switch ( type )
	{
	case NORMAL_BIRD:
		if( bird_Property.goingDirection == LEFT_GO )
			bird_Property.sprite_path	= NORMAL_BIRD_LEFT_SPRITE;
		else
			bird_Property.sprite_path	= NORMAL_BIRD_RIGHT_SPRITE;

		bird_Property.speed				= NORMAL_BIRD_SPEED;
		bird_Property.setImageHeight	= NORMAL_BIRD_HEIGHT;
		bird_Property.setImageWidth		= NORMAL_BIRD_WIDTH;
		bird_Property.zindex			= NORMAL_BIRD_ZINDEX;
		bird_Property.type				= NORMAL_BIRD;

		p_newBird = new NNBird();
		p_newBird->SetBirdProperty( bird_Property );
		p_newBird->SetPosition( BirdSetPosition );
		m_Bird.push_back( p_newBird );
		
		AddChild( p_newBird );

		break;
	case EASY_BIRD:
		if( bird_Property.goingDirection == LEFT_GO )
			bird_Property.sprite_path =  EASY_BIRD_LEFT_SPRITE;
		else
			bird_Property.sprite_path = EASY_BIRD_RIGHT_SPRITE;

		bird_Property.speed = EASY_BIRD_SPEED;
		bird_Property.setImageHeight = EASY_BIRD_HEIGHT;
		bird_Property.setImageWidth = EASY_BIRD_WIDTH;
		bird_Property.zindex = EASY_BIRD_ZINDEX;
		bird_Property.type	=	EASY_BIRD;

		p_newBird = new NNBird();
		p_newBird->SetBirdProperty( bird_Property );
		p_newBird->SetPosition( BirdSetPosition );
		m_Bird.push_back( p_newBird );

		AddChild( p_newBird );
		break;
	default:
		break;
	}
}

void NNBirdFactory::Update( float dTime )
{
	if( !m_Bird.empty() )
	{
		std::list< NNBird* >::iterator bird_Iter = m_Bird.begin();
		for( bird_Iter = m_Bird.begin(); bird_Iter != m_Bird.end(); ++bird_Iter )
		{
			( *bird_Iter ) -> Update( dTime );
		}
	}
}