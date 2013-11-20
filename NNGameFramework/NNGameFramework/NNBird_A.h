#pragma once

#include "NNBird.h"
#include "NNPoo_A.h"
#include <list>

// agebreak : ���⼭ _A�� ���鹺��.. Ŭ���� �̸��� ��Ȯ�ϰ� �Ұ�

// �� A Ŭ���� 
class NNBird_A : public NNBird
{
public:
	NNBird_A(void);
	~NNBird_A(void);

	// agebreak : Move()�� �ƴ� Update() �Լ��� ����Ұ�. 
	// Update()�� �����ϸ� �θ� ������Ʈ���� �ڵ����� ȣ���
	void Move( float dTime );
private:
	void		InitBirdDirection();
	float		m_SumTime;
};