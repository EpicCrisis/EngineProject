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

	Transform2D transform;
	Matrix translateMatrix;
	Matrix rotateMatrix;
	Matrix scaleMatrix;

public:
    Sprite();
	Sprite(unsigned int width, unsigned int height);
	Sprite(const string& path);
    ~Sprite();	

	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
	int GetTextureID(int index) { return m_textureID[index]; };

	Transform2D GetTransform() { return transform; };
	Matrix GetTranslate() { return translateMatrix; };
	Matrix GetRotate() { return rotateMatrix; };
	Matrix GetScale() { return scaleMatrix; };

	void SetTransform(Transform2D _transform);
	Matrix SetTranslate(int x, int y);
	Matrix SetRotate(float rotation);
	Matrix SetScale(float x, float y);

	void LoadFilePath(const string& path);
	void SetTextureID(GLuint textureID);
	void SetDimension(unsigned int width, unsigned int height);

	// Overload draw functions.
	void Draw();
	void Draw(int xPos, int yPos, float rotation, float xScale, float yScale);
	void Draw(Vector2 position, float rotation, Vector2 scale);
	void Draw(Transform2D _transform);
};

