#pragma once
class Vector2
{
private:
	int x, y;
public:
	Vector2(float x, float y);
	Vector2();
	void setX(float _x);
	void setY(float _y);

	int getX();
	int getY();

	void suma(Vector2 v1);
	void resta(Vector2 v1);
	int Punto(Vector2 v1);
	void Cruz(Vector2 v1);
	Vector2 operator+ (Vector2);
	void rotacion(int angulo);
	void escalamiento(int tamaniox, int tamanioy);
	Vector2 operator- (Vector2);
	Vector2 operator* (float x);
	float operator* (Vector2 param);
	//Vector2 operator= (Vector2);
	~Vector2();
};

