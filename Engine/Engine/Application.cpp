
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
	cout << "APPLICATION STARTED" << endl;
}

void Application::Update(float deltaTime)
{
	cout << "APPLICATION UPDATED" << endl;

	time += deltaTime;

	
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw function
}