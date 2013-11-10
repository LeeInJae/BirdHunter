#pragma once

class NNSprite;

class NNPlayerCharacter
{
public:
	NNPlayerCharacter(void);
	virtual ~NNPlayerCharacter(void);

	bool m_CheckByPoo;
	NNSprite* m_pChar;
};