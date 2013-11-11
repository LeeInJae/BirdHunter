#pragma once

#include "NNBird.h"
#include "NNPoo_A.h"
#include <list>

class NNBird_A : public NNBird
{
public:
	NNBird_A(void);
	~NNBird_A(void);
	void Move( float dTime );
	NNSprite* GetPooSprite();

private:
	void		InitBirdDirection();
	void		MakePoo();
	std::list< NNPoo_A* > m_Bird_A_Poo;
	//NNPoo_A		m_Bird_A_Poo;
//	void BirdUpdate( float dTime );
};