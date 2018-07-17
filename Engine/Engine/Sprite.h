#pragma once

#include <string>
#include "GLFW/glfw3.h"
#include "Transform2D.h"
#include "Bitmap.h"

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

	Transform2D transform;
	Matrix Translate(int x, int y);
	Matrix Rotate(float rotation);
	Matrix Scale(float x, float y);

	void LoadTexture(const char *path, GLuint textureID, unsigned int &width, unsigned int &height);
	void DrawSquare(GLuint textureID, int xPos, int yPos, int width, int height);
	void LoadFilePath(const string& path);
	void SetTextureID(GLuint textureID);
	void SetDimension(unsigned int width, unsigned int height);
	
	// Overload draw functions.
	void Draw();
	void Draw(int xPos, int yPos, float rotation, float xScale, float yScale);
};

