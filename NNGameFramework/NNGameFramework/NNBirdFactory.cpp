#include "NNBirdFactory.h"
#include "NNBullet.h"
#include "NNBulletManager.h"
#include "NNSoundManager.h"

NNBirdFactory* NNBirdFactory::m_pInstance = nullptr;

NNBirdFactory::NNBirdFactory(void)
{
	srand((unsigned)time(NULL));
}

NNBirdFactory::~NNBirdFactory(void)
{
	RemoveAll();
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
	case BLACK_SMALL_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? BLACK_SMALL_BIRD_LEFT_SPRITE : BLACK_SMALL_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= BLACK_SMALL_BIRD_SPEED;
		bird_Property.imageHeight		= BLACK_SMALL_BIRD_HEIGHT;
		bird_Property.imageWidth		= BLACK_SMALL_BIRD_WIDTH;
		bird_Property.zIndex			= BLACK_SMALL_BIRD_ZINDEX;
		bird_Property.type				= BLACK_SMALL_BIRD;
		bird_Property.pooCoolTime		= BLACK_SMALL_BIRD_MAKE_POO_TIME;
		break;

	case ORANGE_SMALL_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? ORANGE_SMALL_BIRD_LEFT_SPRITE : ORANGE_SMALL_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= ORANGE_SMALL_BIRD_SPEED;
		bird_Property.imageHeight		= ORANGE_SMALL_BIRD_HEIGHT;
		bird_Property.imageWidth		= ORANGE_SMALL_BIRD_WIDTH;
		bird_Property.zIndex			= ORANGE_SMALL_BIRD_ZINDEX;
		bird_Property.type				= ORANGE_SMALL_BIRD;
		bird_Property.pooCoolTime		= ORANGE_SMALL_BIRD_MAKE_POO_TIME;
		break;

	case WHITE_SMALL_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? WHITE_SMALL_BIRD_LEFT_SPRITE : WHITE_SMALL_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= WHITE_SMALL_BIRD_SPEED;
		bird_Property.imageHeight		= WHITE_SMALL_BIRD_HEIGHT;
		bird_Property.imageWidth		= WHITE_SMALL_BIRD_WIDTH;
		bird_Property.zIndex			= WHITE_SMALL_BIRD_ZINDEX;
		bird_Property.type				= WHITE_SMALL_BIRD;
		bird_Property.pooCoolTime		= WHITE_SMALL_BIRD_MAKE_POO_TIME;
		break;
	case RED_SMALL_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? RED_SMALL_BIRD_LEFT_SPRITE : RED_SMALL_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= RED_SMALL_BIRD_SPEED;
		bird_Property.imageHeight		= RED_SMALL_BIRD_HEIGHT;
		bird_Property.imageWidth		= RED_SMALL_BIRD_WIDTH;
		bird_Property.zIndex			= RED_SMALL_BIRD_ZINDEX;
		bird_Property.type				= RED_SMALL_BIRD;
		bird_Property.pooCoolTime		= RED_SMALL_BIRD_MAKE_POO_TIME;
		break;
	case BLACK_MID_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? BLACK_MID_BIRD_LEFT_SPRITE : BLACK_MID_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= BLACK_MID_BIRD_SPEED;
		bird_Property.imageHeight		= BLACK_MID_BIRD_HEIGHT;
		bird_Property.imageWidth		= BLACK_MID_BIRD_WIDTH;
		bird_Property.zIndex			= BLACK_MID_BIRD_ZINDEX;
		bird_Property.type				= BLACK_MID_BIRD;
		bird_Property.pooCoolTime		= BLACK_MID_BIRD_MAKE_POO_TIME;
		break;
	case CARAMEL_MID_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? CARAMEL_MID_BIRD_LEFT_SPRITE : CARAMEL_MID_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= CARAMEL_MID_BIRD_SPEED;
		bird_Property.imageHeight		= CARAMEL_MID_BIRD_HEIGHT;
		bird_Property.imageWidth		= CARAMEL_MID_BIRD_WIDTH;
		bird_Property.zIndex			= CARAMEL_MID_BIRD_ZINDEX;
		bird_Property.type				= CARAMEL_MID_BIRD;
		bird_Property.pooCoolTime		= CARAMEL_MID_BIRD_MAKE_POO_TIME;
		break;
	case GREEN_MID_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? GREEN_MID_BIRD_LEFT_SPRITE : GREEN_MID_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= GREEN_MID_BIRD_SPEED;
		bird_Property.imageHeight		= GREEN_MID_BIRD_HEIGHT;
		bird_Property.imageWidth		= GREEN_MID_BIRD_WIDTH;
		bird_Property.zIndex			= GREEN_MID_BIRD_ZINDEX;
		bird_Property.type				= GREEN_MID_BIRD;
		bird_Property.pooCoolTime		= GREEN_MID_BIRD_MAKE_POO_TIME;
		break;
	case ICE_MID_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? ICE_MID_BIRD_LEFT_SPRITE : ICE_MID_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= ICE_MID_BIRD_SPEED;
		bird_Property.imageHeight		= ICE_MID_BIRD_HEIGHT;
		bird_Property.imageWidth		= ICE_MID_BIRD_WIDTH;
		bird_Property.zIndex			= ICE_MID_BIRD_ZINDEX;
		bird_Property.type				= ICE_MID_BIRD;
		bird_Property.pooCoolTime		= ICE_MID_BIRD_MAKE_POO_TIME;
		break;
	case YELLOW_MID_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? YELLOW_MID_BIRD_LEFT_SPRITE : YELLOW_MID_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= YELLOW_MID_BIRD_SPEED;
		bird_Property.imageHeight		= YELLOW_MID_BIRD_HEIGHT;
		bird_Property.imageWidth		= YELLOW_MID_BIRD_WIDTH;
		bird_Property.zIndex			= YELLOW_MID_BIRD_ZINDEX;
		bird_Property.type				= YELLOW_MID_BIRD;
		bird_Property.pooCoolTime		= YELLOW_MID_BIRD_MAKE_POO_TIME;
		break;
	case BROWN_BIG_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? BROWN_BIG_BIRD_LEFT_SPRITE : BROWN_BIG_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= BROWN_BIG_BIRD_SPEED;
		bird_Property.imageHeight		= BROWN_BIG_BIRD_HEIGHT;
		bird_Property.imageWidth		= BROWN_BIG_BIRD_WIDTH;
		bird_Property.zIndex			= BROWN_BIG_BIRD_ZINDEX;
		bird_Property.type				= BROWN_BIG_BIRD;
		bird_Property.pooCoolTime		= BROWN_BIG_BIRD_MAKE_POO_TIME;
		break;
	case WHITE_BIG_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? WHITE_BIG_BIRD_LEFT_SPRITE : WHITE_BIG_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= WHITE_BIG_BIRD_SPEED;
		bird_Property.imageHeight		= WHITE_BIG_BIRD_HEIGHT;
		bird_Property.imageWidth		= WHITE_BIG_BIRD_WIDTH;
		bird_Property.zIndex			= WHITE_BIG_BIRD_ZINDEX;
		bird_Property.type				= WHITE_BIG_BIRD;
		bird_Property.pooCoolTime		= WHITE_BIG_BIRD_MAKE_POO_TIME;
		break;
	case PINK_BIG_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? PINK_BIG_BIRD_LEFT_SPRITE : PINK_BIG_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= PINK_BIG_BIRD_SPEED;
		bird_Property.imageHeight		= PINK_BIG_BIRD_HEIGHT;
		bird_Property.imageWidth		= PINK_BIG_BIRD_WIDTH;
		bird_Property.zIndex			= PINK_BIG_BIRD_ZINDEX;
		bird_Property.type				= PINK_BIG_BIRD;
		bird_Property.pooCoolTime		= PINK_BIG_BIRD_MAKE_POO_TIME;
		break;
	case ITEM_KING_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? ITEM_KING_BIRD_LEFT_SPRITE : ITEM_KING_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= ITEM_KING_BIRD_SPEED;
		bird_Property.imageHeight		= ITEM_KING_BIRD_HEIGHT;
		bird_Property.imageWidth		= ITEM_KING_BIRD_WIDTH;
		bird_Property.zIndex			= ITEM_KING_BIRD_ZINDEX;
		bird_Property.type				= ITEM_KING_BIRD;
		bird_Property.pooCoolTime		= ITEM_KING_BIRD_MAKE_POO_TIME;
		break;
	case RED_OLD_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? RED_OLD_BIRD_LEFT_SPRITE : RED_OLD_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= RED_OLD_BIRD_SPEED;
		bird_Property.imageHeight		= RED_OLD_BIRD_HEIGHT;
		bird_Property.imageWidth		= RED_OLD_BIRD_WIDTH;
		bird_Property.zIndex			= RED_OLD_BIRD_ZINDEX;
		bird_Property.type				= RED_OLD_BIRD;
		bird_Property.pooCoolTime		= RED_OLD_BIRD_MAKE_POO_TIME;
		break;

	case GREEN_OLD_BIRD:
		bird_Property.sprite_path		= (bird_Property.goingDirection == LEFT_GO ) ? GREEN_OLD_BIRD_LEFT_SPRITE : GREEN_OLD_BIRD_RIGHT_SPRITE;
		bird_Property.speed				= GREEN_OLD_BIRD_SPEED;
		bird_Property.imageHeight		= GREEN_OLD_BIRD_HEIGHT;
		bird_Property.imageWidth		= GREEN_OLD_BIRD_WIDTH;
		bird_Property.zIndex			= GREEN_OLD_BIRD_ZINDEX;
		bird_Property.type				= GREEN_OLD_BIRD;
		bird_Property.pooCoolTime		= GREEN_OLD_BIRD_MAKE_POO_TIME;
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

void NNBirdFactory::RemoveCheck()
{
	std::list< NNBird* >::iterator birdIter;

	for( birdIter = m_Bird.begin(); birdIter != m_Bird.end(); )
	{
		if( (*birdIter)->GetBirdType() == ITEM_KING_BIRD && (*birdIter)->GetSumTime() >= 10.f && ( (*birdIter)->GetPositionX() < 0 || (*birdIter)->GetPositionX() > RESOLUTION_WIDTH ) )
		{
			auto pBird = *birdIter;

			// 리스트에서 삭제. 반환값은 다음 원소이다.
			//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
			birdIter =  m_Bird.erase( birdIter );	

			// 객체 해제
			RemoveChild(pBird,true);
		}
		else
		{
			++birdIter;
		}
	}
}

void NNBirdFactory::RemoveAll()
{
	std::list< NNBird* >::iterator bird_Iter = m_Bird.begin();

	//poo & bound hitcheck
	for( bird_Iter = m_Bird.begin(); bird_Iter != m_Bird.end(); )
	{
		auto pBird = *bird_Iter;
		// 리스트에서 삭제. 반환값은 다음 원소이다.
		//생성하고 넣고, -> 빼고 해제하고  항상 역순이되어야 함
		bird_Iter =  m_Bird.erase( bird_Iter );	
		// 객체 해제
		RemoveChild(pBird, true);
	}
}