
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

/* */
/* NNInputSystem
/* Ű �Է��� ����ϴ� �̱��� Ŭ����
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
	NONE,
};

enum SpecialKeyInput
{
	ATTACk,
	ITEM1,
	ITEM2,
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
private:
	NNInputSystem();
	~NNInputSystem();
	
	
	static NNInputSystem* m_pInstance;

	PlayerCharacterDirection m_Direction;
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];
};


