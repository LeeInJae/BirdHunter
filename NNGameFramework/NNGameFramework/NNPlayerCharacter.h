#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"
#include "NNBullet_A.h"
#include "BHDefine.h"

//class NNSptie;
//�̷��� �ϴ� m_pchar ����
// agebreak : Ŭ������ ���� ������ �ϰ� ������ CPP���� ��������� �߰����� ������, ������ �߻���

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
	int m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
	float m_SumTime; 
	float m_SpriteHeight;
	float m_SpriteWidth;
};