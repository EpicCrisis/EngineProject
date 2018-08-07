
#include "Application.h"
#include <iostream>

using namespace std;

Application::Application()
{
}

Application::~Application()
{
}

GameObject* Application::Spawn()
{
	return Spawn(new GameObject);
}

GameObject* Application::Spawn(GameObject* duplicate)
{
	m_GOs.GetList().push_back(duplicate);
	return duplicate;
}

GameObject* Application::Spawn(Transform2D transform)
{
	GameObject* GO = new GameObject();
	GO->SetTransform(transform);

	return Spawn(GO);
}

GameObject* Application::Spawn(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Spawn(transform);
}

GameObject& Application::FindGameObject(int index)
{
	return m_GOs.GetItem(index);
}

void Application::Destroy(GameObject* gameObject)
{
	GameObject* storedGOs = gameObject;
	m_GOs.GetList().remove(gameObject);
	delete gameObject;
}

Application & Application::Instance()
{
	// return singleton
	static Application instance;
	return instance;
}

void Application::Start()
{
	//cout << "APPLICATION STARTED" << endl;

	GO = Spawn(Vector2(400.0f, 300.0f), 45.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Jake.bmp");
	
	GO = Spawn(Vector2(100.0f, 100.0f), 0.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/NomadAvatar.bmp");
	
	GO = Spawn(Vector2(600.0f, 400.0f), 90.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Solaire.bmp");

	//=====
	//m_affector1 = ColorAffector(255, 255, 255, 1, 3, 3);
	//m_ps1 = new ParticleSystem(m_sprite222);
	//m_ps1->AddAffector(&m_affector1);
	//m_ps1->AddAffector(&m_affector2);
	//=====
}

void Application::Update(float deltaTime)
{
	cout << "APPLICATION UPDATED" << endl;

	time += deltaTime;

	Transform2D m_transform0;
	m_transform0 = FindGameObject(0).GetTransform();
	m_transform0.rotation = 100.0f * time;
	m_transform0.scale =
		Vector2
		(
			0.5f * (tan(time + 1.0f) + 1.0f), 0.5f * (tan(time + 1.0f) + 1.0f)
		);
	FindGameObject(0).SetTransform(m_transform0);
	
	Transform2D m_transform1;
	m_transform1 = FindGameObject(1).GetTransform();
	m_transform1.position =
		Vector2
		(
			100.0f * (sin(time * 1.0f) + 1.0f), 100.0f * (cos(time * 1.0f) + 1.0f)
		);
	FindGameObject(1).SetTransform(m_transform1);

	Transform2D m_transform2;
	m_transform2 = FindGameObject(2).GetTransform();
	m_transform2.scale =
		Vector2
		(
			1.5f * (cos(time * 2.0f) + 1.0f), 1.5f * (cos(time * 2.0f) + 1.0f)
		);
	FindGameObject(2).SetTransform(m_transform2);

	//=====
	//m_ps1->update();
	//=====
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//=====
	//m_ps1->draw();
	//=====

	// draw function
	iteGO = m_GOs.GetList().begin();

	while (iteGO != m_GOs.GetList().end())
	{
		GameObject GO = **iteGO;
		GO.Draw();
		++iteGO;
	}
}