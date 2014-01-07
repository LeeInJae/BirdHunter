#include "NNBird.h"
#include "BHDefine.h"
#include "NNPooManager.h"

NNBird::NNBird(void)
{
	m_SumTime	= 0;
}

NNBird::~NNBird(void)
{

}

void NNBird::Update( float dTime )
{
	NNObject::Update( dTime );
	if( m_BirdProperty.goingDirection == LEFT_GO )
	{
		SetPosition( GetPositionX() - m_BirdProperty.speed * dTime, GetPositionY() );
		
		if( GetPositionX() <= 0 )
		{
			SetScaleX( GetScaleX() * (-1) );
			m_BirdProperty.goingDirection = RIGHT_GO;
		}
	}
	else
	{
		SetPosition( GetPositionX() + m_BirdProperty.speed * dTime, GetPositionY() );

		if(GetPositionX() >= RESOLUTION_WIDTH )
		{	
			SetScaleX( GetScaleX() * (-1) );
			m_BirdProperty.goingDirection = LEFT_GO;
		}
	}

	m_SumTime += dTime;

	if( m_SumTime >= m_BirdProperty.pooCoolTime && m_BirdProperty.type != ITEM_KING_BIRD )
	{
		NNPooManager::GetInstance()->MakePoo( m_BirdProperty.type, GetPosition() );
		m_SumTime = 0;
	}
}

void NNBird::SetBirdProperty( BIRD_PROPERTY &bird_property )
{
	m_BirdProperty	=	bird_property;
	
	//m_pBird			=	NNSprite::Create( bird_property.sprite_path );
	//////////////////
	switch ( bird_property.type )
	{
	case BLACK_SMALL_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BLACK_SMALL_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BLACK_SMALL_BIRD_RIGHT_SPRITE );
		break;

	case ORANGE_SMALL_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  ORANGE_SMALL_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  ORANGE_SMALL_BIRD_RIGHT_SPRITE );
		break;

	case WHITE_SMALL_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  WHITE_SMALL_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  WHITE_SMALL_BIRD_RIGHT_SPRITE );
		break;
	case RED_SMALL_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  RED_SMALL_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  RED_SMALL_BIRD_RIGHT_SPRITE );
		break;
	case BLACK_MID_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BLACK_MID_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BLACK_MID_BIRD_RIGHT_SPRITE );
		break;
	case CARAMEL_MID_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  CARAMEL_MID_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  CARAMEL_MID_BIRD_RIGHT_SPRITE );
		break;
	case GREEN_MID_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  GREEN_MID_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  GREEN_MID_BIRD_RIGHT_SPRITE );
		break;
	case ICE_MID_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  ICE_MID_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  ICE_MID_BIRD_RIGHT_SPRITE );
		break;
	case YELLOW_MID_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  YELLOW_MID_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  YELLOW_MID_BIRD_RIGHT_SPRITE );
		break;
	case BROWN_BIG_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BROWN_BIG_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  BROWN_BIG_BIRD_RIGHT_SPRITE );
		break;
	case WHITE_BIG_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  WHITE_BIG_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  WHITE_BIG_BIRD_RIGHT_SPRITE );
		break;
	case PINK_BIG_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  PINK_BIG_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  PINK_BIG_BIRD_RIGHT_SPRITE );
		break;
	case ITEM_KING_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			= NNAnimation::Create(0.02,bird_property.imageHeight, bird_property.imageWidth, 12,  ITEM_KING_BIRD_LEFT_00,
			ITEM_KING_BIRD_LEFT_01,ITEM_KING_BIRD_LEFT_02,ITEM_KING_BIRD_LEFT_03,ITEM_KING_BIRD_LEFT_04,ITEM_KING_BIRD_LEFT_05,
			ITEM_KING_BIRD_LEFT_06,ITEM_KING_BIRD_LEFT_07,ITEM_KING_BIRD_LEFT_08,ITEM_KING_BIRD_LEFT_09,ITEM_KING_BIRD_LEFT_10,
			ITEM_KING_BIRD_LEFT_11) :
		m_pBird			= NNAnimation::Create(0.02,bird_property.imageHeight, bird_property.imageWidth, 12,  ITEM_KING_BIRD_RIGHT_00,
			ITEM_KING_BIRD_RIGHT_01,ITEM_KING_BIRD_RIGHT_02,ITEM_KING_BIRD_RIGHT_03,ITEM_KING_BIRD_RIGHT_04,ITEM_KING_BIRD_RIGHT_05,
			ITEM_KING_BIRD_RIGHT_06,ITEM_KING_BIRD_RIGHT_07,ITEM_KING_BIRD_RIGHT_08,ITEM_KING_BIRD_RIGHT_09,ITEM_KING_BIRD_RIGHT_10,
			ITEM_KING_BIRD_RIGHT_11);
		break;
	case RED_OLD_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  RED_OLD_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  RED_OLD_BIRD_RIGHT_SPRITE );
		break;

	case GREEN_OLD_BIRD:
		(bird_property.goingDirection == LEFT_GO ) ?
			m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  GREEN_OLD_BIRD_LEFT_SPRITE ) 
			: m_pBird			=	NNAnimation::Create(0.2,bird_property.imageHeight, bird_property.imageWidth, 1,  GREEN_OLD_BIRD_RIGHT_SPRITE );
		break;
	default:
		break;
	}
	//////////////////
			//m_pBird->SetImageHeight( bird_property.imageHeight );
	//m_pBird->SetImageWidth( bird_property.imageWidth );	
	SetZindex( bird_property.zIndex );
	//m_pBird->SetCenter( m_BirdProperty.position );
	AddChild( m_pBird );
}