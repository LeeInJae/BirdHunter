
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

class NNInputSystem
{
private:
	static NNInputSystem* m_pInstance;

private:
	NNInputSystem();
	~NNInputSystem();

private:
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];

public:
	static NNInputSystem* GetInstance();
	static void ReleaseInstance();

public:
	void UpdateKeyState();
	KeyState GetKeyState( int key );
	NNPoint GetMousePosition();
};


