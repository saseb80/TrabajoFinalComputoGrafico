#pragma once

#include <vector>
#include "Vector2.h"

class Matriz
{
private:
	std::vector<std::vector<float>> mat;
	unsigned rows;
	unsigned cols;
public:
	Matriz(unsigned rows, unsigned cols);
	virtual ~Matriz();

	/*float getRows();
	float getCols();*/
	Matriz& operator= (Matriz& rhs);
	Matriz& operator+ (Matriz& rhs);
	Matriz& suma(Matriz& rhs, Matriz& rhs2);
	Matriz& resta(Matriz& rhs, Matriz& rhs2);
	Matriz& operator- (Matriz& rhs);
	Matriz operator* (Matriz& rhs);
	Matriz transpose();

	/*Matrix& operator+ (float& );
	Matrix& operator- (float& );
	Matrix& operator* (float& );
	Matrix& operator/ (float& );

	Vector2 operator* (const Vector2&);*/
	float& operator()(const unsigned& i, const unsigned j);
	void printMatrix();

	unsigned getRows();
	unsigned getCols();
	void setRows(unsigned _rows);
	void setCols(unsigned _cols);


};
