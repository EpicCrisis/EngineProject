#pragma once

#include <GLFW/glfw3.h>
#include "GameObject.h"
#include "TemplateList.h"
#include <list>

using namespace std;

class Application
{
private:
	Application();
public:
    ~Application();

	// Create singleton.
	static Application& Instance();

	float time;

	list<GameObject> GOs;
	GameObject GO;

	void Start();
	void Update(float deltaTime);
	void Draw();
};

