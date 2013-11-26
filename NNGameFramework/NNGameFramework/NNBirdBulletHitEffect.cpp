#include "NNBirdBulletHitEffect.h"
#include "NNSprite.h"
#include "BHDefine.h"


NNBirdBulletHitEffect::NNBirdBulletHitEffect(NNPoint birdPosition )
{
	m_pSprite[0] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE1 );
	m_pSprite[1] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE2 );
	m_pSprite[2] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE3 );
	m_pSprite[3] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE4 );
	m_pSprite[4] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE5 );
	m_pSprite[5] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE6 );
	m_pSprite[6] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE7 );
	m_pSprite[7] = NNSprite::Create( BIRD_BULLET_HIT_EFFECT_SPRITE8 );
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
	m_Sumtime += dTime;

	if( m_Sumtime >= BIRD_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME )
	{
		m_pCurrentSprite = m_pSprite[m_CurrentFrame];
		SpriteSetPosition( m_BirdPosition );
		++m_CurrentFrame;
		m_Sumtime = 0;
	}
	if( m_CurrentFrame == BIRD_BULLET_HIT_EFFECT_SIZE )
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
	m_pCurrentSprite->SetImageHeight( BIRD_BULLET_HIT_EFFECT_HEIGHT);
	m_pCurrentSprite->SetImageHeight( BIRD_BULLET_HIT_EFFECT_WIDTH );
	m_pCurrentSprite->SetScaleX( BIRD_BULLET_HIT_EFFECT_SCALE_X );
	m_pCurrentSprite->SetScaleY( BIRD_BULLET_HIT_EFFECT_SCALE_Y );
	m_pCurrentSprite->SetPosition( birdPosition );
}