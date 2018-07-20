#pragma once

#include <GLFW/glfw3.h>
#include "Bitmap.h"

class Draw
{
public:
	static void LoadTexture(const char *path, GLuint textureID, unsigned int &width, unsigned int &height);
	static void DrawSquare(GLuint textureID, int xPos, int yPos, int width, int height);
};

