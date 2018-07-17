
#include "Matrix.h"
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

void Sprite::LoadTexture(const char *path, GLuint textureID, unsigned int &width, unsigned int &height)
{
	CBitmap bitmap(path);

	glBindTexture(GL_TEXTURE_2D, textureID);

	// Repeat texture in tiles.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Horizontal texture.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Vertical texture.

																  // Bilinear filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Near filter.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Far filter.

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.GetWidth(), bitmap.GetHeight(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.GetBits());
}

void Sprite::DrawSquare(GLuint textureID, int xPos, int yPos, int width, int height)
{
	float halfW = (float)width * 0.5f;
	float halfH = (float)height * 0.5f;

	// Enable textures.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	GLfloat vertices[] =
	{
		xPos - halfW, yPos - halfH, 0.0f, // bottom left
		xPos - halfW, yPos + halfH, 0.0f, // top left
		xPos + halfW, yPos - halfH, 0.0f, // bottom right

		xPos - halfW, yPos + halfH, 0.0f, // top left
		xPos + halfW, yPos - halfH, 0.0f, // bottom right
		xPos + halfW, yPos + halfH, 0.0f  // top right
	};

	GLfloat texCoords[] =
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	GLubyte colors[] =
	{
		255, 255, 255,
		255, 255, 255,
		255, 255, 255,

		255, 255, 255,
		255, 255, 255,
		255, 255, 255
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
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
	LoadTexture(path.c_str(), m_textureID[0], m_width, m_height);
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
	DrawSquare(m_textureID[0], 0, 0, m_width, m_height);
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
