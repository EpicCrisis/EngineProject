
#include "Draw.h"

void Draw::LoadTexture(const char *path, GLuint textureID, unsigned int &width, unsigned int &height)
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

void Draw::DrawSquare(GLuint textureID, int xPos, int yPos, int width, int height)
{
	float halfW = (float)width * 0.5f;
	float halfH = (float)height * 0.5f;

	// Enable textures.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	GLfloat vertices[] =
	{
		xPos - halfW, yPos - halfH, 0.0f,
		xPos - halfW, yPos + halfH, 0.0f,
		xPos + halfW, yPos - halfH, 0.0f,

		xPos - halfW, yPos + halfH, 0.0f,
		xPos + halfW, yPos - halfH, 0.0f,
		xPos + halfW, yPos + halfH, 0.0f
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