#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"

//class NNSptie;
//�̷��� �ϴ� m_pchar ����

//ĳ���� Ŭ����, has a Bullet �߰� ���

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
	int m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
};