
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

/* */
/* NNInputSystem
/* 키 입력을 담당하는 싱글톤 클래스
/* */

enum KeyState
{
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP,
	KEY_NOTPRESSED,
	
};

enum PlayerCharacterDirection
{
	LEFT,
	RIGHT,
	LEFT_GOING_ATTACK,
	RIGHT_GOING_ATTACK,
	NONE,
};

enum SpecialKeyInput
{
	ATTACK,
	ITEM1,
	ITEM2,
	PAUSE,
	NO,
};

class NNInputSystem
{
public:
	static NNInputSystem* GetInstance();
	static void ReleaseInstance();
	
	void UpdateKeyState();
	KeyState GetKeyState( int key );
	NNPoint GetMousePosition();
	PlayerCharacterDirection GetDirection() { return m_Direction; }
	PlayerCharacterDirection CheckWhichPressedKey();
	SpecialKeyInput			 CheckSpecialPressedKey();
	bool PressedKeyCheck();
private:
	NNInputSystem();
	~NNInputSystem();
	
	static NNInputSystem* m_pInstance;

	PlayerCharacterDirection m_Direction;
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];
	int attackey;

};


