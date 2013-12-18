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

	int			 m_PlayerSpeed; //이속증가, 감소 아이템시 사용
	//좌우가 바뀌는 아이템 사용시 사용
	//PlayerCharacterDirection m_Direction;
	float		 m_SumTime; 
	float		 m_SpriteHeight;
	float		 m_SpriteWidth;

	bool		isLeft;
	bool		m_PauseKey;
	NNAnimation* m_StandingBottomL;
};

