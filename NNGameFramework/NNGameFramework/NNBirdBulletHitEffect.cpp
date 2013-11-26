#include "NNBirdBulletHitEffect.h"
#include "NNSprite.h"
#include "BHDefine.h"


NNBirdBulletHitEffect::NNBirdBulletHitEffect(NNPoint birdPosition )
{
	m_pSprite[0] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite1 );
	m_pSprite[1] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite2 );
	m_pSprite[2] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite3 );
	m_pSprite[3] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite4 );
	m_pSprite[4] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite5 );
	m_pSprite[5] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite6 );
	m_pSprite[6] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite7 );
	m_pSprite[7] = NNSprite::Create( Bird_Bullet_HiT_Effect_Sprite8 );
	m_Sumtime = 0;
	m_CurrentFrame = 0;
	m_pCurrentSprite = m_pSprite[0];
	m_BirdPosition = birdPosition;
	SpriteSetPosition( m_BirdPosition );
}


NNBirdBulletHitEffect::~NNBirdBulletHitEffect(void)
{

}

void NNBirdBulletHitEffect::Update( float dTime )
{
	//SpriteSetPosition( m_BirdPosition );
	m_Sumtime += dTime;

	if( m_Sumtime >= Bird_Bullet_HiT_Effect_Change_Sprite_Time )
	{
		m_pCurrentSprite = m_pSprite[m_CurrentFrame];
		SpriteSetPosition( m_BirdPosition );
		++m_CurrentFrame;
		m_Sumtime = 0;
	}
	if( m_CurrentFrame == Bird_Bullet_HiT_Effect_Size )
	{
		m_CurrentFrame = 0;
	}
	
}

void NNBirdBulletHitEffect::Render()
{
	if( m_pCurrentSprite )
		m_pCurrentSprite->Render();
}

void NNBirdBulletHitEffect::SpriteSetPosition(NNPoint birdPosition)
{
// 	NNPoint effectPosition;
// 
// 	effectPosition.SetX( birdPosition.GetX() - Bird_Bullet_HIT_EFFECT_BALACE_X );
// 	effectPosition.SetY( birdPosition.GetY() - Bird_Bullet_HIT_EFFECT_BALACE_Y );
	m_pCurrentSprite->SetScaleX( Bird_Bullet_HIT_EFFECT_SCALE_X );
	m_pCurrentSprite->SetScaleY( Bird_Bullet_HIT_EFFECT_SCALE_Y );
	//m_pCurrentSprite->SetPosition( effectPosition );
	m_pCurrentSprite->SetPosition( birdPosition );
}