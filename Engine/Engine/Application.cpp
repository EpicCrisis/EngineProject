#include "Application.h"
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;

Application::Application()
{
}

Application::~Application()
{
}

void Application::Start()
{
    //glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    //glDisable(GL_DEPTH_TEST);
}

void Application::Update(float DeltaTIme)
{
    cout << "Delta Time : " << DeltaTIme << endl;
    cout << "FPS : " << 1.0f / DeltaTIme << endl;
}

void Application::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
