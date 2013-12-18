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
	void MakeItem( ITEM_TYPE itemType, NNPoint birdPosition, float scaleX );
	bool HitCheck( NNPlayerCharacter* player);
	//bool HitCheck( ITEM_TYPE iType, NNPlayerCharacter* player );
	std::list<NNItem*>&	GetItemList(void) {return m_ItemList;}
	ITEM_TYPE GetItemType(void){return m_ItemType;}
	void SetItemType(ITEM_TYPE itype){m_ItemType = itype;}

private:
	NNItemManager(void);
	~NNItemManager(void);

	ITEM_TYPE m_ItemType;

	std::list< NNItem* > m_ItemList;

	static NNItemManager* m_pInstance;
	void RemoveCheck(void);
	
};

