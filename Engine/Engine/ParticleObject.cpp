
#include "ParticleObject.h"

ParticleObject::ParticleObject() : GameObject()
{
	m_velocity = Vector2(0.0f, 0.0f);
	m_acceleration = Vector2(0.0f, 0.0f);
}

ParticleObject::ParticleObject(Sprite& sprite, Vector2 position, Vector2 velocity, Vector2 acceleration) : GameObject(sprite)
{
	Transform2D transform = GetTransform();
	transform.position = position;
	SetTransform(transform);

	m_velocity = velocity;
	m_acceleration = acceleration;
}

ParticleObject::~ParticleObject()
{
}

void ParticleObject::Start()
{
	
}

void ParticleObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	// acceleration -> velocity -> position
	m_velocity += m_acceleration;
	m_transform.position += m_velocity;

	m_life -= deltaTime;
}

void ParticleObject::Draw()
{
}
