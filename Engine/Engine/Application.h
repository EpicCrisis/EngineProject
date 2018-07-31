
#pragma once

#include <GLFW/glfw3.h>
#include "GameObjectSystem.h"

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

	void Start();
	void Update(float deltaTime);
	void Draw();
};

