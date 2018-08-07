
#pragma once

#include <GLFW/glfw3.h>
#include "GameObject.h"
#include "GameObjectContainer.h"
#include "ParticleSystem.h"

using namespace std;

class Application
{
private:
	Application();

	GameObjectContainer<GameObject> m_GOs;
	list<GameObject*>::iterator iteGO;

	//ParticleSystem* m_ps1;
	//ParticleAffector* m_affector1;

public:
    ~Application();

	GameObject* GO;

	// overload spawn function
	GameObject* Spawn();
	GameObject* Spawn(GameObject* duplicate);
	GameObject* Spawn(Transform2D transform);
	GameObject* Spawn(Vector2 position, float rotation, Vector2 scale);

	GameObject& FindGameObject(int index);

	void Destroy(GameObject* gameObject);

	// create singleton
	static Application& Instance();
	float time;

	void Start();
	void Update(float deltaTime);
	void Draw();
};

