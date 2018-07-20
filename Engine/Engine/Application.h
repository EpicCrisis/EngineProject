#pragma once

#include <GLFW/glfw3.h>
#include "Sprite.h"

class Application
{
public:
    Application();
    ~Application();

	// Create singleton.
	static Application& Instance();

	float time;

	Sprite m_dummySprite0;
	Sprite m_dummySprite1;
	Sprite m_dummySprite2;

	void Start();
	void Update(float deltaTime);
	void Draw();
};

