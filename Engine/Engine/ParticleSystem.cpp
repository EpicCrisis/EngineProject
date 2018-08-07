
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
}

ParticleSystem::ParticleSystem(Sprite & sprite)
{
	emissionRate = 1.0f;
	emissionCounter = 0.0f;
}

ParticleSystem::~ParticleSystem()
{
}

ParticleObject * ParticleSystem::Spawn()
{
	return Spawn(new ParticleObject);
}

ParticleObject * ParticleSystem::Spawn(ParticleObject * duplicate)
{
	m_POs.GetList().push_back(duplicate);
	return duplicate;
}

ParticleObject * ParticleSystem::Spawn(Transform2D transform)
{
	ParticleObject* PO = new ParticleObject();
	PO->SetTransform(transform);

	return Spawn(PO);
}

ParticleObject * ParticleSystem::Spawn(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Spawn(transform);
}

ParticleObject & ParticleSystem::FindParticleObject(int index)
{
	return m_POs.GetItem(index);
}

void ParticleSystem::Destroy(ParticleObject * particle)
{
	ParticleObject* storedPOs = particle;
	m_POs.GetList().remove(particle);
	delete particle;
}

void ParticleSystem::Start()
{
	
}

void ParticleSystem::Draw()
{
	while (itePO != m_POs.GetList().end())
	{
		ParticleObject PO = **itePO;
		PO.Draw();
		++itePO;
	}
}

void ParticleSystem::Update(float deltaTime)
{
	emissionCounter += emissionRate;
	while (emissionCounter >= 1.0f)
	{
		emissionCounter = 0.0f;

		// emit particle


	}

	// update particle movement
	itePO = m_POs.GetList().begin();

	while (itePO != m_POs.GetList().end())
	{
		ParticleObject PO = **itePO;

		// remove particle if life <= 0
		if (PO.GetLife() <= 0)
		{
			
		}

		// update particle information
		PO.Update(deltaTime);

		++itePO;
	}
}


