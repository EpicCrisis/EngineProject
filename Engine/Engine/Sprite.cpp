
#include "Matrix.h"
#include "Sprite.h"
#include "Draw.h"

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