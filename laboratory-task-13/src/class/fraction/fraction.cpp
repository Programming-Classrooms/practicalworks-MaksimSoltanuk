#include "fraction.hpp"


//-----------------------------------------------------------------------------------// конструкторы и деструктор 
Fraction::Fraction() : n(0), d(1) { // по умолчанию
	std::cout << "default\n";
}
Fraction::Fraction(const int64_t n, const int64_t d) : n(n), d(d) { // с параметрами
	std::cout << "with parameters\n";
	if (d == 0 || d == 0.0) {
		throw std::logic_error("division by zero");
	}
}
Fraction::Fraction(const Fraction& f) : n(f.n), d(f.d) { // копирования
	std::cout << "copy\n";
}
Fraction::Fraction(Fraction&& f) noexcept : n(1), d(1) { // пермещения
	std::swap(n, f.n);
	std::swap(d, f.d);
	std::cout << "moving\n";
}
Fraction::~Fraction() { std::cout << "destuctor\n"; } // деструктор
//-----------------------------------------------------------------------------------// арифметические операции
Fraction Fraction::operator+(const Fraction& f) { // +
	return Fraction((n * f.d) + (f.n * d), d * f.d);
}
Fraction Fraction::operator+(const int64_t& i) {
	return Fraction(n + (i * d), d);
}
Fraction operator+(const int64_t& i, const Fraction& f) {
	return Fraction(f.n + (i * f.d), f.d);
}
Fraction Fraction::operator-(const Fraction& f) { // -
	return Fraction((n * f.d) - (f.n * d), d * f.d);
}
Fraction Fraction::operator-(const int64_t& i) {
	return Fraction(n - (i * d), d);
}
Fraction operator-(const int64_t& i, const Fraction& f) {
	return Fraction((i * f.d) - f.n, f.d);
}
Fraction Fraction::operator*(const Fraction& f) { // *
	return Fraction(n * f.n, d * f.d);
}
Fraction Fraction::operator*(const int64_t& i) {
	return Fraction(n * i, d);
}
Fraction operator*(const int64_t& i, const Fraction& f) {
	return Fraction(i*f.n, f.d);
}
Fraction Fraction::operator/(const Fraction& f) { // /
	if (f.n == 0) {
		throw std::logic_error("division by zero");
	}
	return Fraction(n * f.d, d * f.n);
}
Fraction Fraction::operator/(const int64_t& i) {
	if (i == 0) {
		throw std::logic_error("division by zero");
	}
	return Fraction(n, d * i);
}
Fraction operator/(const int64_t& i, const Fraction& f) {
	if (f.n == 0) {
		throw std::logic_error("division by zero");
	}
	return Fraction(i * f.d, f.n);
}
Fraction Fraction::operator^(const int64_t& degree) { // ^ // возведение в степень(в отрицательную тоже можно)
	Fraction res(1, 1);
	Fraction start = *this;
	if (degree == 0) {
		return res;
	}
	if (degree < 0) {
		start = !start;
	}
	for (size_t i = 0; i < abs(degree); ++i) {
		res = res * start;
	}
	return res;
}
//-----------------------------------------------------------------------------------// операторы сравнения
bool Fraction::operator>(const Fraction& f) { // >
	if (doubleForm(*this) > doubleForm(f)) {
		return true;
	}
	else {
		return false;
	}
}
bool Fraction::operator<(const Fraction& f) { // <
	if (doubleForm(*this) < doubleForm(f)) {
		return true;
	}
	else {
		return false;
	}
}
bool Fraction::operator>=(const Fraction& f) { // >=
	return (doubleForm(*this) > doubleForm(f) || (n == f.n && d == f.d));
}
bool Fraction::operator<=(const Fraction& f) { // <=
	if (doubleForm(*this) < doubleForm(f) || (n == f.n && d == f.d)) {
		return true;
	}
	else {
		return false;
	}
}
bool Fraction::operator==(const Fraction& f) { // ==
	if (n == f.n && d == f.d) {
		return true;
	}
	else {
		return false;
	}
}
bool Fraction::operator!=(const Fraction& f) { // !=
	if (n != f.n || d != f.d) {
		return true;
	}
	else {
		return false;
	}
}
//-----------------------------------------------------------------------------------// инкременты и декременты
Fraction& Fraction::operator++() { // ++префиксный
	n += d;
	return *this;
}
Fraction& Fraction::operator--() { // --префиксный
	n -= d;
	return *this;
}
Fraction Fraction::operator++(int) { // постфиксный++
	Fraction start (*this);
	n += d;
	return start;
}
Fraction Fraction::operator--(int) { // постфиксный--
	Fraction start (*this);
	n -= d;
	return start;
}
//-----------------------------------------------------------------------------------// унарный минус
Fraction Fraction::operator-() { // унарный минус
	return Fraction(-n, d);
}
//-----------------------------------------------------------------------------------// оператор получения обратной дроби
Fraction Fraction::operator!() { // обратная дробь
	return Fraction(d, n);
}
//-----------------------------------------------------------------------------------// ввод из потока
std::istream& operator>>(std::istream& in, Fraction& f) {
	std::cout << "Input numerator and denamenator:\n";
	in >> f.n >> f.d;
	if (f.d == 0 || f.d == 0.0) {
		throw std::logic_error("division by zero");
	}
	if (f.d < 0 || f.d < 0.0) {
		f.n *= -1;
		f.d *= -1;
	}
	return in;
}
//-----------------------------------------------------------------------------------// вывод в поток
std::ostream& operator<<(std::ostream& out, Fraction& f) {
	if (f.d < 0 || f.d < 0.0) {
		f.n *= -1;
		f.d *= -1;
	}
	f.reduction(f);
	if (f.d == 0 || f.d == 0.0) {
		throw std::logic_error("division by zero");
	}
	if (f.d != 1 || f.d != 1.0) {
		return out << "(" << f.n << "/" << f.d << ")" << '\n';
	}
	else {
		return out << f.n << '\n';
	}
}
//-----------------------------------------------------------------------------------// вещественная форма
double Fraction::doubleForm(const Fraction& f) { // вещественная форма
	return static_cast<double>(f.n) / (f.d);
}
//-----------------------------------------------------------------------------------// присваивания
Fraction& Fraction::operator=(const Fraction& f) { // присваивание
	if (this != &f) {
		n = f.n;
		d = f.d;
	}
	return *this;
}
//-----------------------------------------------------------------------------------// составные операторы присваивания
Fraction& Fraction::operator+=(const Fraction& f) {
	d = (n * f.d) + (f.n * d);
	n = d * f.d;
	return *this;
}
Fraction& Fraction::operator+=(const int64_t& i) {
	n += (i * d);
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& f) {
	n = (n * f.d) - (f.n * d);
	d = d * f.d;
	return *this;
}
Fraction& Fraction::operator-=(const int64_t& i) {
	n -= (i * d);
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& f) {
	n = n * f.n;
	d = d * f.d;
	return *this;
}
Fraction& Fraction::operator*=(const int64_t& i) {
	n *= i;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& f) {
	if (f.n == 0) {
		throw std::logic_error("division by zero");
	}
	n = n * f.d;
	d = d * f.n;
	return *this;
}
Fraction& Fraction::operator/=(const int64_t& i) {
	d *= i;
	return *this;
}
int64_t Fraction::getNumerator() const
{
    return n;
}
int64_t Fraction::getDenominator() const
{
    return d;
}
//-----------------------------------------------------------------------------------// максимальное сокращение дроби
Fraction& Fraction::reduction(Fraction& f) {
	int64_t n = abs(f.n), d = abs(f.d), start = f.n;
	for (size_t i = 2; i <= fmin(n, d); ++i) {
		if ((n % i == 0) && (d % i == 0)) {
			n /= i;
			d /= i;
			i = 1;
		}
	}
	f.n = n;
	f.d = d;
	if (start < 0) {
		f.n *= -1;
	}
	return *this;
}

