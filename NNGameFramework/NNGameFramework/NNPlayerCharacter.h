#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"

//class NNSptie;
//�̷��� �ϴ� m_pchar ����

class NNPlayerCharacter : public NNObject
{
public:
	NNPlayerCharacter(void);
	~NNPlayerCharacter(void);

	bool m_CheckByPoo;
	NNSprite* m_pChar;
	void SetPlayerSpeed( int speed ) { m_PlayerSpeed = speed; }
	int GetPlayerSpeed() { return m_PlayerSpeed; }


private:
	int m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
};

