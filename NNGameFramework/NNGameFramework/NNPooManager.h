#pragma once
#include "NNObject.h"
#include "NNPlayerCharacter.h"
#include "BHDefine.h"

class NNPoo;

class NNPooManager : public NNObject
{
public:
	static NNPooManager* GetInstance();
	static void				ReleaseInstance();
	
	void	Update( float dTime );
	void	MakePoo( PooType WhichPoo, NNPoint birdPosition );
	int		GetLandedPoo( void ){ return m_LandedPoo; }
	bool	HitCheckByPlayer( NNPlayerCharacter* player );
	std::list< NNPoo* >& GetPooList() { return m_Poo; }

private:
	NNPooManager(void);
	~NNPooManager(void);

	std::list< NNPoo* > m_Poo;

	static NNPooManager* m_pInstance;
	void RemoveCheck();

	int m_LandedPoo;
};