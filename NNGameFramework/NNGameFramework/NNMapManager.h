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
	static void ReleaseInstance();
	~NNMapManager(void);
	void Update(float dTime);
	void WarningCountInit(void);
	int GetWarningLV(void){return m_CurrentWarningLV;}
	int GetPollution(void){return m_Pollution;}
	void SetPollution(int newPollution){m_Pollution = newPollution;}

protected:
	NNMapManager(void);
	NNSprite* m_pMap;
	NNSprite* m_WarningFilter;

private:
	bool m_IsWarning;
	static NNMapManager* m_pInstance;
	int m_Pollution;
	int m_CurrentWarningLV;
	int m_PrevWarningLV;
	std::vector<int> m_WarningCount;
};

