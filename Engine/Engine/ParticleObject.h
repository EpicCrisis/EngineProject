
#pragma once

#include "GameObject.h"

class ParticleObject : public GameObject
{
private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_life;
	float m_defaultLife;

public:
	ParticleObject();
	ParticleObject(Sprite& sprite, Vector2 position, Vector2 velocity, Vector2 acceleration);
	~ParticleObject();

	float GetLife() { return m_life; };
	float GetDefaultLife() { return m_defaultLife; };
	
	void Start();
	void Update(float deltaTime);
	void Draw();
};

