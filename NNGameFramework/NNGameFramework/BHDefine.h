﻿#pragma once
#include "NNSprite.h"
#include "NNAnimation.h"
#include <time.h>
#include <vector>

#define RESOLUTION_WIDTH	800
#define RESOLUTION_HEIGHT	600

#define GAMESTART_READYTIME	3.0f
#define BACKGROUND_SPRITE	L"Image/BACKGROUND6.png"
#define BACKGROUND_ZINDEX	1

#define GAMEOVER_SPRITE		L"Image/GAMEOVER.png"
#define GAMEOVER_ZINDEX		2

#define START_STRING_NUMBER	11
#define START_STRING_HEIGHT 50.f
#define START_STRING_WIDTH	50.f
#define START_STRING_ZINDEX 2

#define TITLE_SPRITE		L"Image/TITLE.png"
#define TITLE_WIDTH			800.f
#define TITLE_HEIGHT		100.f
#define TITLE_ZINDEX		1

#define TITLE_FILTER_SPRITE L"Image/TITLE_BACKGROUND.jpg"
#define TITLE_FILTER_WIDTH			800.f
#define TITLE_FILTER_HEIGHT			700.f
#define TITLE_FILTER_ZINDEX			0

#define STRING_P			L"Image/LETTERS/P.png"
#define STRING_E			L"Image/LETTERS/E.png"
#define STRING_R			L"Image/LETTERS/R.png"
#define STRING_S			L"Image/LETTERS/S.png"
#define STRING_A			L"Image/LETTERS/A.png"
#define STRING_N			L"Image/LETTERS/N.png"
#define STRING_Y			L"Image/LETTERS/Y.png"
#define STRING_K			L"Image/LETTERS/K.png"

#define INIT_PLAYERSPEED	200
#define PLAYER_WIDTH		66
#define PLAYER_HEIGHT		90
#define PLAYER_POSITION_X	350
#define PLAYER_POSITION_Y	472
#define PLAYER_SPRITE_REAL_EDGE 50
#define PLAYER_SPRITE		L"Image/PC/stand00.png"
#define PLAYER_ATLAS		L"Image/PC/PC_ATLAS.png"
#define PLAYER_ZINDEX		2

////아이템 지속시간
#define DUALGUN_RUNTIME		10.f

//////무기아이템 스프라이트
#define NORMALGUN			L"Image/UI/NORMALGUN.png"
#define DUALGUN				L"Image/UI/DUALGUN.png"

#define PLAYER_STAND_TOP_R_00	L"Image/PC/STAND/STAND_R_00.png"
#define PLAYER_STAND_TOP_R_01	L"Image/PC/STAND/STAND_R_01.png"
#define PLAYER_STAND_TOP_R_02	L"Image/PC/STAND/STAND_R_02.png"
#define PLAYER_STAND_TOP_R_03	L"Image/PC/STAND/STAND_R_03.png"
#define PLAYER_STAND_BOTTOM_R	L"Image/PC/STAND/STAND_R_LEG.png"

#define PLAYER_DUALGUN_STAND_TOP_R_00	L"Image/PC/STAND/DUAL_GUN_RIGHT_STAND01.png"
#define PLAYER_DUALGUN_STAND_TOP_R_01	L"Image/PC/STAND/DUAL_GUN_RIGHT_STAND02.png"
#define PLAYER_DUALGUN_STAND_TOP_R_02	L"Image/PC/STAND/DUAL_GUN_RIGHT_STAND03.png"
#define PLAYER_DUALGUN_STAND_TOP_R_03	L"Image/PC/STAND/DUAL_GUN_RIGHT_STAND04.png"

#define PLAYER_STAND_TOP_L_00	L"Image/PC/STAND/STAND_L_00.png"
#define PLAYER_STAND_TOP_L_01	L"Image/PC/STAND/STAND_L_01.png"
#define PLAYER_STAND_TOP_L_02	L"Image/PC/STAND/STAND_L_02.png"
#define PLAYER_STAND_TOP_L_03	L"Image/PC/STAND/STAND_L_03.png"
#define PLAYER_STAND_BOTTOM_L	L"Image/PC/STAND/STAND_L_LEG.png"

#define PLAYER_DUALGUN_STAND_TOP_L_00	L"Image/PC/STAND/DUAL_GUN_LEFT_STAND01.png"
#define PLAYER_DUALGUN_STAND_TOP_L_01	L"Image/PC/STAND/DUAL_GUN_LEFT_STAND02.png"
#define PLAYER_DUALGUN_STAND_TOP_L_02	L"Image/PC/STAND/DUAL_GUN_LEFT_STAND03.png"
#define PLAYER_DUALGUN_STAND_TOP_L_03	L"Image/PC/STAND/DUAL_GUN_LEFT_STAND04.png"

#define PLAYER_RUN_TOP_R_00	L"Image/PC/RUN/RUN_TOP_R_00.png"
#define PLAYER_RUN_TOP_R_01	L"Image/PC/RUN/RUN_TOP_R_01.png"
#define PLAYER_RUN_TOP_R_02	L"Image/PC/RUN/RUN_TOP_R_02.png"
#define PLAYER_RUN_TOP_R_03	L"Image/PC/RUN/RUN_TOP_R_03.png"
#define PLAYER_RUN_TOP_R_04	L"Image/PC/RUN/RUN_TOP_R_04.png"
#define PLAYER_RUN_TOP_R_05	L"Image/PC/RUN/RUN_TOP_R_05.png"

#define PLAYER_RUN_TOP_L_00	L"Image/PC/RUN/RUN_TOP_L_00.png"
#define PLAYER_RUN_TOP_L_01	L"Image/PC/RUN/RUN_TOP_L_01.png"
#define PLAYER_RUN_TOP_L_02	L"Image/PC/RUN/RUN_TOP_L_02.png"
#define PLAYER_RUN_TOP_L_03	L"Image/PC/RUN/RUN_TOP_L_03.png"
#define PLAYER_RUN_TOP_L_04	L"Image/PC/RUN/RUN_TOP_L_04.png"
#define PLAYER_RUN_TOP_L_05	L"Image/PC/RUN/RUN_TOP_L_05.png"

#define PLAYER_RUN_BOTTOM_R_00	L"Image/PC/RUN/RUN_BOTTOM_R_00.png"
#define PLAYER_RUN_BOTTOM_R_01	L"Image/PC/RUN/RUN_BOTTOM_R_01.png"
#define PLAYER_RUN_BOTTOM_R_02	L"Image/PC/RUN/RUN_BOTTOM_R_02.png"
#define PLAYER_RUN_BOTTOM_R_03	L"Image/PC/RUN/RUN_BOTTOM_R_03.png"
#define PLAYER_RUN_BOTTOM_R_04	L"Image/PC/RUN/RUN_BOTTOM_R_04.png"
#define PLAYER_RUN_BOTTOM_R_05	L"Image/PC/RUN/RUN_BOTTOM_R_05.png"

#define PLAYER_RUN_BOTTOM_L_00	L"Image/PC/RUN/RUN_BOTTOM_L_00.png"
#define PLAYER_RUN_BOTTOM_L_01	L"Image/PC/RUN/RUN_BOTTOM_L_01.png"
#define PLAYER_RUN_BOTTOM_L_02	L"Image/PC/RUN/RUN_BOTTOM_L_02.png"
#define PLAYER_RUN_BOTTOM_L_03	L"Image/PC/RUN/RUN_BOTTOM_L_03.png"
#define PLAYER_RUN_BOTTOM_L_04	L"Image/PC/RUN/RUN_BOTTOM_L_04.png"
#define PLAYER_RUN_BOTTOM_L_05	L"Image/PC/RUN/RUN_BOTTOM_L_05.png"

#define NORMAL_SHOT_R_00	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_00.png"
#define NORMAL_SHOT_R_01	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_01.png"
#define NORMAL_SHOT_R_02	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_02.png"
#define NORMAL_SHOT_R_03	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_03.png"
#define NORMAL_SHOT_R_04	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_04.png"
#define NORMAL_SHOT_R_05	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_05.png"
#define NORMAL_SHOT_R_06	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_06.png"
#define NORMAL_SHOT_R_07	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_07.png"
#define NORMAL_SHOT_R_08	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_08.png"
#define NORMAL_SHOT_R_09	L"Image/PC/GUNSHOT/NORMAL_SHOT_R_09.png"

#define DUALGUN_SHOT_R_00	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_01.png"
#define DUALGUN_SHOT_R_01	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_02.png"
#define DUALGUN_SHOT_R_02	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_03.png"
#define DUALGUN_SHOT_R_03	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_04.png"
#define DUALGUN_SHOT_R_04	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_05.png"
#define DUALGUN_SHOT_R_05	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_06.png"
#define DUALGUN_SHOT_R_06	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_07.png"
#define DUALGUN_SHOT_R_07	L"Image/PC/GUNSHOT/DUALGUN_SHOT_R_08.png"

#define DUALGUN_SHOT_L_00	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_01.png"
#define DUALGUN_SHOT_L_01	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_02.png"
#define DUALGUN_SHOT_L_02	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_03.png"
#define DUALGUN_SHOT_L_03	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_04.png"
#define DUALGUN_SHOT_L_04	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_05.png"
#define DUALGUN_SHOT_L_05	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_06.png"
#define DUALGUN_SHOT_L_06	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_07.png"
#define DUALGUN_SHOT_L_07	L"Image/PC/GUNSHOT/DUALGUN_SHOT_L_08.png"

#define NORMAL_SHOT_L_00	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_00.png"
#define NORMAL_SHOT_L_01	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_01.png"
#define NORMAL_SHOT_L_02	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_02.png"
#define NORMAL_SHOT_L_03	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_03.png"
#define NORMAL_SHOT_L_04	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_04.png"
#define NORMAL_SHOT_L_05	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_05.png"
#define NORMAL_SHOT_L_06	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_06.png"
#define NORMAL_SHOT_L_07	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_07.png"
#define NORMAL_SHOT_L_08	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_08.png"
#define NORMAL_SHOT_L_09	L"Image/PC/GUNSHOT/NORMAL_SHOT_L_09.png"

#define BIRD_WIDTH			30
#define BIRD_HEIGHT			30

#define BIRD_SET_MAX_WIDTH		100
#define BIRD_SET_MAX_HEIGHT		100

#define UI_SPRITE			L"Image/UI_ATLAS.png"
#define SKULL_SPRITE		L"Image/SKULL.png"

#define SKILL_FIRST_BAR		L"Image/UI/SKILL_FIRST_BAR.png"
#define SKILL_SECOND_BAR	L"Image/UI/SKILL_SECOND_BAR.png"
/**********************************************************************///
/////////////<새들의 속성들 값을 지정 >/////////////////////////////////////////////////////////////////////
//////////////SMALL BIRD////////////////////////////////////////////////////////////////////////////////////
#define BLACK_SMALL_BIRD_LEFT_SPRITE		L"Image/BLACK_SMALL_BIRD_LEFT.png"
#define BLACK_SMALL_BIRD_RIGHT_SPRITE		L"Image/BLACK_SMALL_BIRD_RIGHT.png"
#define BLACK_SMALL_BIRD_WIDTH				30.f
#define BLACK_SMALL_BIRD_HEIGHT				30.f
#define BLACK_SMALL_BIRD_ZINDEX				2
#define BLACK_SMALL_BIRD_SPEED				55
#define BLACK_SMALL_BIRD_MAKE_POO_TIME		10

#define ORANGE_SMALL_BIRD_LEFT_SPRITE		L"Image/ORANGE_SMALL_BIRD_LEFT.png"
#define ORANGE_SMALL_BIRD_RIGHT_SPRITE		L"Image/ORANGE_SMALL_BIRD_RIGHT.png"
#define ORANGE_SMALL_BIRD_WIDTH				30.f
#define ORANGE_SMALL_BIRD_HEIGHT			30.f
#define ORANGE_SMALL_BIRD_ZINDEX			2
#define ORANGE_SMALL_BIRD_SPEED				60
#define ORANGE_SMALL_BIRD_MAKE_POO_TIME		10

#define WHITE_SMALL_BIRD_LEFT_SPRITE		L"Image/WHITE_SMALL_BIRD_LEFT.png"
#define WHITE_SMALL_BIRD_RIGHT_SPRITE		L"Image/WHITE_SMALL_BIRD_RIGHT.png"
#define WHITE_SMALL_BIRD_WIDTH				30.f
#define WHITE_SMALL_BIRD_HEIGHT				30.f
#define WHITE_SMALL_BIRD_ZINDEX				2
#define WHITE_SMALL_BIRD_SPEED				65
#define WHITE_SMALL_BIRD_MAKE_POO_TIME		10

#define RED_SMALL_BIRD_LEFT_SPRITE			L"Image/RED_SMALL_BIRD_LEFT.png"
#define RED_SMALL_BIRD_RIGHT_SPRITE			L"Image/RED_SMALL_BIRD_RIGHT.png"
#define RED_SMALL_BIRD_WIDTH				50.f
#define RED_SMALL_BIRD_HEIGHT				40.f
#define RED_SMALL_BIRD_ZINDEX				2
#define RED_SMALL_BIRD_SPEED				70
#define RED_SMALL_BIRD_MAKE_POO_TIME		10

//////////////MID BIRD//////////////////////////////////////////////////////////////////////////////////
#define BLACK_MID_BIRD_LEFT_SPRITE			L"Image/BLACK_MID_BIRD_LEFT.png"
#define BLACK_MID_BIRD_RIGHT_SPRITE			L"Image/BLACK_MID_BIRD_RIGHT.png"
#define BLACK_MID_BIRD_WIDTH				60.f
#define BLACK_MID_BIRD_HEIGHT				60.f
#define BLACK_MID_BIRD_ZINDEX				2
#define BLACK_MID_BIRD_SPEED				30
#define BLACK_MID_BIRD_MAKE_POO_TIME		15

#define CARAMEL_MID_BIRD_LEFT_SPRITE		L"Image/CARAMEL_MID_BIRD_LEFT.png"
#define CARAMEL_MID_BIRD_RIGHT_SPRITE		L"Image/CARAMEL_MID_BIRD_RIGHT.png"
#define CARAMEL_MID_BIRD_WIDTH				60.f
#define CARAMEL_MID_BIRD_HEIGHT				60.f
#define CARAMEL_MID_BIRD_ZINDEX				2
#define CARAMEL_MID_BIRD_SPEED				35
#define CARAMEL_MID_BIRD_MAKE_POO_TIME		15

#define GREEN_MID_BIRD_LEFT_SPRITE			L"Image/GREEN_MID_BIRD_LEFT.png"
#define GREEN_MID_BIRD_RIGHT_SPRITE			L"Image/GREEN_MID_BIRD_RIGHT.png"
#define GREEN_MID_BIRD_WIDTH				60.f
#define GREEN_MID_BIRD_HEIGHT				60.f
#define GREEN_MID_BIRD_ZINDEX				2
#define GREEN_MID_BIRD_SPEED				40
#define GREEN_MID_BIRD_MAKE_POO_TIME		15

#define ICE_MID_BIRD_LEFT_SPRITE			L"Image/ICE_MID_BIRD_LEFT.png"
#define ICE_MID_BIRD_RIGHT_SPRITE			L"Image/ICE_MID_BIRD_RIGHT.png"
#define ICE_MID_BIRD_WIDTH					60.f
#define ICE_MID_BIRD_HEIGHT					60.f
#define ICE_MID_BIRD_ZINDEX					2
#define ICE_MID_BIRD_SPEED					45
#define ICE_MID_BIRD_MAKE_POO_TIME			15

#define YELLOW_MID_BIRD_LEFT_SPRITE			L"Image/YELLOW_MID_BIRD_LEFT.png"
#define YELLOW_MID_BIRD_RIGHT_SPRITE		L"Image/YELLOW_MID_BIRD_RIGHT.png"
#define YELLOW_MID_BIRD_WIDTH				60.f
#define YELLOW_MID_BIRD_HEIGHT				60.f
#define YELLOW_MID_BIRD_ZINDEX				2
#define YELLOW_MID_BIRD_SPEED				50
#define YELLOW_MID_BIRD_MAKE_POO_TIME		15
//////////////////////BIG BIRD/////////////////////////////////////////////////////////////////////////////////
#define BROWN_BIG_BIRD_LEFT_SPRITE			L"Image/BROWN_BIG_BIRD_LEFT.png"
#define BROWN_BIG_BIRD_RIGHT_SPRITE			L"Image/BROWN_BIG_BIRD_RIGHT.png"
#define BROWN_BIG_BIRD_WIDTH				90.f
#define BROWN_BIG_BIRD_HEIGHT				90.f
#define BROWN_BIG_BIRD_ZINDEX				2
#define BROWN_BIG_BIRD_SPEED				30
#define BROWN_BIG_BIRD_MAKE_POO_TIME		20

#define WHITE_BIG_BIRD_LEFT_SPRITE			L"Image/WHITE_BIG_BIRD_LEFT.png"
#define WHITE_BIG_BIRD_RIGHT_SPRITE			L"Image/WHITE_BIG_BIRD_RIGHT.png"
#define WHITE_BIG_BIRD_WIDTH				90.f
#define WHITE_BIG_BIRD_HEIGHT				90.f
#define WHITE_BIG_BIRD_ZINDEX				2
#define WHITE_BIG_BIRD_SPEED				30
#define WHITE_BIG_BIRD_MAKE_POO_TIME		20

#define PINK_BIG_BIRD_LEFT_SPRITE			L"Image/PINK_BIG_BIRD_LEFT.png"
#define PINK_BIG_BIRD_RIGHT_SPRITE			L"Image/PINK_BIG_BIRD_RIGHT.png"
#define PINK_BIG_BIRD_WIDTH					90.f
#define PINK_BIG_BIRD_HEIGHT				90.f
#define PINK_BIG_BIRD_ZINDEX				2
#define PINK_BIG_BIRD_SPEED					35
#define PINK_BIG_BIRD_MAKE_POO_TIME			20
//////////////ITEM BIRD //////////////////////////////////////////////

#define ITEM_KING_BIRD_LEFT_SPRITE			L"Image/ITEM_KING_BIRD_LEFT.png"
#define ITEM_KING_BIRD_RIGHT_SPRITE			L"Image/ITEM_KING_BIRD_RIGHT.png"

#define ITEM_KING_BIRD_LEFT_00			L"Image/BIRD/ITEM_KING_BIRD_00.png"
#define ITEM_KING_BIRD_LEFT_01			L"Image/BIRD/ITEM_KING_BIRD_01.png"
#define ITEM_KING_BIRD_LEFT_02			L"Image/BIRD/ITEM_KING_BIRD_02.png"
#define ITEM_KING_BIRD_LEFT_03			L"Image/BIRD/ITEM_KING_BIRD_03.png"
#define ITEM_KING_BIRD_LEFT_04			L"Image/BIRD/ITEM_KING_BIRD_04.png"
#define ITEM_KING_BIRD_LEFT_05			L"Image/BIRD/ITEM_KING_BIRD_05.png"
#define ITEM_KING_BIRD_LEFT_06			L"Image/BIRD/ITEM_KING_BIRD_06.png"
#define ITEM_KING_BIRD_LEFT_07			L"Image/BIRD/ITEM_KING_BIRD_07.png"
#define ITEM_KING_BIRD_LEFT_08			L"Image/BIRD/ITEM_KING_BIRD_08.png"
#define ITEM_KING_BIRD_LEFT_09			L"Image/BIRD/ITEM_KING_BIRD_09.png"
#define ITEM_KING_BIRD_LEFT_10			L"Image/BIRD/ITEM_KING_BIRD_10.png"
#define ITEM_KING_BIRD_LEFT_11			L"Image/BIRD/ITEM_KING_BIRD_11.png"


#define ITEM_KING_BIRD_RIGHT_00			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_00.png"
#define ITEM_KING_BIRD_RIGHT_01			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_01.png"
#define ITEM_KING_BIRD_RIGHT_02			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_02.png"
#define ITEM_KING_BIRD_RIGHT_03			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_03.png"
#define ITEM_KING_BIRD_RIGHT_04			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_04.png"
#define ITEM_KING_BIRD_RIGHT_05			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_05.png"
#define ITEM_KING_BIRD_RIGHT_06			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_06.png"
#define ITEM_KING_BIRD_RIGHT_07			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_07.png"
#define ITEM_KING_BIRD_RIGHT_08			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_08.png"
#define ITEM_KING_BIRD_RIGHT_09			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_09.png"
#define ITEM_KING_BIRD_RIGHT_10			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_10.png"
#define ITEM_KING_BIRD_RIGHT_11			L"Image/BIRD/ITEM_KING_BIRD_RIGHT_11.png"

#define ITEM_KING_BIRD_WIDTH				100.f
#define ITEM_KING_BIRD_HEIGHT				100.f
#define ITEM_KING_BIRD_ZINDEX				2
#define ITEM_KING_BIRD_SPEED				100
#define ITEM_KING_BIRD_MAKE_POO_TIME		3

///////////////OLD BIRD///////////////////////////////////////////////////
#define RED_OLD_BIRD_LEFT_SPRITE			L"Image/RED_OLD_BIRD_LEFT.png"
#define RED_OLD_BIRD_RIGHT_SPRITE			L"Image/RED_OLD_BIRD_RIGHT.png"
#define RED_OLD_BIRD_WIDTH					70.f
#define RED_OLD_BIRD_HEIGHT					70.f
#define RED_OLD_BIRD_ZINDEX					2
#define RED_OLD_BIRD_SPEED					100
#define RED_OLD_BIRD_MAKE_POO_TIME			3

#define GREEN_OLD_BIRD_LEFT_SPRITE			L"Image/GREEN_OLD_BIRD_LEFT.png"
#define GREEN_OLD_BIRD_RIGHT_SPRITE			L"Image/GREEN_OLD_BIRD_RIGHT.png"
#define GREEN_OLD_BIRD_WIDTH				70.f
#define GREEN_OLD_BIRD_HEIGHT				70.f
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


#define PLAYERCHARACTER_APPEAR_SPRITE1 L"image/PC/PC_APPEAR01.png"
#define PLAYERCHARACTER_APPEAR_SPRITE2 L"image/PC/PC_APPEAR02.png"
#define PLAYERCHARACTER_APPEAR_SPRITE3 L"image/PC/PC_APPEAR03.png"
#define PLAYERCHARACTER_APPEAR_SPRITE4 L"image/PC/PC_APPEAR04.png"
#define PLAYERCHARACTER_APPEAR_SPRITE5 L"image/PC/PC_APPEAR05.png"
#define PLAYERCHARACTER_APPEAR_SPRITE6 L"image/PC/PC_APPEAR06.png"
#define PLAYERCHARACTER_APPEAR_SPRITE7 L"image/PC/PC_APPEAR07.png"
#define PLAYERCHARACTER_APPEAR_NUMBER 7
#define PLAYERCHARACTER_APPEAR_FPS	0.07f


#define NORMAL_POO_WIDTH	30.f
#define NORMAL_POO_HEIGHT	30.f
#define NORMAL_POO_ZINDEX	2
#define NORMAL_POO_ACCEL_SPEED	50
#define NORMAL_POO_SPRITE L"Image/poo.png"

#define NORMAL_BULLET_WIDTH		10.f
#define NORMAL_BULLET_HEIGHT	30.f
#define NORMAL_BULLET_SPEED		900
#define NORMAL_BULLET_ZINDEX	2
#define NORMAL_BULLET_SPRITE	L"Image/BULLET3.png"

#define WINDOW_WIDTH_LEFT_EDGE	0.f
#define WINDOW_WIDTH_RIGHT_EDGE 800.f
#define WINDOW_HEIGHT_UP_EDGE	0.f
#define WINDOW_HEIGHT_DOWN_EDGE	600.f

#define GUN_WIDTH 10

#define POLLUTION_WARNING_LV_01	10
#define POLLUTION_WARNING_LV_02 20
#define POLLUTION_WARNING_LV_03	30
#define POLLUTION_WARNING_LV_04	40

#define MAP_DEFAULT		L"Image/BGimage1.png"
#define WARNING_FILTER  L"Image/WARNING_FILTER.png"

#define BIRD_BULLET_CRASH_EFFECT_SCALE_X 1.0f
#define BIRD_BULLET_CRASH_EFFECT_SCALE_Y 1.0f
#define BIRD_BULLET_HIT_EFFECT_WIDTH	128.f
#define BIRD_BULLET_HIT_EFFECT_HEIGHT	128.f

#define POO_BULLET_HIT_EFFECT_SCALE_X	0.5f
#define POO_BULLET_HIT_EFFECT_SCALE_Y	0.5f
#define POO_BULLET_HIT_EFFECT_WIDTH		192.f
#define POO_BULLET_HIT_EFFECT_HEIGHT	192.f

#define BIRD_BULLET_HIT_EFFECT_SIZE 5

#define ALL_BIRD_BULLET_HIT_EFFECT_SPRITE1	L"Image/BIRD_DIE/ALL_BIRD_DIE_001.png"

#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/BLACK_BIRD_DIE_002.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/BLACK_BIRD_DIE_003.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/BLACK_BIRD_DIE_004.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/BLACK_BIRD_DIE_005.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/BLACK_BIRD_DIE_006.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/BLACK_BIRD_DIE_007.png"
#define BLACK_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/BLACK_BIRD_DIE_008.png"

#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/BROWN_BIRD_DIE_002.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/BROWN_BIRD_DIE_003.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/BROWN_BIRD_DIE_004.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/BROWN_BIRD_DIE_005.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/BROWN_BIRD_DIE_006.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/BROWN_BIRD_DIE_007.png"
#define BROWN_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/BROWN_BIRD_DIE_008.png"

#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_002.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_003.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_004.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_005.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_006.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_007.png"
#define CARAMEL_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/CARAMEL_BIRD_DIE_008.png"

#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/GOLD_BIRD_DIE_002.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/GOLD_BIRD_DIE_003.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/GOLD_BIRD_DIE_004.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/GOLD_BIRD_DIE_005.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/GOLD_BIRD_DIE_006.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/GOLD_BIRD_DIE_007.png"
#define GOLD_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/GOLD_BIRD_DIE_008.png"

#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/GREEN_BIRD_DIE_002.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/GREEN_BIRD_DIE_003.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/GREEN_BIRD_DIE_004.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/GREEN_BIRD_DIE_005.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/GREEN_BIRD_DIE_006.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/GREEN_BIRD_DIE_007.png"
#define GREEN_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/GREEN_BIRD_DIE_008.png"

#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/ICE_BIRD_DIE_002.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/ICE_BIRD_DIE_003.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/ICE_BIRD_DIE_004.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/ICE_BIRD_DIE_005.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/ICE_BIRD_DIE_006.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/ICE_BIRD_DIE_007.png"
#define ICE_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/ICE_BIRD_DIE_008.png"

#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_002.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_003.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_004.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_005.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_006.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_007.png"
#define ORANGE_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/ORANGE_BIRD_DIE_008.png"

#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/PINK_BIRD_DIE_002.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/PINK_BIRD_DIE_003.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/PINK_BIRD_DIE_004.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/PINK_BIRD_DIE_005.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/PINK_BIRD_DIE_006.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/PINK_BIRD_DIE_007.png"
#define PINK_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/PINK_BIRD_DIE_008.png"

#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/RED_BIRD_DIE_002.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/RED_BIRD_DIE_003.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/RED_BIRD_DIE_004.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/RED_BIRD_DIE_005.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/RED_BIRD_DIE_006.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/RED_BIRD_DIE_007.png"
#define RED_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/RED_BIRD_DIE_008.png"

#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/WHITE_BIRD_DIE_002.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/WHITE_BIRD_DIE_003.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/WHITE_BIRD_DIE_004.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/WHITE_BIRD_DIE_005.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/WHITE_BIRD_DIE_006.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/WHITE_BIRD_DIE_007.png"
#define WHITE_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/WHITE_BIRD_DIE_008.png"

#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE2 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_002.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE3 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_003.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE4 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_004.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE5 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_005.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE6 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_006.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE7 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_007.png"
#define YELLOW_BIRD_BULLET_HIT_EFFECT_SPRITE8 L"Image/BIRD_DIE/YELLOW_BIRD_DIE_008.png"

#define BIRD_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME 0.05f

#define POO_BULLET_HIT_EFFECT_SIZE 7
#define POO_BULLET_HIT_EFFECT_SPRITE1 L"Image/EXPLOSION_01.png"
#define POO_BULLET_HIT_EFFECT_SPRITE2 L"Image/EXPLOSION_02.png"
#define POO_BULLET_HIT_EFFECT_SPRITE3 L"Image/EXPLOSION_03.png"
#define POO_BULLET_HIT_EFFECT_SPRITE4 L"Image/EXPLOSION_04.png"
#define POO_BULLET_HIT_EFFECT_SPRITE5 L"Image/EXPLOSION_05.png"
#define POO_BULLET_HIT_EFFECT_SPRITE6 L"Image/EXPLOSION_06.png"
#define POO_BULLET_HIT_EFFECT_SPRITE7 L"Image/EXPLOSION_07.png"
#define POO_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME 0.05f

#define BIRD_BULLET_HIT_BALANCE_X 40.f

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

enum BIRD_SPRITE
{
	BLACK_SMALL_BIRD_LEFT,
	ORANGE_SMALL_BIRD_LEFT,
	WHITE_SMALL_BIRD_LEFT,
	RED_SMALL_BIRD_LEFT,
	BLACK_MID_BIRD_LEFT,
	CARAMEL_MID_BIRD_LEFT,
	GREEN_MID_BIRD_LEFT,
	ICE_MID_BIRD_LEFT,
	YELLOW_MID_BIRD_LEFT,
	BROWN_BIG_BIRD_LEFT,
	WHITE_BIG_BIRD_LEFT,
	PINK_BIG_BIRD_LEFT,
	ITEM_KING_BIRD_LEFT,
	RED_OLD_BIRD_LEFT,
	GREEN_OLD_BIRD_LEFT,

	BLACK_SMALL_BIRD_RIGHT,
	ORANGE_SMALL_BIRD_RIGHT,
	WHITE_SMALL_BIRD_RIGHT,
	RED_SMALL_BIRD_RIGHT,
	BLACK_MID_BIRD_RIGHT,
	CARAMEL_MID_BIRD_RIGHT,
	GREEN_MID_BIRD_RIGHT,
	ICE_MID_BIRD_RIGHT,
	YELLOW_MID_BIRD_RIGHT,
	BROWN_BIG_BIRD_RIGHT,
	WHITE_BIG_BIRD_RIGHT,
	PINK_BIG_BIRD_RIGHT,
	ITEM_KING_BIRD_RIGHT,
	RED_OLD_BIRD_RIGHT,
	GREEN_OLD_BIRD_RIGHT,
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

enum ATTACK_STATUS
{
	NORMAL,
	DUAL_GUN,
};
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
	STARTSCENEBGM,

	SYSTEMSOUND_MAX,
};



enum GOING_DIRECTION
{
	LEFT_GO,
	RIGHT_GO,
};


enum ITEM_TYPE
{
	ITEM_DUAL_GUN,
	ITEM_FIRE_SHOOTER,
	ITEM_CLEANER,

	ITEM_MAX_NUM
};

#define	ITEM_WIDTH	30.f
#define	ITEM_HEIGHT	30.f
#define	ITEM_SPEED	100
#define	ITEM_ACCEL_SPEED	0.3f
#define	ITEM_ZINDEX	2

#define ITEM_DUAL_GUN_SPRITE	L"Image/ITEM/ITEM_DUAL_GUN.png"

struct OBJECT_PROPERTY
{
	float			speed;
	float			accel_speed;
	std::wstring	sprite_path;
	float			imageWidth;
	float			imageHeight;
	int				zIndex;
	NNPoint			position;
};

struct BIRD_PROPERTY : public OBJECT_PROPERTY
{
	NNAnimation*	birdAnimation;
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

struct ITEM_PROPERTY : public OBJECT_PROPERTY
{
	ITEM_TYPE	type;
	NNAnimation*	animation;
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

#define PLAYERCHARACTER_RIGHT_DIE_NUMBER 19
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE1 L"Image/PC/PC_DIE01.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE2 L"Image/PC/PC_DIE02.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE3 L"Image/PC/PC_DIE03.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE4 L"Image/PC/PC_DIE04.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE5 L"Image/PC/PC_DIE05.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE6 L"Image/PC/PC_DIE06.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE7 L"Image/PC/PC_DIE07.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE8 L"Image/PC/PC_DIE08.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE9 L"Image/PC/PC_DIE09.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE10 L"Image/PC/PC_DIE10.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE11 L"Image/PC/PC_DIE11.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE12 L"Image/PC/PC_DIE12.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE13 L"Image/PC/PC_DIE13.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE14 L"Image/PC/PC_DIE14.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE15 L"Image/PC/PC_DIE15.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE16 L"Image/PC/PC_DIE16.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE17 L"Image/PC/PC_DIE17.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE18 L"Image/PC/PC_DIE18.png"
#define PLAYERCHARACTER_RIGHT_DIE_SPRITE19 L"Image/PC/PC_DIE19.png"
#define PLAYERCHARACTER_RIGHT_DIE_FPS	    0.03f

#define PLAYERCHARACTER_LEFT_DIE_NUMBER 19
#define PLAYERCHARACTER_LEFT_DIE_SPRITE1 L"Image/PC/PC_LEFT_DIE01.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE2 L"Image/PC/PC_LEFT_DIE02.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE3 L"Image/PC/PC_LEFT_DIE03.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE4 L"Image/PC/PC_LEFT_DIE04.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE5 L"Image/PC/PC_LEFT_DIE05.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE6 L"Image/PC/PC_LEFT_DIE06.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE7 L"Image/PC/PC_LEFT_DIE07.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE8 L"Image/PC/PC_LEFT_DIE08.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE9 L"Image/PC/PC_LEFT_DIE09.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE10 L"Image/PC/PC_LEFT_DIE10.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE11 L"Image/PC/PC_LEFT_DIE11.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE12 L"Image/PC/PC_LEFT_DIE12.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE13 L"Image/PC/PC_LEFT_DIE13.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE14 L"Image/PC/PC_LEFT_DIE14.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE15 L"Image/PC/PC_LEFT_DIE15.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE16 L"Image/PC/PC_LEFT_DIE16.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE17 L"Image/PC/PC_LEFT_DIE17.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE18 L"Image/PC/PC_LEFT_DIE18.png"
#define PLAYERCHARACTER_LEFT_DIE_SPRITE19 L"Image/PC/PC_LEFT_DIE19.png"
#define PLAYERCHARACTER_LEFT_DIE_FPS	    0.03f