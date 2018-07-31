
#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(Sprite & sprite)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetTransform(Transform2D transform)
{
	m_transform = transform;
}

void GameObject::SetSprite(Sprite& sprite)
{
	m_sprite = sprite;
}

void GameObject::Start()
{
	
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{
	GetSprite().Draw(GetTransform());
}
