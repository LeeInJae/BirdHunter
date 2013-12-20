#pragma once
#include "nnplayercharacter.h"
class NNPlayerCharacterBottom :
	public NNObject
{
public:
	NNPlayerCharacterBottom(void);
	~NNPlayerCharacterBottom(void);

	void	Update( float dTime );
	bool	IsLeft();
	float	GetSpriteHeight()	{ return m_SpriteHeight; }
	float	GetSpriteWidth()	{ return m_SpriteWidth; }
	
private:
	NNAnimation*		m_pCharBottom;

	NNAnimation*	m_StandingBottomR;
	NNAnimation*	m_RunningBottomR;
	NNAnimation*	m_RunningBottomL;

	void	PCAnimationInit(void);

	int			 m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
	float		 m_SumTime; 
	float		 m_SpriteHeight;
	float		 m_SpriteWidth;

	bool		isLeft;
	bool		m_PauseKey;
	NNAnimation* m_StandingBottomL;
};

