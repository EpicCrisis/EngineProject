#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetTransform(Transform2D _transform)
{
	transform = _transform;
}

Matrix GameObject::SetTranslate(int x, int y)
{
	return Matrix::makeTranslationMatrix(Vector(x, y, 0.0f));
}

Matrix GameObject::SetRotate(float rotation)
{
	return Matrix::makeRotateMatrix(rotation, Vector(0.0f, 0.0f, 1.0f));
}

Matrix GameObject::SetScale(float x, float y)
{
	return Matrix::makeScaleMatrix(Vector(x, y, 0.0f));
}

void GameObject::SetImage(const string & path)
{
	sprite.LoadFilePath(path);
}

void GameObject::Draw()
{
	translateMatrix = SetTranslate(transform.position.x, transform.position.y);
	rotateMatrix = SetRotate(transform.rotation);
	scaleMatrix = SetScale(transform.scale.x, transform.scale.y);

	Matrix viewMatrix = translateMatrix * rotateMatrix * scaleMatrix;

	glLoadMatrixf((GLfloat*)viewMatrix.mVal);
	Draw::DrawSquare(sprite.GetTextureID(0), 0, 0, sprite.GetWidth(), sprite.GetHeight());
}

void GameObject::Draw(int xPos, int yPos, float rotation, float xScale, float yScale)
{
	transform.position.x = xPos;
	transform.position.y = yPos;
	transform.rotation = rotation;
	transform.scale.x = xScale;
	transform.scale.y = yScale;

	Draw();
}

void GameObject::Draw(Vector2 position, float rotation, Vector2 scale)
{
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	Draw();
}

void GameObject::Draw(Transform2D _transform)
{
	transform = _transform;

	Draw();
}

void GameObject::Start()
{

}

void GameObject::Update(float deltaTime)
{

}