
#pragma once

#include "Sprite.h"
#include "Transform2D.h"

class GameObject
{
protected:
	Transform2D m_transform;
	Sprite m_sprite;

public:
	GameObject();
	GameObject(Sprite& sprite);
	~GameObject();

	Transform2D GetTransform() { return m_transform; };
	void SetTransform(Transform2D transform);

	Sprite& GetSprite() { return m_sprite; };
	void SetSprite(Sprite& sprite);

	void Start();
	void Update(float deltaTime);
	void Draw();
};

