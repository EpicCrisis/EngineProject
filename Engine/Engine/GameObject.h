#pragma once

#include "Sprite.h"
#include "Transform2D.h"

class GameObject
{
private:
	Transform2D transform;
	Matrix translateMatrix;
	Matrix rotateMatrix;
	Matrix scaleMatrix;

	Matrix SetTranslate(int x, int y);
	Matrix SetRotate(float rotation);
	Matrix SetScale(float x, float y);

public:
	GameObject();
	~GameObject();

	Sprite sprite;

	Transform2D GetTransform() { return transform; };
	Matrix GetTranslate() { return translateMatrix; };
	Matrix GetRotate() { return rotateMatrix; };
	Matrix GetScale() { return scaleMatrix; };

	void SetTransform(Transform2D _transform);
	void SetImage(const string& path);

	void Start();
	void Update(float deltaTime);

	// Overload draw functions.
	void Draw();
	void Draw(int xPos, int yPos, float rotation, float xScale, float yScale);
	void Draw(Vector2 position, float rotation, Vector2 scale);
	void Draw(Transform2D _transform);
};

