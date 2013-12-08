#pragma once
#include "NNObject.h"

class NNSprite;
class NNSpriteAtlas;

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
private:
	//NNSprite*	 m_pChar;
	NNSpriteAtlas* m_pChar;
	int			 m_PlayerSpeed; //�̼�����, ���� �����۽� ���
	//�¿찡 �ٲ�� ������ ���� ���
	//PlayerCharacterDirection m_Direction;
	float		 m_SumTime; 
	float		 m_SpriteHeight;
	float		 m_SpriteWidth;

	bool		m_PauseKey;
};