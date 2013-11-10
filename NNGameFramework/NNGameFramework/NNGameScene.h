#pragma once
#include "NNScene.h"
#include "NNPlayerCharacter.h"

class NNSprite;
//class NNPlayerCharacter; ���̷��� �ϸ� �ȵ���?
//������� �߰��ϴϱ� ��
//���� ���� ��

class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNCREATE_FUNC( NNGameScene );

protected:
	NNSprite* m_pMap;
	NNPlayerCharacter m_pCharacter;
	
	virtual void Render();
	virtual void Update( float dTime );
	void MovePlayerCharacter( float dTime );
};

