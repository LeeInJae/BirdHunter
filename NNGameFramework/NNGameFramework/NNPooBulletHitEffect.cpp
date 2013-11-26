#include "NNPooBulletHitEffect.h"
#include "NNSprite.h"
#include "BHDefine.h"

NNPooBulletHitEffect::NNPooBulletHitEffect(void)
{
}

NNPooBulletHitEffect::NNPooBulletHitEffect( NNPoint pooPosition )
{
	m_pSprite[0] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite1 );
	m_pSprite[1] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite2 );
	m_pSprite[2] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite3 );
	m_pSprite[3] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite4 );
	m_pSprite[4] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite5 );
	m_pSprite[5] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite6 );
	m_pSprite[6] = NNSprite::Create( Poo_Bullet_HiT_Effect_Sprite7 );
	
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
//	SpriteSetPosition( m_PooPosition );
	m_Sumtime += dTime;

	if( m_Sumtime >= Poo_Bullet_HiT_Effect_Change_Sprite_Time )
	{
		m_pCurrentSprite = m_pSprite[m_CurrentFrame];
		SpriteSetPosition( m_PooPosition );
		++m_CurrentFrame;
		m_Sumtime = 0;
	}
	if( m_CurrentFrame == Poo_Bullet_HiT_Effect_Size )
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
	
	effectPosition.SetX( pooPosition.GetX() - Poo_Bullet_HIT_EFFECT_BALACE_X );
	effectPosition.SetY( pooPosition.GetY() - Poo_Bullet_HIT_EFFECT_BALACE_Y );
	m_pCurrentSprite->SetScaleX( Poo_Bullet_HIT_EFFECT_SCALE_X );
	m_pCurrentSprite->SetScaleY( Poo_Bullet_HIT_EFFECT_SCALE_Y );
	m_pCurrentSprite->SetPosition( effectPosition );
}