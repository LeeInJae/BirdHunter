#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"
#include "NNBullet_A.h"
#include "BHDefine.h"

//class NNSptie;
//이렇게 하니 m_pchar 에러
// agebreak : 클래스의 전방 선언을 하고 나서는 CPP에서 헤더파일을 추가하지 않으면, 에러가 발생함

class NNPlayerCharacter : public NNObject
{
public:

	NNPlayerCharacter(void);
	~NNPlayerCharacter(void);
	
	void Move( float dTime );
	void Update( float dTime );
	float GetSpriteHeight() { return m_SpriteHeight; }
	float GetSpriteWidth() { return m_SpriteWidth; }

	//NNPlayerCharacter* GetMine(){ return this; }

private:
	NNSprite* m_pChar;
	bool m_CheckByPoo;
	int m_PlayerSpeed; //이속증가, 감소 아이템시 사용
	//좌우가 바뀌는 아이템 사용시 사용
	//PlayerCharacterDirection m_Direction;
	float m_SumTime; 
	float m_SpriteHeight;
	float m_SpriteWidth;
};