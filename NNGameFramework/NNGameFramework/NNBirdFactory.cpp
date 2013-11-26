#include "NNBirdFactory.h"
#include "NNBullet.h"
#include "NNBulletManager.h"
#include "NNAudioSystem.h"


NNBirdFactory* NNBirdFactory::m_pInstance = nullptr;

NNBirdFactory::NNBirdFactory(void)
{
	srand((unsigned)time(NULL));
	m_SE_BirdDie.push_back(SE_BIRD_DIE_00);
	m_SE_BirdDie.push_back(SE_BIRD_DIE_01);
	m_SE_BirdDie.push_back(SE_BIRD_DIE_02);
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

void NNBirdFactory::MakeBird( BIRD_TYPE type )
{
	NNPoint BirdSetPosition;
	NNBird* p_newBird;
	BIRD_PROPERTY bird_Property;

 	BirdSetPosition.SetY( (float) (rand() % BIRD_SET_MAX_HEIGHT) );

	bird_Property.goingDirection =  rand() % 2 ? LEFT_GO : RIGHT_GO;
	( bird_Property.goingDirection == LEFT_GO ) ? BirdSetPosition.SetX( WINDOW_WIDTH_LEFT_EDGE - ( rand() % BIRD_SET_MAX_WIDTH ) )
												: BirdSetPosition.SetX( WINDOW_WIDTH_RIGHT_EDGE + ( rand() % BIRD_SET_MAX_WIDTH ) );
	switch ( type )
	{
	case NORMAL_BIRD:
		bird_Property.sprite_path	=	(bird_Property.goingDirection == LEFT_GO ) ? NORMAL_BIRD_LEFT_SPRITE : NORMAL_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= NORMAL_BIRD_SPEED;
		bird_Property.imageHeight	= NORMAL_BIRD_HEIGHT;
		bird_Property.imageWidth		= NORMAL_BIRD_WIDTH;
		bird_Property.zIndex			= NORMAL_BIRD_ZINDEX;
		bird_Property.type				= NORMAL_BIRD;
		break;
	case EASY_BIRD:
		bird_Property.sprite_path	=	(bird_Property.goingDirection == LEFT_GO ) ? EASY_BIRD_LEFT_SPRITE : EASY_BIRD_RIGHT_SPRITE;
		bird_Property.speed = EASY_BIRD_SPEED;
		bird_Property.imageHeight = EASY_BIRD_HEIGHT;
		bird_Property.imageWidth = EASY_BIRD_WIDTH;
		bird_Property.zIndex = EASY_BIRD_ZINDEX;
		bird_Property.type	=	EASY_BIRD;
		break;
	default:
		break;
	}

	p_newBird = new NNBird();
	p_newBird->SetBirdProperty( bird_Property );
	p_newBird->SetPosition( BirdSetPosition );
	m_Bird.push_back( p_newBird );

	AddChild( p_newBird );
}

void NNBirdFactory::RemoveChild( NNObject* object, bool memoryDel )
{
	// agebreak : 두번째 인자가 false가 들어오면 무슨 문제가 발생하는가?
	NNObject::RemoveChild(object, memoryDel);
	NNAudioSystem::GetInstance()->Play(m_SE_BirdDie[rand()%m_SE_BirdDie.size()]);
}