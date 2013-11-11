#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"

//class NNSptie;
//이렇게 하니 m_pchar 에러

//캐릭터 클래스, has a Bullet 추가 요망

class NNPlayerCharacter : public NNObject
{
public:
	NNPlayerCharacter(void);
	~NNPlayerCharacter(void);
	
	NNSprite* GetCharacterSprite() { return m_pChar; }
	void SetPlayerSpeed( int speed ) { m_PlayerSpeed = speed; }
	int GetPlayerSpeed() { return m_PlayerSpeed; }
	void Move( float dTime );
private:
	NNSprite* m_pChar;
	bool m_CheckByPoo;
	int m_PlayerSpeed; //이속증가, 감소 아이템시 사용
	//좌우가 바뀌는 아이템 사용시 사용
	//PlayerCharacterDirection m_Direction;
};