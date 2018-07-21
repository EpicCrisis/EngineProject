
#include "Application.h"
#include <iostream>

using namespace std;

Application::Application()
{
}

Application::~Application()
{
}

Application & Application::Instance()
{
	// return singleton
	static Application instance;
	return instance;
}

void Application::Start()
{
	GO.SetImage("../media/100x100Jake.bmp");
	GOs.push_back(GO);
	GO.SetImage("../media/225x225Solaire.bmp");
	GOs.push_back(GO);
	GO.SetImage("../media/380x370NomadAvatar.bmp");
	GOs.push_back(GO);
}

void Application::Update(float deltaTime)
{
	time += deltaTime;
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*object0.Draw
	(
		320.0f,
		240.0f,
		100.0f * time,
		0.25f * (sin(time + 1.0f) + 5.0f),
		0.5f * (sin(time + 1.0f) + 5.0f)
	);*/

	GameObject object0 = TemplateList::Get(GOs, 0);

	Vector2 position = Vector2(100.0f, 200.0f);
	float rotation = 45.0f;
	Vector2 scale = Vector2(2.0f, 3.0f);

	bool test = false;
	if (time > 3.0f)
	{
		test = true;
	}
	if (test)
	{
		rotation = 90.0f;
		position = Vector2(0.0f, 100.0f);
	}

	TemplateList::Get(GOs, 0).Draw(position, rotation, scale);

	TemplateList::Get(GOs, 1).Draw
	(
		300.0f * (sin(time - 1.0f) + 1.0f),
		100.0f * (sin(time - 1.0f) + 1.0f),
		-250.0f * time,
		0.5f * (sin(time - 5.0f) + 2.75f),
		0.75f * (sin(time - 5.0f) + 2.75f)
	);

	TemplateList::Get(GOs, 2).Draw
	(
		500.0f * (tan(time + 2.0f) + 1.0f),
		400.0f * (tan(time + 2.0f) + 1.0f),
		5.0f * time,
		10.0f * (sin(time + 2.0f) + 0.75f),
		5.0f * (sin(time + 2.0f) + 0.75f)
	);
}
