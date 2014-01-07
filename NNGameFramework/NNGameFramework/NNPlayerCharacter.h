#pragma once
#include "NNObject.h"
#include "BHDefine.h"

class NNSprite;
class NNSpriteAtlas;
class NNAnimation;

//�÷��̾� Ŭ����
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
	void IsGameOver() { m_GameOver = true; }
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

	NNAnimation*	m_AmorStandingTopR;
	NNAnimation*	m_AmorStandingTopL;
	NNAnimation*	m_AmorRunningTopR;
	NNAnimation*	m_AmorRunningTopL;
	NNAnimation*	m_AmorShotR;
	NNAnimation*	m_AmorShotL;

	ATTACK_STATUS	m_AttackStatus;

	void	PCAnimationInit(void);

	int			 m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
	float		 m_SumTime; 
	float		 m_SpriteHeight;
	float		 m_SpriteWidth;

	bool		AnimationEndCheck;
	bool		isLeft;
	bool		m_PauseKey;
	bool		isAttack;
	float		m_DelayTime[ITEM_MAX_NUM];
	bool		m_GameOver;
	GOING_DIRECTION m_Direction;
};