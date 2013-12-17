#include "NNFire.h"
#include "NNAnimation.h"
#include "BHDefine.h"


NNFire::NNFire(void)
{
	m_Animation = NNAnimation::Create
		( 
		26, 
		FIRE01,FIRE02,FIRE03,FIRE04,FIRE05,FIRE06,FIRE07,FIRE08,FIRE09,FIRE10,
		FIRE11,FIRE12,FIRE13,FIRE14,FIRE15,FIRE16,FIRE17,FIRE18,FIRE19,FIRE20,
		FIRE21,FIRE22,FIRE23,FIRE24,FIRE25,FIRE26 );
	AddChild(m_Animation);
}


NNFire::~NNFire(void)
{
}
