
#include "GameObjectSystem.h"

GameObjectSystem::GameObjectSystem()
{
}

GameObjectSystem::~GameObjectSystem()
{
}

GameObject* GameObjectSystem::Spawn()
{
	return Spawn(new GameObject);
}

GameObject* GameObjectSystem::Spawn(GameObject* duplicate)
{
	m_GOs.GetList().push_back(duplicate);
	return duplicate;
}

GameObject* GameObjectSystem::Spawn(Transform2D transform)
{
	GameObject* GO = new GameObject();
	GO->SetTransform(transform);

	return Spawn(GO);
}

GameObject* GameObjectSystem::Spawn(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Spawn(transform);
}

GameObject& GameObjectSystem::FindGameObject(int index)
{
	return m_GOs.GetItem(index);
}

void GameObjectSystem::Start()
{
	GO = Spawn(Vector2(400.0f, 300.0f), 45.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Jake.bmp");

	GO = Spawn(Vector2(100.0f, 100.0f), 0.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/NomadAvatar.bmp");

	GO = Spawn(Vector2(600.0f, 400.0f), 90.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Solaire.bmp");
}

void GameObjectSystem::Update(float deltaTime)
{
	Transform2D m_gameObject0;
	m_gameObject0 = FindGameObject(0).GetTransform();
	m_gameObject0.rotation = 100.0f * deltaTime;
	m_gameObject0.scale =
		Vector2
		(
			0.5f * (tan(deltaTime * 1.0f) + 1.0f), 0.5f * (tan(deltaTime * 1.0f) + 1.0f)
		);
	FindGameObject(0).SetTransform(m_gameObject0);

	Transform2D m_gameObject1;
	m_gameObject1 = FindGameObject(1).GetTransform();
	m_gameObject1.position =
		Vector2
		(
			100.0f * (sin(deltaTime * 1.0f) + 1.0f), 100.0f * (cos(deltaTime * 1.0f) + 1.0f)
		);
	FindGameObject(1).SetTransform(m_gameObject1);

	Transform2D m_gameObject2;
	m_gameObject2 = FindGameObject(2).GetTransform();
	m_gameObject2.scale =
		Vector2
		(
			1.5f * (cos(deltaTime * 2.0f) + 1.0f), 1.5f * (cos(deltaTime * 2.0f) + 1.0f)
		);
	FindGameObject(2).SetTransform(m_gameObject2);
}

void GameObjectSystem::Draw()
{
	iteGO = m_GOs.GetList().begin();

	while (iteGO != m_GOs.GetList().end())
	{
		GameObject GO = **iteGO;
		GO.Draw();
		++iteGO;
	}
}

