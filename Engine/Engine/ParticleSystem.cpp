
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
			PO.Despawn();
		}

		// update particle information
		PO.Update(deltaTime);

		++itePO;
	}
}


