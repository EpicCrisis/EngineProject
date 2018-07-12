
#include "Matrix.h"
#include "Draw.h"
#include "Sprite.h"

Sprite::Sprite()
{
    m_width = 128;
    m_height = 128;
}

Sprite::Sprite(unsigned int width, unsigned int height)
{
	SetDimension(width, height);
}

Sprite::Sprite(const string & path)
{
	LoadFilePath(path);
}

Sprite::~Sprite()
{
}

Matrix Sprite::Translate(int x, int y)
{
	return Matrix::makeTranslationMatrix(Vector(x, y, 0.0f));
}

Matrix Sprite::Rotate(float rotation)
{
	return Matrix::makeRotateMatrix(rotation, Vector(0.0f, 0.0f, 1.0f));
}

Matrix Sprite::Scale(float x, float y)
{
	return Matrix::makeScaleMatrix(Vector(x, y, 0.0f));
}

void Sprite::LoadFilePath(const string & path)
{
	glGenTextures(1, m_textureID);
	Draw::LoadTexture(path.c_str(), m_textureID[0], m_width, m_height);
}

void Sprite::SetTextureID(GLuint textureID)
{
	this->m_textureID[0] = textureID;
}

void Sprite::SetDimension(unsigned int width, unsigned int height)
{
	this->m_width = width;
	this->m_height = height;
}

void Sprite::Draw()
{
	Matrix transformMatrix = Translate(transform.position.x, transform.position.y);
	Matrix rotateMatrix = Rotate(transform.rotation);
	Matrix scaleMatrix = Scale(transform.scale.x, transform.scale.y);

	Matrix viewMatrix = transformMatrix * rotateMatrix * scaleMatrix;

	glLoadMatrixf((GLfloat*)viewMatrix.mVal);
	Draw::DrawSquare(m_textureID[0], 0, 0, m_width, m_height);
}

void Sprite::Draw(int xPos, int yPos, float rotation, float xScale, float yScale)
{
	transform.position.x = xPos;
	transform.position.y = yPos;
	transform.rotation = rotation;
	transform.scale.x = xScale;
	transform.scale.y = yScale;

	Draw();
}
