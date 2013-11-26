#include "NNPooBulletHitEffect.h"
#include "NNSprite.h"
#include "BHDefine.h"

NNPooBulletHitEffect::NNPooBulletHitEffect(void)
{
}

NNPooBulletHitEffect::NNPooBulletHitEffect( NNPoint pooPosition )
{
	m_pSprite[0] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE1 );
	m_pSprite[1] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE2 );
	m_pSprite[2] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE3 );
	m_pSprite[3] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE4 );
	m_pSprite[4] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE5 );
	m_pSprite[5] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE6 );
	m_pSprite[6] = NNSprite::Create( POO_BULLET_HIT_EFFECT_SPRITE7 );
	
	m_Sumtime = 0;
	m_CurrentFrame = 0;
	m_pCurrentSprite = m_pSprite[0];
	m_PooPosition = pooPosition;
	SpriteSetPosition( m_PooPosition );
}


NNPooBulletHitEffect::~NNPooBulletHitEffect(void)
{
}

void NNPooBulletHitEffect::Update( float dTime )
{
	m_Sumtime += dTime;

	if( m_Sumtime >= POO_BULLET_HIT_EFFECT_CHANGE_SPRITE_TIME )
	{
		m_pCurrentSprite = m_pSprite[m_CurrentFrame];
		SpriteSetPosition( m_PooPosition );
		++m_CurrentFrame;
		m_Sumtime = 0;
	}
	if( m_CurrentFrame == POO_BULLET_HIT_EFFECT_SIZE )
	{
		m_CurrentFrame = 0;
	}
}

void NNPooBulletHitEffect::Render()
{
	if(m_pCurrentSprite)
		m_pCurrentSprite->Render();
}

void NNPooBulletHitEffect::SpriteSetPosition(NNPoint pooPosition)
{
	NNPoint effectPosition;
	
	effectPosition.SetX( pooPosition.GetX() - POO_BULLET_HIT_EFFECT_BALACE_X );
	effectPosition.SetY( pooPosition.GetY() - POO_BULLET_HIT_EFFECT_BALACE_Y );
	m_pCurrentSprite->SetScaleX( POO_BULLET_HIT_EFFECT_SCALE_X );
	m_pCurrentSprite->SetScaleY( POO_BULLET_HIT_EFFECT_SCALE_Y );
	m_pCurrentSprite->SetPosition( effectPosition );
}