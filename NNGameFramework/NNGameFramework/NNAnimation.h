
#pragma once

#include "NNSpriteNode.h"
#include <vector>

class NNAnimation : public NNObject
{
public:
	NNAnimation();
	virtual ~NNAnimation();

	void Render();
	void Update( float dTime );

	static NNAnimation* Create( int count, ... );
	static NNAnimation* Create( float fps, float width, float height, int count, ... );
	static NNAnimation* Create();

	int GetFrameCount() const { return m_FrameCount; }
	int GetNowFrame() const { return m_Frame; }
	bool IsLoop() const { return m_Loop; }
	bool IsAnimationEnded() {return m_AnimationEnd;}
	void SetFrameTime( float fps );
	void AddSpriteNode( wchar_t* path );
	void SetLoop( bool loop ) { m_Loop = loop; }
	void SetLifeTime( float time ) { m_LifeTime = time; }
private:
	std::vector<NNSpriteNode*> m_SpriteList;

	int m_FrameCount;
	int m_Frame;
	float m_Time;
	float m_LifeTime;
	bool m_Loop;
	bool m_AnimationEnd;
};