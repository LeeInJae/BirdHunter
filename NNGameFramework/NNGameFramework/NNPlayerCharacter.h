#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;
class NNSpriteAtlas;
class NNAnimation;

//플레이어 클래스
class NNPlayerCharacter : public NNObject
{
public:

	NNPlayerCharacter(void);
	~NNPlayerCharacter(void);
	
	void	Update( float dTime );
	float	GetSpriteHeight()	{ return m_SpriteHeight; }
	float	GetSpriteWidth()	{ return m_SpriteWidth; }
	bool	GetPauseKey()		{ return m_PauseKey ; }
	ATTACK_STATUS GetAttackStatus() { 	return m_AttackStatus; }
	GOING_DIRECTION GetPlayerDirection();
	void SetAttackStatus( ATTACK_STATUS status );
private:
	NNAnimation*	m_pCharTop;

	NNAnimation*	m_StandingTopR;
	NNAnimation*	m_StandingTopL;
	NNAnimation*	m_RunningTopR;
	NNAnimation*	m_RunningTopL;
	NNAnimation*	m_NormalShotR;
	NNAnimation*	m_NormalShotL;

	NNAnimation*	m_DualGunStandingTopR;
	NNAnimation*	m_DualGunStandingTopL;
	NNAnimation*	m_DualGunRunningTopR;
	NNAnimation*	m_DualGunRunningTopL;
	NNAnimation*	m_DualGunShotR;
	NNAnimation*	m_DualGunShotL;

	ATTACK_STATUS	m_AttackStatus;

	void	PCAnimationInit(void);

	int			 m_PlayerSpeed; //이속증가, 감소 아이템시 사용
	//좌우가 바뀌는 아이템 사용시 사용
	//PlayerCharacterDirection m_Direction;
	float		 m_SumTime; 
	float		 m_SpriteHeight;
	float		 m_SpriteWidth;

	bool		AnimationEndCheck;
	bool		isLeft;
	bool		m_PauseKey;
	bool		isAttack;
	GOING_DIRECTION m_Direction;
};