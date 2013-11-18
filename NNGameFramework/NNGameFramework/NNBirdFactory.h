#pragma once
#include "NNObject.h"
#include "NNBird_A.h"
#include "NNBird_B.h"
#include "NNBird_C.h"
#include "BHDefine.h"

class NNBirdFactory : public NNObject
{
public:
	static NNBirdFactory* GetInstance();
	static void ReleaseInstance();
	void MakeBird( BirdType type );
	void Update( float dTime );
	std::list< NNBird* >& GetBirdList() { return m_Bird; }
private:
	NNBirdFactory(void);
	~NNBirdFactory(void);

	static NNBirdFactory* m_pInstance;
	void RemoveCheck();

	std::list< NNBird* > m_Bird;
};