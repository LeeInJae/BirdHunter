#pragma once
#include "NNBird.h"

// agebreak : 이름을 _A, _B 식으로 짓지 말것. Normal, Hard 등으로 명확한 네이밍을 할것
class NNBIRD_B : public NNBird
{
public:
	NNBIRD_B(void);
	~NNBIRD_B(void);
	void Move( float dTime );
private:
	void InitBirdDirection();
};

