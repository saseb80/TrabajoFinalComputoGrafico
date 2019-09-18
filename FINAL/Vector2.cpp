#include "pch.h"
#include "Vector2.h"
#include"SDL.h"
#include<cmath>


Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;

}

Vector2::Vector2()
{

}

void Vector2::setX(float _x)
{
	x = _x;
}

void Vector2::setY(float _y)
{
	y = _y;
}


int Vector2::getX()
{
	return x;
}

int Vector2::getY()
{
	return y;
}


void Vector2::suma(Vector2 v1)
{
	this->x = this->x + v1.x;
	this->y = this->y + v1.y;
}

void Vector2::rotacion(int angulo)
{
	int x2 = this->x;
	this->x = (this->x*(cos(angulo*0.0174533))) + (this->y*(-sin(angulo*0.0174533)));
	this->y = (x2*(sin(angulo*0.0174533))) + (this->y*(cos(angulo*0.0174533)));
}

void Vector2::escalamiento(int tamaniox, int tamanioy)
{
	this->x = (this->x * tamaniox);
	this->y = (this->y * tamanioy);
}

void Vector2::resta(Vector2 v1)
{
	x = x - v1.x;
	y = y - v1.x;
}

int Vector2::Punto(Vector2 v1)
{
	return (x * v1.x) + (y * v1.y);
}

void Vector2::Cruz(Vector2 v1)
{

}

Vector2 Vector2::operator+ (Vector2 param)
{
	Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

Vector2 Vector2::operator- (Vector2 param)
{
	Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}

float Vector2:: operator* (Vector2 param)
{
	float temp;
	temp = (x * param.x) + (y * param.y);
	return temp;
}

Vector2 Vector2::operator*(float x)
{
	Vector2 temp;
	temp.x = x * this->x;
	temp.y = y * this->y;
	return temp;
}

//Vector2 Vector2::operator= (Vector2 param) 
//{
//
//}

Vector2::~Vector2()
{
}
