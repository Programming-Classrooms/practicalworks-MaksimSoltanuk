#include "matrix.hpp"


//-----------------------------------------------------------------// конструкторы и деструктор
Matrix::Matrix() : row(1), col(1), mtr(new double* [row]) { // по умолчанию
	for (size_t i = 0; i < row; ++i) {
		mtr[i] = new double[col];
	}
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			mtr[i][j] = 0;
		}
	}
	std::cout << "default\n";
}
Matrix::Matrix(const uint8_t& r, const uint8_t& c) : row(r), col(c), mtr(new double* [r]) { // с параметрами
	if (c < 1 || r < 1) {
		throw std::logic_error("it isn't imposible");
	}
	for (size_t i = 0; i < row; ++i) {
		mtr[i] = new double[col];
	}
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			mtr[i][j] = 0;
		}
	}
	std::cout << "parametrs\n";
}
Matrix::Matrix(const Matrix& m) : row(m.row), col(m.col), mtr(new double* [m.row]) { // копирования
	if (m.col < 1 || m.row < 1) {
		throw std::logic_error("it isn't imposible");
	}
	for (size_t i = 0; i < row; ++i) {
		mtr[i] = new double[col];
		for (size_t j = 0; j < col; ++j) {
			mtr[i][j] = m.mtr[i][j];
		}
	}
	std::cout << "copy\n";
}
Matrix::Matrix(Matrix&& m) noexcept : row(m.row), col(m.col), mtr(m.mtr) { // перемещения
	m.row = 0;
	m.col = 0;
	m.mtr = nullptr;
	std::cout << "move";
}
Matrix::~Matrix() { // деструктор
	for (size_t i = 0; i < row; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
	std::cout << "destructor\n";
}
//-----------------------------------------------------------------// оператор присваивания
Matrix& Matrix::operator=(const Matrix& m) { // присваивание с матрицы
	if (this != &m) {
		for (size_t i = 0; i < row; ++i) {
			delete[] mtr[i];
		}
		delete[] mtr;
		row = m.row;
		col = m.col;
		mtr = new double* [row];
		for (size_t i = 0; i < row; ++i) {
			mtr[i] = new double[col];
			for (size_t j = 0; j < col; ++j) {
				mtr[i][j] = m.mtr[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator=(const double& num) { // присваивание числа(если матрица квадратная, то число превращается матрицу равной единичная умножить на число)
	if (col == row) {
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				mtr[i][j] = 0;
			}
		}
		for (size_t i = 0; i < row; ++i) {
			mtr[i][i] = num;
		}
	}
	else {
		throw std::logic_error("matrix must be square");
	}
	return *this;
}
//-----------------------------------------------------------------// составные операторы присваивания
Matrix& Matrix::operator+=(const Matrix& m) {
	if (row == m.row && col == m.col) {
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				mtr[i][j] += m.mtr[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& m) {
	if (row == m.row && col == m.col) {
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				mtr[i][j] -= m.mtr[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& m) {
	if (col != m.row) {
		throw std::logic_error("ñolumns of the first matrix must be equal to rows of the second matrix");
	}
	if (row == m.row && m.col == col) {
		Matrix mtrCopy(row, m.col);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < m.col; ++j) {
				mtrCopy.mtr[i][j] = 0;
				for (int k = 0; k < col; ++k) {
					mtrCopy.mtr[i][j] += mtr[i][k] * m.mtr[k][j];
				}
			}
		}
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				this->mtr[i][j] = mtrCopy.mtr[i][j];
			}
		}
	}
	else {
		throw std::logic_error("rows of the first matrix must be equal to columns of the second matrix");
	}
	return *this;
}
//-----------------------------------------------------------------// умножение на константу слева
Matrix operator*(const double& num, const Matrix& m) {
	Matrix res(m.row, m.col);
	for (size_t j = 0; j < m.row; ++j) {
		for (size_t i = 0; i < m.col; ++i) {
			res[j][i] = num * m.mtr[j][i];
		}
	}
	return res;
}
//-----------------------------------------------------------------// умножение на константу справа
Matrix Matrix::operator*(const double& num) {
	Matrix res(row, col);
	for (size_t j = 0; j < row; ++j) {
		for (size_t i = 0; i < col; ++i) {
			res[j][i] = num * mtr[j][i];
		}
	}
	return res;
}
//-----------------------------------------------------------------// деление на константу
Matrix Matrix::operator/(const double& num) {
	Matrix res(row, col);
	for (size_t j = 0; j < row; ++j) {
		for (size_t i = 0; i < col; ++i) {
			res[j][i] = mtr[j][i] / num;
		}
	}
	return res;
}
//-----------------------------------------------------------------// плюс для матрицы
Matrix Matrix::operator+(const Matrix& m) {
	Matrix copy(row, col);
	if (row == m.row && col == m.col) {
		for (size_t j = 0; j < row; ++j) {
			for (size_t i = 0; i < col; ++i) {
				copy[j][i] = mtr[j][i] + m.mtr[j][i];
			}
		}
	}
	else {
		throw std::logic_error("matrix is little");
	}
	return copy;
}
//-----------------------------------------------------------------// плюс для числа 
Matrix Matrix::operator+(const double& num) {
	Matrix copy(row, col);
	Matrix res(row, col);
	copy = num;
	res = copy;
	for (size_t j = 0; j < row; ++j) {
		for (size_t i = 0; i < col; ++i) {
			res[j][i] = copy[j][i] + mtr[j][i];
		}
	}
	return res;
}
//-----------------------------------------------------------------// минус для матрицы
Matrix Matrix::operator-(const Matrix& m) {
	Matrix copy(row, col);
	if (row == m.row && col == m.col) {
		for (size_t j = 0; j < row; ++j) {
			for (size_t i = 0; i < col; ++i) {
				copy[j][i] = mtr[j][i] - m.mtr[j][i];
			}
		}
	}
	else {
		throw std::logic_error("matrix is little");
	}
	return copy;
}
//-----------------------------------------------------------------// умножение матриц
Matrix Matrix::operator*(const Matrix& m) {
	if (col != m.row) {
		throw std::logic_error("ñolumns of the first matrix must be equal to rows of the second matrix");
	}
	Matrix mtrCopy(row, m.col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < m.col; ++j) {
			mtrCopy.mtr[i][j] = 0;
			for (int k = 0; k < col; ++k) {
				mtrCopy.mtr[i][j] += mtr[i][k] * m.mtr[k][j];
			}
		}
	}
	return mtrCopy;
}
//-----------------------------------------------------------------// операторы сравнения
bool Matrix::operator==(const Matrix& m) {
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			if (m.mtr[i][j] != mtr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool Matrix::operator!=(const Matrix& m) {
	uint16_t count = 0;
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			if (m.mtr[i][j] == mtr[i][j]) {
				++count;
			}
		}
	}
	if (count == (row*col)) {
		return false;
	}
	return true;
}
double Matrix::getRow() const
{
    return row;
}
double Matrix::getCol() const
{
    return col;
}
//-----------------------------------------------------------------// вывод и ввод
std::ostream& operator<<(std::ostream& out, const Matrix& m) {
	for (size_t i = 0; i < m.row; ++i) {
		for (size_t j = 0; j < m.col; ++j) {
			out << m.mtr[i][j] << ' ';
		}
		out << '\n';
	}
	return out;
}
std::istream& operator>>(std::istream& in, Matrix& m) {
	std::cout << "how high and wide is it?\n";
	size_t newRow, newCol;
	in.clear();
	in >> newRow >> newCol;
	uint64_t res = newRow * newCol;
	std::cout << "input " << res << " elements\n";
	Matrix tempMtr(newRow, newCol);
	for (size_t i = 0; i < newRow; ++i) {
		for (size_t j = 0; j < newCol; ++j) {
			in >> tempMtr[i][j];
		}
	}
	m = std::move(tempMtr);
	return in;
}
//-----------------------------------------------------------------// []
double* Matrix::operator[](const size_t& i) {
	return mtr[i];
}
