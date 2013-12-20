#pragma once
#include "NNObject.h"
#include <vector>
#include <string>

class NNSprite;

class NNMapManager :
	public NNObject
{
public:
	static NNMapManager* GetInstance();
	~NNMapManager(void);
	void Update(float dTime);
	void WarningCountInit(void);
	int GetWarningLV(void){return m_CurrentWarningLV;}

protected:
	NNMapManager(void);
	NNSprite* m_pMap;
	NNSprite* m_WarningFilter;

private:
	bool m_WarningFlag;
	static NNMapManager* m_pInstance;
	int m_Pollution;
	int m_CurrentWarningLV;
	int m_PrevWarningLV;
	std::vector<int> m_WarningCount;
};

