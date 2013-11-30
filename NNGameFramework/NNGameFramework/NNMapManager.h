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
	void SetMapContainer(void);
	void SetWarningCount(void);
	int GetWarningLV(void){return m_CurrentWarningLV;}

protected:
	NNMapManager(void);
	NNSprite* m_pMap;

private:
	static NNMapManager* m_pInstance;
	int pollution;
	int m_CurrentWarningLV;
	int m_PrevWarningLV;
	std::vector<std::wstring> m_MapContainer;
	std::vector<int> m_WarningCount;
};

