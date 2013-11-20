#pragma once

#include "NNBird.h"
#include "NNPoo_A.h"
#include <list>

// agebreak : 여기서 _A는 당췌뭔가.. 클래스 이름은 명확하게 할것

// 새 A 클래스 
class NNBird_A : public NNBird
{
public:
	NNBird_A(void);
	~NNBird_A(void);

	// agebreak : Move()가 아닌 Update() 함수를 사용할것. 
	// Update()로 구현하면 부모 오브젝트에서 자동으로 호출됨
	void Move( float dTime );
private:
	void		InitBirdDirection();
	float		m_SumTime;
};