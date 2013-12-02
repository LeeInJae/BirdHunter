#pragma once
#include "NNSprite.h"
#include <time.h>
#include <vector>

#define RESOLUTION_WIDTH	800
#define RESOLUTION_HEIGHT	600

#define UI_WIDTH			800
#define UI_HEIGHT			100
#define UI_SPRITE			L"Image/UI.png"
#define BACKGROUND_SPRITE	L"Image/BACKGROUND.jpg"
#define BACKGROUND_ZINDEX	0
#define START_STRING_NUMBER	11
#define START_STRING_HEIGHT 50.f
#define START_STRING_WIDTH	50.f
#define START_STRING_ZINDEX 1
#define UI_ZINDEX	1

#define STRING_P			L"Image/P.png"
#define STRING_E			L"Image/E.png"
#define STRING_R			L"Image/R.png"
#define STRING_S			L"Image/S.png"
#define STRING_A			L"Image/A.png"
#define STRING_N			L"Image/N.png"
#define STRING_Y			L"Image/Y.png"
#define STRING_K			L"Image/K.png"

#define INIT_PLAYERSPEED	200
#define PLAYER_WIDTH		100
#define PLAYER_HEIGHT		100
#define PLAYER_POSITION_X	350
#define PLAYER_POSITION_Y	500
#define PLAYER_SPRITE_REAL_EDGE 30
#define PLAYER_SPRITE		L"Image/character.png"
#define PLAYER_ZINDEX		2

#define BIRD_WIDTH			30
#define BIRD_HEIGHT			30

#define BIRD_SET_MAX_WIDTH		100
#define BIRD_SET_MAX_HEIGHT		100

/**********************************************************************///
/////////////<새들의 속성들 값을 지정 >/////////////////////////////////////////////////////////////////////
//////////////SMALL BIRD////////////////////////////////////////////////////////////////////////////////////
#define BLACK_SMALL_BIRD_LEFT_SPRITE		L"Image/BLACK_SMALL_BIRD_LEFT.png"
#define BLACK_SMALL_BIRD_RIGHT_SPRITE		L"Image/BLACK_SMALL_BIRD_RIGHT.png"
#define BLACK_SMALL_BIRD_WIDTH				30.f
#define BLACK_SMALL_BIRD_HEIGHT				30.f
#define BLACK_SMALL_BIRD_ZINDEX				2
#define BLACK_SMALL_BIRD_SPEED				100
#define BLACK_SMALL_BIRD_MAKE_POO_TIME		5

#define ORANGE_SMALL_BIRD_LEFT_SPRITE		L"Image/ORANGE_SMALL_BIRD_LEFT.png"
#define ORANGE_SMALL_BIRD_RIGHT_SPRITE		L"Image/ORANGE_SMALL_BIRD_RIGHT.png"
#define ORANGE_SMALL_BIRD_WIDTH				50.f
#define ORANGE_SMALL_BIRD_HEIGHT			50.f
#define ORANGE_SMALL_BIRD_ZINDEX			2
#define ORANGE_SMALL_BIRD_SPEED				100
#define ORANGE_SMALL_BIRD_MAKE_POO_TIME		10

#define WHITE_SMALL_BIRD_LEFT_SPRITE		L"Image/WHITE_SMALL_BIRD_LEFT.png"
#define WHITE_SMALL_BIRD_RIGHT_SPRITE		L"Image/WHITE_SMALL_BIRD_RIGHT.png"
#define WHITE_SMALL_BIRD_WIDTH				30.f
#define WHITE_SMALL_BIRD_HEIGHT				30.f
#define WHITE_SMALL_BIRD_ZINDEX				2
#define WHITE_SMALL_BIRD_SPEED				100
#define WHITE_SMALL_BIRD_MAKE_POO_TIME		15

#define RED_SMALL_BIRD_LEFT_SPRITE			L"Image/RED_SMALL_BIRD_LEFT.png"
#define RED_SMALL_BIRD_RIGHT_SPRITE			L"Image/RED_SMALL_BIRD_RIGHT.png"
#define RED_SMALL_BIRD_WIDTH				30.f
#define RED_SMALL_BIRD_HEIGHT				30.f
#define RED_SMALL_BIRD_ZINDEX				2
#define RED_SMALL_BIRD_SPEED				100
#define RED_SMALL_BIRD_MAKE_POO_TIME		20

//////////////MID BIRD//////////////////////////////////////////////////////////////////////////////////
#define BLACK_MID_BIRD_LEFT_SPRITE			L"Image/BLACK_MID_BIRD_LEFT.png"
#define BLACK_MID_BIRD_RIGHT_SPRITE			L"Image/BLACK_MID_BIRD_RIGHT.png"
#define BLACK_MID_BIRD_WIDTH				30.f
#define BLACK_MID_BIRD_HEIGHT				30.f
#define BLACK_MID_BIRD_ZINDEX				2
#define BLACK_MID_BIRD_SPEED				100
#define BLACK_MID_BIRD_MAKE_POO_TIME		3

#define CARAMEL_MID_BIRD_LEFT_SPRITE		L"Image/CARAMEL_MID_BIRD_LEFT.png"
#define CARAMEL_MID_BIRD_RIGHT_SPRITE		L"Image/CARAMEL_MID_BIRD_RIGHT.png"
#define CARAMEL_MID_BIRD_WIDTH				30.f
#define CARAMEL_MID_BIRD_HEIGHT				30.f
#define CARAMEL_MID_BIRD_ZINDEX				2
#define CARAMEL_MID_BIRD_SPEED				100
#define CARAMEL_MID_BIRD_MAKE_POO_TIME		3

#define GREEN_MID_BIRD_LEFT_SPRITE			L"Image/GREEN_MID_BIRD_LEFT.png"
#define GREEN_MID_BIRD_RIGHT_SPRITE			L"Image/GREEN_MID_BIRD_RIGHT.png"
#define GREEN_MID_BIRD_WIDTH				30.f
#define GREEN_MID_BIRD_HEIGHT				30.f
#define GREEN_MID_BIRD_ZINDEX				2
#define GREEN_MID_BIRD_SPEED				100
#define GREEN_MID_BIRD_MAKE_POO_TIME		3

#define ICE_MID_BIRD_LEFT_SPRITE			L"Image/ICE_MID_BIRD_LEFT.png"
#define ICE_MID_BIRD_RIGHT_SPRITE			L"Image/ICE_MID_BIRD_RIGHT.png"
#define ICE_MID_BIRD_WIDTH					30.f
#define ICE_MID_BIRD_HEIGHT					30.f
#define ICE_MID_BIRD_ZINDEX					2
#define ICE_MID_BIRD_SPEED					100
#define ICE_MID_BIRD_MAKE_POO_TIME			3

#define YELLOW_MID_BIRD_LEFT_SPRITE			L"Image/YELLOW_MID_BIRD_LEFT.png"
#define YELLOW_MID_BIRD_RIGHT_SPRITE		L"Image/YELLOW_MID_BIRD_RIGHT.png"
#define YELLOW_MID_BIRD_WIDTH				30.f
#define YELLOW_MID_BIRD_HEIGHT				30.f
#define YELLOW_MID_BIRD_ZINDEX				2
#define YELLOW_MID_BIRD_SPEED				100
#define YELLOW_MID_BIRD_MAKE_POO_TIME		3
//////////////////////BIG BIRD/////////////////////////////////////////////////////////////////////////////////
#define BROWN_BIG_BIRD_LEFT_SPRITE			L"Image/BROWN_BIG_BIRD_LEFT.png"
#define BROWN_BIG_BIRD_RIGHT_SPRITE			L"Image/BROWN_BIG_BIRD_RIGHT.png"
#define BROWN_BIG_BIRD_WIDTH				30.f
#define BROWN_BIG_BIRD_HEIGHT				30.f
#define BROWN_BIG_BIRD_ZINDEX				2
#define BROWN_BIG_BIRD_SPEED				100
#define BROWN_BIG_BIRD_MAKE_POO_TIME		3

#define WHITE_BIG_BIRD_LEFT_SPRITE			L"Image/WHITE_BIG_BIRD_LEFT.png"
#define WHITE_BIG_BIRD_RIGHT_SPRITE			L"Image/WHITE_BIG_BIRD_RIGHT.png"
#define WHITE_BIG_BIRD_WIDTH				30.f
#define WHITE_BIG_BIRD_HEIGHT				30.f
#define WHITE_BIG_BIRD_ZINDEX				2
#define WHITE_BIG_BIRD_SPEED				100
#define WHITE_BIG_BIRD_MAKE_POO_TIME		3

#define PINK_BIG_BIRD_LEFT_SPRITE			L"Image/PINK_BIG_BIRD_LEFT.png"
#define PINK_BIG_BIRD_RIGHT_SPRITE			L"Image/PINK_BIG_BIRD_RIGHT.png"
#define PINK_BIG_BIRD_WIDTH					30.f
#define PINK_BIG_BIRD_HEIGHT				30.f
#define PINK_BIG_BIRD_ZINDEX				2
#define PINK_BIG_BIRD_SPEED					100
#define PINK_BIG_BIRD_MAKE_POO_TIME			3
//////////////ITEM BIRD //////////////////////////////////////////////

#define ITEM_KING_BIRD_LEFT_SPRITE			L"Image/ITEM_KING_BIRD_LEFT.png"
#define ITEM_KING_BIRD_RIGHT_SPRITE			L"Image/ITEM_KING_BIRD_RIGHT.png"
#define ITEM_KING_BIRD_WIDTH				30.f
#define ITEM_KING_BIRD_HEIGHT				30.f
#define ITEM_KING_BIRD_ZINDEX				2
#define ITEM_KING_BIRD_SPEED				100
#define ITEM_KING_BIRD_MAKE_POO_TIME		3

///////////////OLD BIRD///////////////////////////////////////////////////
#define RED_OLD_BIRD_LEFT_SPRITE			L"Image/RED_OLD_BIRD_LEFT.png"
#define RED_OLD_BIRD_RIGHT_SPRITE			L"Image/RED_OLD_BIRD_RIGHT.png"
#define RED_OLD_BIRD_WIDTH					30.f
#define RED_OLD_BIRD_HEIGHT					30.f
#define RED_OLD_BIRD_ZINDEX					2
#define RED_OLD_BIRD_SPEED					100
#define RED_OLD_BIRD_MAKE_POO_TIME			3

#define GREEN_OLD_BIRD_LEFT_SPRITE			L"Image/GREEN_OLD_BIRD_LEFT.png"
#define GREEN_OLD_BIRD_RIGHT_SPRITE			L"Image/GREEN_OLD_BIRD_RIGHT.png"
#define GREEN_OLD_BIRD_WIDTH				30.f
#define GREEN_OLD_BIRD_HEIGHT				30.f
#define GREEN_OLD_BIRD_ZINDEX				2
#define GREEN_OLD_BIRD_SPEED				100
#define GREEN_OLD_BIRD_MAKE_POO_TIME		3
//////////////////////////////////////////////////////////////////////////
/**********************************************************************///



/**********************************************************************///
//////////////<새들의 똥의 관한 속성 지정>////////////////////////////////
#define BLACK_SMALL_BIRD_POO_SPRITE			L"Image/BLACK_POO.png"
#define BLACK_SMALL_BIRD_POO_WIDTH			30.f
#define BLACK_SMALL_BIRD_POO_HEIGHT			30.f
#define BLACK_SMALL_BIRD_POO_ZINDEX			2
#define BLACK_SMALL_BIRD_POO_ACCEL_SPEED	0.3f
#define BLACK_SMALL_BIRD_POO_SPEED			100

#define ORANGE_SMALL_BIRD_POO_SPRITE		L"Image/ORANGE_POO.png"
#define ORANGE_SMALL_BIRD_POO_WIDTH			50.f
#define ORANGE_SMALL_BIRD_POO_HEIGHT		50.f
#define ORANGE_SMALL_BIRD_POO_ZINDEX		2
#define ORANGE_SMALL_BIRD_POO_ACCEL_SPEED	0.3f
#define ORANGE_SMALL_BIRD_POO_SPEED			100

#define WHITE_SMALL_BIRD_POO_SPRITE			L"Image/WHITE_POO.png"
#define WHITE_SMALL_BIRD_POO_WIDTH			30.f
#define WHITE_SMALL_BIRD_POO_HEIGHT			30.f
#define WHITE_SMALL_BIRD_POO_ZINDEX			2
#define WHITE_SMALL_BIRD_POO_ACCEL_SPEED	0.3f
#define WHITE_SMALL_BIRD_POO_SPEED			100

#define RED_SMALL_BIRD_POO_SPRITE			L"Image/RED_POO.png"
#define RED_SMALL_BIRD_POO_WIDTH			30.f
#define RED_SMALL_BIRD_POO_HEIGHT			30.f
#define RED_SMALL_BIRD_POO_ZINDEX			2
#define RED_SMALL_BIRD_POO_ACCEL_SPEED		0.3f
#define RED_SMALL_BIRD_POO_SPEED			100

//////////////MID BIRD//////////////////////////////////////////////////////////////////////////////////
#define BLACK_MID_BIRD_POO_SPRITE			L"Image/BLACK_POO.png"
#define BLACK_MID_BIRD_POO_WIDTH			30.f
#define BLACK_MID_BIRD_POO_HEIGHT			30.f
#define BLACK_MID_BIRD_POO_ZINDEX			2
#define BLACK_MID_BIRD_POO_ACCEL_SPEED		0.3f
#define BLACK_MID_BIRD_POO_SPEED			100

#define CARAMEL_MID_BIRD_POO_SPRITE			L"Image/CARAMEL_POO.png"
#define CARAMEL_MID_BIRD_POO_WIDTH			30.f
#define CARAMEL_MID_BIRD_POO_HEIGHT			30.f
#define CARAMEL_MID_BIRD_POO_ZINDEX			2
#define CARAMEL_MID_BIRD_POO_ACCEL_SPEED	5.f
#define CARAMEL_MID_BIRD_POO_SPEED			100

#define GREEN_MID_BIRD_POO_SPRITE			L"Image/GREEN_POO.png"
#define GREEN_MID_BIRD_POO_WIDTH			30.f
#define GREEN_MID_BIRD_POO_HEIGHT			30.f
#define GREEN_MID_BIRD_POO_ZINDEX			2
#define GREEN_MID_BIRD_POO_ACCEL_SPEED		0.3f
#define GREEN_MID_BIRD_POO_SPEED			100

#define ICE_MID_BIRD_POO_SPRITE				L"Image/ICE_POO.png"
#define ICE_MID_BIRD_POO_WIDTH				30.f
#define ICE_MID_BIRD_POO_HEIGHT				30.f
#define ICE_MID_BIRD_POO_ZINDEX				2
#define ICE_MID_BIRD_POO_ACCEL_SPEED		0.3f
#define ICE_MID_BIRD_POO_SPEED				100

#define YELLOW_MID_BIRD_POO_SPRITE			L"Image/YELLOW_POO.png"
#define YELLOW_MID_BIRD_POO_WIDTH			30.f
#define YELLOW_MID_BIRD_POO_HEIGHT			30.f
#define YELLOW_MID_BIRD_POO_ZINDEX			2
#define YELLOW_MID_BIRD_POO_ACCEL_SPEED		0.3f
#define YELLOW_MID_BIRD_POO_SPEED			100
//////////////////////BIG BIRD/////////////////////////////////////////////////////////////////////////////////
#define BROWN_BIG_BIRD_POO_SPRITE			L"Image/BROWN_POO.png"
#define BROWN_BIG_BIRD_POO_WIDTH			30.f
#define BROWN_BIG_BIRD_POO_HEIGHT			30.f
#define BROWN_BIG_BIRD_POO_ZINDEX			2
#define BROWN_BIG_BIRD_POO_ACCEL_SPEED		0.3f
#define BROWN_BIG_BIRD_POO_SPEED			100

#define WHITE_BIG_BIRD_POO_SPRITE			L"Image/WHITE_POO.png"
#define WHITE_BIG_BIRD_POO_WIDTH			30.f
#define WHITE_BIG_BIRD_POO_HEIGHT			30.f
#define WHITE_BIG_BIRD_POO_ZINDEX			2
#define WHITE_BIG_BIRD_POO_ACCEL_SPEED		0.3f
#define WHITE_BIG_BIRD_POO_SPEED			100

#define PINK_BIG_BIRD_POO_SPRITE			L"Image/PINK_POO.png"
#define PINK_BIG_BIRD_POO_WIDTH				30.f
#define PINK_BIG_BIRD_POO_HEIGHT			30.f
#define PINK_BIG_BIRD_POO_ZINDEX			2
#define PINK_BIG_BIRD_POO_ACCEL_SPEED		0.3f
#define PINK_BIG_BIRD_POO_SPEED				100
//////////////ITEM BIRD //////////////////////////////////////////////

#define ITEM_KING_BIRD_POO_SPRITE			L"Image/GOLD_POO.png"
#define ITEM_KING_BIRD_POO_WIDTH			30.f
#define ITEM_KING_BIRD_POO_HEIGHT			30.f
#define ITEM_KING_BIRD_POO_ZINDEX			2
#define ITEM_KING_BIRD_POO_ACCEL_SPEED		0.3f
#define ITEM_KING_BIRD_POO_SPEED			100
///////////////OLD BIRD///////////////////////////////////////////////////
#define RED_OLD_BIRD_POO_SPRITE				L"Image/RED_POO.png"
#define RED_OLD_BIRD_POO_WIDTH				30.f
#define RED_OLD_BIRD_POO_HEIGHT				30.f
#define RED_OLD_BIRD_POO_ZINDEX				2
#define RED_OLD_BIRD_POO_ACCEL_SPEED		0.3f
#define RED_OLD_BIRD_POO_SPEED				100

#define GREEN_OLD_BIRD_POO_SPRITE			L"Image/GREEN_POO.png"
#define GREEN_OLD_BIRD_POO_WIDTH			30.f
#define GREEN_OLD_BIRD_POO_HEIGHT			30.f
#define GREEN_OLD_BIRD_POO_ZINDEX			2
#define GREEN_OLD_BIRD_POO_ACCEL_SPEED		0.3f
#define GREEN_OLD_BIRD_POO_SPEED			100
//////////////////////////////////////////////////////////////////////////

#define AMMO_MAX	5

#define NORMAL_POO_WIDTH	30.f
#define NORMAL_POO_HEIGHT	30.f
#define NORMAL_POO_ZINDEX	2
#define NORMAL_POO_ACCEL_SPEED	50
#define NORMAL_POO_SPRITE L"Image/poo.png"

#define NORMAL_BULLET_WIDTH		25.f
#define NORMAL_BULLET_HEIGHT	30.f
#define NORMAL_BULLET_SPEED		200
#define NORMAL_BULLET_ZINDEX	2
#define NORMAL_BULLET_SPRITE	L"Image/BULLET.png"

#define WINDOW_WIDTH_LEFT_EDGE	0.f
#define WINDOW_WIDTH_RIGHT_EDGE 800.f
#define WINDOW_HEIGHT_UP_EDGE	0.f
#define WINDOW_HEIGHT_DOWN_EDGE	600.f

#define GUN_WIDTH 70

#define POLLUTION_WARNING_LV_01	5
#define POLLUTION_WARNING_LV_02 15
#define POLLUTION_WARNING_LV_03	25
#define POLLUTION_WARNING_LV_04	40

#define MAP_DEFAULT		L"Image/map.png"
#define MAP_WARNING_01	L"Image/mapWarning001.png"
#define MAP_WARNING_02	L"Image/mapWarning002.png"
#define MAP_WARNING_03	L"Image/mapWarning003.png"
#define MAP_WARNING_04	L"Image/mapWarning004.png"

#define BIRD_BULLET_HIT_EFFECT_SCALE_X 1.0f
#define BIRD_BULLET_HIT_EFFECT_SCALE_Y 1.0f
#define BIRD_BULLET_HIT_EFFECT_WIDTH	128.f
#define BIRD_BULLET_HIT_EFFECT_HEIGHT	128.f
#define BIRD_BULLET_HIT_EFFECT_LIFETIME 1.0f
#define BIRD_BULLET_HIT_EFFECT_BALANCE_X 80.f
#define BIRD_BULLET_HIT_EFFECT_BALANCE_Y 40.f

#define POO_BULLET_HIT_EFFECT_SCALE_X 0.5f
#define POO_BULLET_HIT_EFFECT_SCALE_Y 0.5f
#define POO_BULLET_HIT_EFFECT_WIDTH		192.f
#define POO_BULLET_HIT_EFFECT_HEIGHT	192.f
#define POO_BULLET_HIT_EFFECT_LIFETIME 0.5f
#define POO_BULLET_HIT_EFFECT_BALANCE_X 30.f
#define POO_BULLET_HIT_EFFECT_BALANCE_Y 30.f

#define BIRD_BULLET_HIT_EFFECT_SIZE 8
#define BIRD_BULLET_HIT_EFFECT_SPRITE1 L"Image/GREEN_BIRD_DIE_001.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/GREEN_BIRD_DIE_002.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/GREEN_BIRD_DIE_003.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/GREEN_BIRD_DIE_004.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/GREEN_BIRD_DIE_005.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/GREEN_BIRD_DIE_006.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/GREEN_BIRD_DIE_007.png"
#define BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/GREEN_BIRD_DIE_008.png"
#define BIRD_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME 0.15f

#define POO_BULLET_HIT_EFFECT_SIZE 7
#define POO_BULLET_HIT_EFFECT_SPRITE1 L"Image/EXPLOSION_01.png"
#define POO_BULLET_HIT_EFFECT_SPRITE2 L"Image/EXPLOSION_02.png"
#define POO_BULLET_HIT_EFFECT_SPRITE3 L"Image/EXPLOSION_03.png"
#define POO_BULLET_HIT_EFFECT_SPRITE4 L"Image/EXPLOSION_04.png"
#define POO_BULLET_HIT_EFFECT_SPRITE5 L"Image/EXPLOSION_05.png"
#define POO_BULLET_HIT_EFFECT_SPRITE6 L"Image/EXPLOSION_06.png"
#define POO_BULLET_HIT_EFFECT_SPRITE7 L"Image/EXPLOSION_07.png"
#define POO_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME 0.15f

#define BIRD_BULLET_HIT_BALANCE_X 50.f

#define BIRD_ALL_NUMBER			15
#define SMALL_BIRD_NUMBER		4
#define MID_BIRD_NUMBER			5
#define BIG_BIRD_NUMBER			3
#define OLD_BIRD_NUMBER			2
#define ITEM_KING_BIRD_NUMBER	1
#define TIME_LEVEL_00		30
#define TIME_LEVEL_01		60
#define TIME_LEVEL_02		100
#define TIME_LEVEL_03		130
#define TIME_LEVEL_04		180
#define TIME_LEVEL_05		230

enum BULLET_TYPE
{
	NORMAL_BULLET,
	FIRE_BULLET,
	STORM_BULLET,
};

enum BIRD_TYPE
{
	BLACK_SMALL_BIRD,
	ORANGE_SMALL_BIRD,
	WHITE_SMALL_BIRD,
	RED_SMALL_BIRD,
	BLACK_MID_BIRD,
	CARAMEL_MID_BIRD,
	GREEN_MID_BIRD,
	ICE_MID_BIRD,
	YELLOW_MID_BIRD,
	BROWN_BIG_BIRD,
	WHITE_BIG_BIRD,
	PINK_BIG_BIRD,
	ITEM_KING_BIRD,
	RED_OLD_BIRD,
	GREEN_OLD_BIRD,
};

#define	BLACK_SMALL_BIRD_BORN_TIME		5
#define	ORANGE_SMALL_BIRD_BORN_TIME		8
#define	WHITE_SMALL_BIRD_BORN_TIME		11
#define	RED_SMALL_BIRD_BORN_TIME		14

#define	BLACK_MID_BIRD_BORN_TIME		17
#define	CARAMEL_MID_BIRD_BORN_TIME		20
#define	GREEN_MID_BIRD_BORN_TIME		23
#define	ICE_MID_BIRD_BORN_TIME			26
#define	YELLOW_MID_BIRD_BORN_TIME		29

#define	BROWN_BIG_BIRD_BORN_TIME		32
#define	WHITE_BIG_BIRD_BORN_TIME		35
#define	PINK_BIG_BIRD_BORN_TIME			38

#define	ITEM_KING_BIRD_BORN_TIME		41
#define	RED_OLD_BIRD_BORN_TIME			44	
#define	GREEN_OLD_BIRD_BORN_TIME		47

#define SMALL_BIRD_COOLTIME		3
#define MID_BIRD_COOLTIME		8
#define BIG_BIRD_COOLTIME		15
#define ITEM_KING_BIRD_COOLTIME	30
#define OLD_BIRD_COOLTIME		20

enum POO_TYPE
{
	BLACK_SMALL_BIRD_POO,
	ORANGE_SMALL_BIRD_POO,
	WHITE_SMALL_BIRD_POO,
	RED_SMALL_BIRD_POO,
	BLACK_MID_BIRD_POO,
	CARAMEL_MID_BIRD_POO,
	GREEN_MID_BIRD_POO,
	ICE_MID_BIRD_POO,
	YELLOW_MID_BIRD_POO,
	BROWN_BIG_BIRD_POO,
	WHITE_BIG_BIRD_POO,
	PINK_BIG_BIRD_POO,
	ITEM_KING_BIRD_POO,
	RED_OLD_BIRD_POO,
	GREEN_OLD_BIRD_POO,
};

enum SystemSE
{
	GAMESTART,
	WARNING,
	GAMEOVER,
	GAMEBGM,

	SYSTEMSOUND_MAX,
};



enum GOING_DIRECTION
{
	LEFT_GO,
	RIGHT_GO,
};

struct OBJECT_PROPERTY
{
	float			speed;
	float			accel_speed;
	std::wstring	sprite_path;
	float			imageWidth;
	float			imageHeight;
	int				zIndex;
};

struct BIRD_PROPERTY : public OBJECT_PROPERTY
{
	GOING_DIRECTION	goingDirection;
	BIRD_TYPE		type;
	float			pooCoolTime;
};

struct POO_PROPERTY : public OBJECT_PROPERTY
{
	POO_TYPE			type;
};

struct BULLET_PROPERTY : public OBJECT_PROPERTY
{
	BULLET_TYPE		type;
};

struct HIT_RECT
{
	float left, right, down, up;

	bool HitCheck( HIT_RECT& target )
	{
		if( target.right < left || target.down < up || target.left	> right	||	target.up > down )
		{
			return false;
		}
		return true;
	}
};