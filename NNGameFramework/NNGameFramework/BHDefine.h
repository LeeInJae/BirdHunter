#pragma once

#define RESOLUTION_WIDTH	800
#define RESOLUTION_HEIGHT	600

#define INIT_PLAYERSPEED	200
#define PLAYER_WIDTH		100
#define PLAYER_HEIGHT		100
#define PLAYER_POSITION_X	350
#define PLAYER_POSITION_Y	500

#define BIRD_WIDTH			30
#define BIRD_HEIGHT			30
#define INIT_BIRD_A_SPEED		200
#define INIT_BIRD_B_SPEED		70
#define INIT_BIRD_C_SPEED		80
#define INIT_BIRD_D_SPEED		90
#define INIT_BIRD_E_SPEED		100
#define BIRD_SET_MAX_WIDTH		800
#define BIRD_SET_MAX_HEIGHT		50
#define POO_SPEED		30
#define POO_WIDTH		30
#define POO_HEIGHT		30

#define POO_A_SPEED		50
#define POO_A_WIDTH		20
#define POO_A_HEIGHT	20

#define POO_B_SPEED		1
#define POO_B_WIDTH		150
#define POO_B_HEIGHT	150

#define BULLET_A_WIDTH  30
#define BULLET_A_HEIGHT 30
#define BULLET_A_SPEED  100

#define NORMAL_BIRD_LEFT_SPRITE	 L"Image/BIRD_A_LEFT.png"
#define NORMAL_BIRD_RIGHT_SPRITE L"Image/BIRD_A_RIGHT.png"
#define NORMAL_BIRD_WIDTH	30
#define NORMAL_BIRD_HEIGHT	30
#define NORMAL_BIRD_ZINDEX	2
#define NORMAL_BIRD_SPEED	100;

#define NORMAL_BIRD_POO_WIDTH	30
#define NORMAL_BIRD_POO_HEIGHT	30
#define NORMAL_BIRD_POO_ZINDEX	2
#define NORMAL_BIRD_POO_SPEED	50
#define NORMAL_BIRD_POO_SPRITE L"Image/poo.png"

enum BulletType
{
	Bullet_A,
	Bullet_B,
	Bullet_C,
};

enum BirdType
{
	EASY_BIRD,
	NORMAL_BIRD,
	HARD_BIRD,
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
	int				setImageWidth;
	int				setImageHeight;
	GoingDirection	goingDirection;
	int				zindex;
};

struct POO_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	int				setImageWidth;
	int				setImageHeight;
	int				zindex;
};