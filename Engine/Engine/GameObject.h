#pragma once

#include "Sprite.h"
#include "Transform2D.h"

class GameObject
{
private:

public:
	GameObject();
	~GameObject();

	Sprite sprite;

	void Start();
	void Update(float deltaTime);
	void Draw();
};

