
#pragma once

#include "ParticleObject.h"
#include "ParticleObjectContainer.h"
#include "ParticleAffector.h"
#include "Sprite.h"

using namespace std;

class ParticleSystem
{
private:
	float emissionRate;
	float emissionCounter;

	Vector2 m_position;

	ParticleObjectContainer<ParticleObject> m_POs;
	list<ParticleObject*>::iterator itePO;

public:
	ParticleSystem();
	ParticleSystem(Sprite& sprite);
	~ParticleSystem();

	void Start();
	void Update(float deltaTime);
	void Draw();
};

