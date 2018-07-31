
#pragma once

#include "GameObject.h"

class ParticleObject : GameObject
{
private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_life;
	float m_defaultLife;

public:
	ParticleObject();
	ParticleObject(Sprite* sprite, Vector2 position, Vector2 acceleration);
	~ParticleObject();

	float GetLife() { return m_life; };
	float GetDefaultLife() { return m_defaultLife; };

	void Spawn();
	void Despawn();
	
	void Start();
	void Update(float deltaTime);
	void Draw();
};

