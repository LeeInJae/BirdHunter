#pragma once
#include "NNObject.h"
#include "NNPlayerCharacter.h"
#include "BHDefine.h"

class NNPoo;

// ¶ËÀ» °ü¸®ÇÏ´Â ¶Ë ¸Å´ÏÁ®
class NNPooManager : public NNObject
{
public:
	static NNPooManager* GetInstance();
	static void				ReleaseInstance();
	
	void	Update( float dTime );
	void	MakePoo( BIRD_TYPE WhichPoo, NNPoint birdPosition );
	int		GetLandedPoo( void ){ return m_LandedPoo; }
	void	SetLandedPoo( int newPoo ){m_LandedPoo = newPoo;}
	bool	HitCheckByPlayer( NNPlayerCharacter* player );
	bool	HitCheckByShield( NNAnimation* shield );
	std::list< NNPoo* >& GetPooList() { return m_Poo; }
	void RemoveAll();
private:
	NNPooManager(void);
	~NNPooManager(void);

	std::list< NNPoo* > m_Poo;

	
	static NNPooManager* m_pInstance;
	void RemoveCheck();
	
	int m_LandedPoo;
};