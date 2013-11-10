
#include "NNInputSystem.h"
#include "NNApplication.h"
#include <windows.h>

NNInputSystem* NNInputSystem::m_pInstance = nullptr;

NNInputSystem::NNInputSystem()
{
	ZeroMemory( m_PrevKeyState, sizeof(m_PrevKeyState) );
	ZeroMemory( m_NowKeyState, sizeof(m_NowKeyState) );
}
NNInputSystem::~NNInputSystem()
{
}

NNInputSystem* NNInputSystem::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNInputSystem();
	}

	return m_pInstance;
}

void NNInputSystem::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNInputSystem::UpdateKeyState()
{
	for (int i=0; i<256; i++ )
	{
		m_PrevKeyState[i] = m_NowKeyState[i];

		if( ::GetKeyState(i) & 0x8000 )
		{
			m_NowKeyState[i] = true;
		}
		else
		{
			m_NowKeyState[i] = false;
		}
	}
}
KeyState NNInputSystem::GetKeyState( int key )
{
	if ( m_PrevKeyState[key] == false && m_NowKeyState[key] == true )
	{
		return KEY_DOWN;
	}
	else if ( m_PrevKeyState[key] == true && m_NowKeyState[key] == true )
	{
		return KEY_PRESSED;
	}
	else if ( m_PrevKeyState[key] == true && m_NowKeyState[key] == false )
	{
		return KEY_UP;
	}
	
	return KEY_NOTPRESSED;
}

PlayerCharacterDirection NNInputSystem::CheckWhichPressedKey()
{
	if( GetInstance() -> GetKeyState( VK_LEFT ) == KEY_PRESSED )
		return LEFT;
	else if( GetInstance() -> GetKeyState( VK_RIGHT ) == KEY_PRESSED )
		return RIGHT;

	return NONE;

	// 	if( GetInstance() -> GetKeyState( VK_LEFT ) == KEY_PRESSED ) 싱글톤 구조 질문. 함수만들어서 함수값을 받아오려고 했는데 에러남
// 		m_Direction = LEFT;
// 	else if( GetInstance() -> GetKeyState( VK_RIGHT ) == KEY_PRESSED )
// 		m_Direction = RIGHT;
// 
// 	m_Direction = NONE;
}

NNPoint NNInputSystem::GetMousePosition()
{
	POINT pt;
	GetCursorPos( &pt );
	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt );

	return NNPoint((float)pt.x,(float)pt.y);
}
