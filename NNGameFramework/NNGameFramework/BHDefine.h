#pragma once
#include "NNSprite.h"
#include "NNSound.h"
#include <time.h>
#include <vector>

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

#define MAP_DEFAULT		L"Image/map.png"
#define MAP_WARNING_01	L"Image/mapWarning001.png"
#define MAP_WARNING_02	L"Image/mapWarning002.png"
#define MAP_WARNING_03	L"Image/mapWarning003.png"
#define MAP_WARNING_04	L"Image/mapWarning004.png"

// agebreak : 함수째로 Define 하지 않는다. 만약 하는 경우에는 Create를 Define에 명시한다.
#define SE_GAMESTART	NNSound::Create("Sound/GAME_START.wav")
#define SE_BIRD_DIE_00	NNSound::Create("Sound/BIRD_DIE_00.wav")
#define SE_BIRD_DIE_01	NNSound::Create("Sound/BIRD_DIE_01.wav")
#define SE_BIRD_DIE_02	NNSound::Create("Sound/BIRD_DIE_02.wav")
#define SE_POO_BOOM_00	NNSound::Create("Sound/POO_BOOM_00.wav")
#define SE_POO_BOOM_01	NNSound::Create("Sound/POO_BOOM_01.wav")
#define SE_POO_BOOM_02	NNSound::Create("Sound/POO_BOOM_02.wav")
#define SE_POO_BOOM_03	NNSound::Create("Sound/POO_BOOM_03.wav")
#define SE_POO_BOOM_04	NNSound::Create("Sound/POO_BOOM_04.wav")
#define SE_WARNING		NNSound::Create("Sound/WARNING.wav")

#define Bird_Bullet_HIT_EFFECT_SCALE_X 1.0f
#define Bird_Bullet_HIT_EFFECT_SCALE_Y 1.0f
#define Bird_Bullet_HIT_EFFECT_LIFETIME 0.5
#define Bird_Bullet_HIT_EFFECT_BALACE_X 40
#define Bird_Bullet_HIT_EFFECT_BALACE_Y 40

#define Poo_Bullet_HIT_EFFECT_SCALE_X 0.5f
#define Poo_Bullet_HIT_EFFECT_SCALE_Y 0.5f
#define Poo_Bullet_HIT_EFFECT_LIFETIME 0.5
#define Poo_Bullet_HIT_EFFECT_BALACE_X 40
#define Poo_Bullet_HIT_EFFECT_BALACE_Y 40

#define Bird_Bullet_HiT_Effect_Size 8
#define Bird_Bullet_HiT_Effect_Sprite1 L"Image/GREEN_BIRD_DIE_001.png"
#define Bird_Bullet_HiT_Effect_Sprite2 L"Image/GREEN_BIRD_DIE_002.png"
#define Bird_Bullet_HiT_Effect_Sprite3 L"Image/GREEN_BIRD_DIE_003.png"
#define Bird_Bullet_HiT_Effect_Sprite4 L"Image/GREEN_BIRD_DIE_004.png"
#define Bird_Bullet_HiT_Effect_Sprite5 L"Image/GREEN_BIRD_DIE_005.png"
#define Bird_Bullet_HiT_Effect_Sprite6 L"Image/GREEN_BIRD_DIE_006.png"
#define Bird_Bullet_HiT_Effect_Sprite7 L"Image/GREEN_BIRD_DIE_007.png"
#define Bird_Bullet_HiT_Effect_Sprite8 L"Image/GREEN_BIRD_DIE_008.png"
#define Bird_Bullet_HiT_Effect_Change_Sprite_Time 0.15f

#define Poo_Bullet_HiT_Effect_Size 7
#define Poo_Bullet_HiT_Effect_Sprite1 L"Image/EXPLOSION_01.png"
#define Poo_Bullet_HiT_Effect_Sprite2 L"Image/EXPLOSION_02.png"
#define Poo_Bullet_HiT_Effect_Sprite3 L"Image/EXPLOSION_03.png"
#define Poo_Bullet_HiT_Effect_Sprite4 L"Image/EXPLOSION_04.png"
#define Poo_Bullet_HiT_Effect_Sprite5 L"Image/EXPLOSION_05.png"
#define Poo_Bullet_HiT_Effect_Sprite6 L"Image/EXPLOSION_06.png"
#define Poo_Bullet_HiT_Effect_Sprite7 L"Image/EXPLOSION_07.png"
#define Poo_Bullet_HiT_Effect_Change_Sprite_Time 0.15f



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

// agebreak : 아래 세개의 프로퍼티는 전부 거의 같은 형태이다. 이것을 상속 구조로 만드는게 낫지 않을까?
struct BIRD_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth;	// agebreak : 변수명을 set으로 시작하는것 옳지 않다.
	float			setImageHeight;
	GoingDirection	goingDirection;
	int				zindex;
	BirdType		type;
};

struct POO_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth; // agebreak : 변수명을 set으로 시작하는것 옳지 않다.
	float			setImageHeight;
	int				zindex;
	PooType			type;
};

struct Bullet_PROPERTY
{
	int				speed;
	std::wstring	sprite_path;
	float			setImageWidth; // agebreak : 변수명을 set으로 시작하는것 옳지 않다.
	float			setImageHeight;
	int				zindex;
	BulletType		type;
};

struct Hit_Rect
{
	float left, right, down, up;

	// agebreak : 이렇게 구조체를 받아와 값을 비교만 하는 경우에는 참조를 사용하자. 
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