#pragma once
#include "NNObject.h"
#include "BHDefine.h"
#include "NNBird.h"

// agebreak : 클래스 위에는 설명을 단다
class NNBirdFactory : public NNObject
{
public:
	static NNBirdFactory*	GetInstance();
	static void				ReleaseInstance();
	void					MakeBird( BirdType type );
	void					Update( float dTime );
	std::list< NNBird* >&	GetBirdList() { return m_Bird; }
	void					RemoveChild( NNObject* object, bool memoryDel );

private:
	NNBirdFactory(void);
	~NNBirdFactory(void);

	static NNBirdFactory*	 m_pInstance;

	std::list< NNBird* >	 m_Bird;

	std::vector<NNSound*> m_SE_BirdDie; 
};
