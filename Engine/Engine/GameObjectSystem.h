
#pragma once

#include "GameObject.h"
#include "GameObjectContainer.h"

class GameObjectSystem
{
private:
	GameObjectContainer<GameObject> m_GOs;
	list<GameObject*>::iterator iteGO;

public:
	GameObjectSystem();
	~GameObjectSystem();

	GameObject* GO;

	// overload spawn function
	GameObject* Spawn();
	GameObject* Spawn(GameObject* duplicate);
	GameObject* Spawn(Transform2D transform);
	GameObject* Spawn(Vector2 position, float rotation, Vector2 scale);

	GameObject& FindGameObject(int index);

	void Start();
	void Update(float deltaTime);
	void Draw();
};

