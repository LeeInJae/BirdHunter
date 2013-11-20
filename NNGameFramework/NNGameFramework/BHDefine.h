#pragma once
#include "NNSprite.h"

#define RESOLUTION_WIDTH	800
#define RESOLUTION_HEIGHT	600

#define INIT_PLAYERSPEED	200
#define PLAYER_WIDTH		100
#define PLAYER_HEIGHT		100
#define PLAYER_POSITION_X	350
#define PLAYER_POSITION_Y	500
#define PLAYER_SPRITE_REAL_EDGE 30
#define PLAYER_SPRITE		L"Image/character.png"
#define PLAYER_ZINDEX		1

#define BIRD_WIDTH			30
#define BIRD_HEIGHT			30

#define BIRD_SET_MAX_WIDTH		800
#define BIRD_SET_MAX_HEIGHT		100

#define NORMAL_BIRD_LEFT_SPRITE	 L"Image/BIRD_A_LEFT.png"
#define NORMAL_BIRD_RIGHT_SPRITE L"Image/BIRD_A_RIGHT.png"
#define NORMAL_BIRD_WIDTH	30.f
#define NORMAL_BIRD_HEIGHT	30.f
#define NORMAL_BIRD_ZINDEX	2
#define NORMAL_BIRD_SPEED	100

#define EASY_BIRD_LEFT_SPRITE	 L"Image/BIRD_B_LEFT.png"
#define EASY_BIRD_RIGHT_SPRITE L"Image/BIRD_B_RIGHT.png"
#define EASY_BIRD_WIDTH	50.f
#define EASY_BIRD_HEIGHT	50.f
#define EASY_BIRD_ZINDEX	2
#define EASY_BIRD_SPEED	100

#define NORMAL_POO_WIDTH	30.f
#define NORMAL_POO_HEIGHT	30.f
#define NORMAL_POO_ZINDEX	2
#define NORMAL_POO_SPEED	50
#define NORMAL_POO_SPRITE L"Image/poo.png"

#define NORMAL_BULLET_WIDTH		25.f
#define NORMAL_BULLET_HEIGHT	25.f
#define NORMAL_BULLET_SPEED		100
#define NORMAL_BULLET_ZINDEX	2
#define NORMAL_BULLET_SPRITE	L"Image/BULLET_A.png"

#define WINDOW_WIDTH_LEFT_EDGE	0.f
#define WINDOW_WIDTH_RIGHT_EDGE 800.f
#define WINDOW_HEIGHT_UP_EDGE	0.f
#define WINDOW_HEIGHT_DOWN_EDGE	600.f

#define GUN_WIDTH 70

#define POLLUTION_WARNING_LV_01	5
#define POLLUTION_WARNING_LV_02 15
#define POLLUTION_WARNING_LV_03	25
#define POLLUTION_WARNING_LV_04	40

#define MAP_DEFAULT_SPRITE L"Image/map.png"

#define HIT_EFFECT_SCALE_X 30
#define HIT_EFFECT_SCALE_Y 30
#define HIT_EFFECT_LIFETIME 2

enum BulletType
{
	NORMAL_BULLET,
	FIRE_BULLET,
	STORM_BULLET,
};

enum BirdType
{
	EASY_BIRD,
	NORMAL_BIRD,
	HARD_BIRD,
};

enum PooType
{
	NORMAL_POO,
	BLOOD_POO,
	BIG_POO,
};

enum GoingDirection
{
	LEFT_GO,
	RIGHT_GO,
};

struct BIRD_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth;
	float			setImageHeight;
	GoingDirection	goingDirection;
	int				zindex;
	BirdType		type;
};

struct POO_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth;
	float			setImageHeight;
	int				zindex;
	PooType			type;
};

struct Bullet_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth;
	float			setImageHeight;
	int				zindex;
	BulletType		type;
};

struct Hit_Rect
{
	float left, right, down, up;

	bool HitCheck( Hit_Rect target )
	{
		if( target.right < left || target.down < up || target.left	> right	||	target.up > down )
		{
			return false;
		}
		return true;
	}
	// agebreak : 여기에 체크 함수를 넣으면?
};