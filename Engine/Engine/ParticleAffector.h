
#pragma once

#include "ParticleObject.h"

class ParticleAffector : public ParticleObject
{
public:
	virtual void affectParticleUpdate(ParticleObject* particle) = 0;
};

class ColorAffector : public ParticleAffector
{
protected:

public:
	virtual void affectParticleUpdate(ParticleObject* particle);
};

class GravityAffector : public ParticleAffector
{
protected:

public:
	virtual void affectParticleUpdate(ParticleObject* particle);
};

class FastAffector : public ParticleAffector
{
protected:

public:
	virtual void affectParticleUpdate(ParticleObject* particle);
};