
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
	m_dummySprite0.LoadFilePath("../media/100x100Jake.bmp");
	m_dummySprite1.LoadFilePath("../media/225x225Solaire.bmp");
	m_dummySprite2.LoadFilePath("../media/380x370NomadAvatar.bmp");
}

void Application::Update(float deltaTime)
{
	time += deltaTime;
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_dummySprite0.Draw
	(
		320.0f,
		240.0f,
		100.0f * time,
		0.25f * (sin(time + 1.0f) + 5.0f),
		0.5f * (sin(time + 1.0f) + 5.0f)
	);

	m_dummySprite1.Draw
	(
		300.0f * (sin(time - 1.0f) + 1.0f),
		100.0f * (sin(time - 1.0f) + 1.0f),
		-250.0f * time,
		0.5f * (sin(time - 5.0f) + 2.75f),
		0.75f * (sin(time - 5.0f) + 2.75f)
	);

	m_dummySprite2.Draw
	(
		500.0f * (tan(time + 2.0f) + 1.0f),
		400.0f * (tan(time + 2.0f) + 1.0f),
		5.0f * time,
		10.0f * (sin(time + 2.0f) + 0.75f),
		5.0f * (sin(time + 2.0f) + 0.75f)
	);
}
