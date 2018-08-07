
#pragma once

#include "ParticleObject.h"
#include "ParticleObjectContainer.h"
#include "ParticleAffector.h"
#include "ParticleAffectorContainer.h"
#include "Sprite.h"

using namespace std;

class ParticleSystem : public ParticleAffector
{
private:
	float emissionRate;
	float emissionCounter;

	Vector2 m_position;

	ParticleObjectContainer<ParticleObject> m_POs;
	list<ParticleObject*>::iterator itePO;

	ParticleAffectorContainer<ParticleAffector> m_PAs;
	list<ParticleAffector*>::iterator itePA;


public:
	ParticleSystem();
	ParticleSystem(Sprite& sprite);
	~ParticleSystem();

	ParticleObject* PO;

	// overload spawn function
	ParticleObject* Spawn();
	ParticleObject* Spawn(ParticleObject* duplicate);
	ParticleObject* Spawn(Transform2D transform);
	ParticleObject* Spawn(Vector2 position, float rotation, Vector2 scale);

	ParticleObject& FindParticleObject(int index);

	void Destroy(ParticleObject* particle);

	void Start();
	void Update(float deltaTime);
	void Draw();
};

