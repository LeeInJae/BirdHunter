#pragma once
#include "NNObject.h"
#include "BHDefine.h"
#include "NNBird.h"

//������ ���� �����ϰ� �������ִ� Ŭ����
class NNBirdFactory : public NNObject
{
public:
	static NNBirdFactory*	GetInstance();
	static void				ReleaseInstance();
	void					MakeBird( BIRD_TYPE type );
	std::list< NNBird* >&	GetBirdList() { return m_Bird; }
	void	Update( float dTime );
private:
	NNBirdFactory(void);
	~NNBirdFactory(void);

	static NNBirdFactory*	 m_pInstance;
	void RemoveCheck();
	std::list< NNBird* >	 m_Bird;
};
