#pragma once
#include "NNObject.h"
#include "BHDefine.h"
#include "NNBird.h"

class NNBirdFactory : public NNObject
{
public:
	static NNBirdFactory*	GetInstance();
	static void				ReleaseInstance();
	void					MakeBird( BirdType type );
	void					Update( float dTime );
	std::list< NNBird* >&	GetBirdList() { return m_Bird; }

private:
	NNBirdFactory(void);
	~NNBirdFactory(void);

	static NNBirdFactory*	 m_pInstance;

	std::list< NNBird* >	 m_Bird;
	
};