#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <cstdint>

class Matrix
{
private:
	uint16_t row; // строка
	uint16_t col; // столбец
	double** mtr; // двумерный массив
public:
	Matrix(); // по умолчанию 
	Matrix(const uint16_t&, const uint16_t&); // с параметрами
	Matrix(const Matrix&); // копирования
	Matrix(Matrix&&) noexcept; // перемещения
	~Matrix(); // деструктор

	Matrix& operator=(const Matrix&); // присваивание для матриц
	Matrix& operator=(const double&); // присваивание для чисел
	double* operator[](const size_t&); // []

	friend std::ostream& operator<<(std::ostream&, const Matrix&); // вывод
	friend std::istream& operator>>(std::istream&, Matrix&); // ввод

	Matrix operator+(const Matrix&); // плюс для матриц
	Matrix operator+(const double&); // плюс для чисел
	Matrix operator*(const double&); // умножение на константу
	friend Matrix operator*(const double&, const Matrix&); // умножение на константу слева
	Matrix operator/(const double&); // деление на константу
	Matrix operator-(const Matrix&); // вычитание матриц
	Matrix operator*(const Matrix&); // умножение матриц
	Matrix& operator+=(const Matrix&); // +=
	Matrix& operator-=(const Matrix&); // -=
	Matrix& operator*=(const Matrix&); //*=

	bool operator==(const Matrix&); // равенство
	bool operator!=(const Matrix&); // не равенство

	double getRow() const;
	double getCol() const;
};
#endif
