#include"pch.h"
#include "Matriz.h"
#include <iostream>

Matriz::Matriz(unsigned rows, unsigned cols) {
	mat.resize(rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(cols, 0);
	}
	/*rows = _rows;
	cols = _cols;*/
}

float& Matriz::operator()(const unsigned& i, const unsigned j) {
	return (mat[i][j]);
}


void Matriz::setRows(unsigned _rows) {
	rows = _rows;
}

void Matriz::setCols(unsigned _cols) {
	cols = _cols;
}

unsigned Matriz::getRows() {
	return rows;
}

unsigned Matriz::getCols() {
	return cols;
}

Matriz& Matriz::operator+(Matriz& rhs) {
	Matriz mat2(getRows(), getCols());
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			rhs(i, j) = rhs(i, j) + mat2(i, j);
			std::cout << rhs(i, j) << std::endl;
		}
	}
	return rhs;
}

Matriz& Matriz::suma(Matriz& rhs, Matriz& rhs2) {
	Matriz mat2(getRows(), getCols());
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			rhs(i, j) = rhs(i, j) + rhs2(i, j);
			std::cout << rhs(i, j) << std::endl;
		}
	}
	return rhs;
}

Matriz& Matriz::resta(Matriz& rhs, Matriz& rhs2) {
	Matriz mat2(getRows(), getCols());
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			rhs(i, j) = rhs(i, j) - rhs2(i, j);
			std::cout << rhs(i, j) << std::endl;
		}
	}
	return rhs;
}

Matriz& Matriz::operator-(Matriz& rhs) {
	Matriz mat2(getRows(), getCols());
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			rhs(i, j) = rhs(i, j) - mat2(i, j);
		}
	}
	return rhs;
}

Matriz& Matriz::operator= (Matriz& rhs) {
	return rhs;
}

void Matriz::printMatrix() {
	/*for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			rhs(i, j) = rhs(i, j) - mat2(i, j);
			std::cout <<  << std::endl;
		}
	}*/
}

//Matrix Matrix::operator*(Matrix& rhs) {
//    Matrix mat2(getRows(), getCols());
//    Matrix mult(getRows(), getCols());
//    for (unsigned i = 0; i < rows; i++) {
//        for (unsigned j = 0; j < cols; j++) {
//            for (unsigned k = 0; k < cols; k++) {
//                mult(i,j) += rhs(i, j) * mat2(i, j);
//            }
//        }
//    }
//    return mult;
//}

Matriz::~Matriz() {
}