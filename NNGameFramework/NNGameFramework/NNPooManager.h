#pragma once
#include "NNObject.h"
#include "NNPoo_A.h"

enum PooType
{
	POO_A,
	POO_B,
	POO_C,
	POO_D,
};

class NNPooManager : public NNObject
{
public:
	static NNPooManager* GetInstance();
	static void				ReleaseInstance();
	void Move( float dTime );
	void MakePoo( PooType WhichPoo, NNPoint birdPosition );

private:
	NNPooManager(void);
	~NNPooManager(void);

	std::list< NNPoo_A* > m_Poo_A;
	static NNPooManager* m_pInstance;
	void RemoveCheck();
// 	std::list< NNPoo_B * > m_Poo_B;
// 	std::list< NNPoo_C * > m_Poo_C;
// 	std::list< NNPoo_D * > m_Poo_D;
};