#pragma once

#include <string>
#include "GLFW/glfw3.h"
#include "Draw.h"
#include "Transform2D.h"
#include "Matrix.h"

using namespace std;

class Sprite
{
private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_textureID[1];

public:
    Sprite();
	Sprite(unsigned int width, unsigned int height);
	Sprite(const string& path);
    ~Sprite();	

	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
	int GetTextureID(int index) { return m_textureID[index]; };

	void LoadFilePath(const string& path);
	void SetTextureID(GLuint textureID);
	void SetDimension(unsigned int width, unsigned int height);
};

