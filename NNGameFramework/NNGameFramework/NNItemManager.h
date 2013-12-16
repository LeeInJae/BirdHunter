#pragma once
#include "NNObject.h"
#include "BHDefine.h"
#include <list>

class NNItem;
class NNPlayerCharacter;
class NNPlayerCharacterBottom;

class NNItemManager	: public NNObject
{
public:
	static NNItemManager* GetInstance();
	static void ReleaseInstance();

	void Update( float dTime );
	void MakeItem( ITEM_TYPE itemType, NNPoint birdPosition );
	bool HitCheck( NNPlayerCharacter* player);
	std::list<NNItem*>&	GetItemList(void) {return m_ItemList;}

private:
	NNItemManager(void);
	~NNItemManager(void);

	std::list< NNItem* > m_ItemList;

	static NNItemManager* m_pInstance;
	void RemoveCheck(void);
};

