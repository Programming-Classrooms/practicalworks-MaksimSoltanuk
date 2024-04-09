#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <cstdint>
#include <cmath>


class Fraction
{
private:
	int64_t n; // числитель
	int64_t d; // делитель
	//-----------------------------------------------------------------------------------// хранение дроби (в не сокращаемом виде)
	Fraction& reduction(Fraction&); // сокращение дроби
public:
//-----------------------------------------------------------------------------------//	конструкторы, детсруктор
	Fraction(); // по умолчанию
	Fraction(const int64_t, const int64_t); // с параметрами
	Fraction(const Fraction&); // копирования
	Fraction(Fraction&&) noexcept; // перемещения
	~Fraction(); // деструктор
//-----------------------------------------------------------------------------------// арифметические операции
	Fraction operator+(const Fraction&); // +
	Fraction operator+(const int64_t&);
	friend Fraction operator+(const int64_t&, const Fraction&);
	Fraction operator-(const Fraction&); // -
	Fraction operator-(const int64_t&);
	friend Fraction operator-(const int64_t&, const Fraction&);
	Fraction operator*(const Fraction&); // *
	Fraction operator*(const int64_t&);
	friend Fraction operator*(const int64_t&, const Fraction&);
	Fraction operator/(const Fraction&); // /
	Fraction operator/(const int64_t&);
	friend Fraction operator/(const int64_t&, const Fraction&);
	Fraction operator^(const int64_t&); // ^
//-----------------------------------------------------------------------------------// операторы сравнения
	bool operator>(const Fraction&); // >
	bool operator<(const Fraction&); // <
	bool operator>=(const Fraction&); // >=
	bool operator<=(const Fraction&); // <=
	bool operator==(const Fraction&); // ==
	bool operator!=(const Fraction&); // !=
//-----------------------------------------------------------------------------------// инкременты и декременты
	Fraction& operator++(); // постфиксный
	Fraction& operator--(); // постфиксный
	Fraction operator++(int); // префиксный
	Fraction operator--(int); // префиксный
//-----------------------------------------------------------------------------------// унарный минус
	Fraction operator-(); // унарный минус
//-----------------------------------------------------------------------------------// оператор получения обратной дроби
	Fraction operator!(); // обратная дробь
//-----------------------------------------------------------------------------------// ввод в поток
	friend std::istream& operator>>(std::istream&, Fraction&); // ввод
//-----------------------------------------------------------------------------------// вывод в поток
	friend std::ostream& operator<<(std::ostream&, Fraction&); // вывод
//-----------------------------------------------------------------------------------// приведение к вещественному типу
	double doubleForm(const Fraction&); //  вещественная форма
//-----------------------------------------------------------------------------------// оператор присваивания
	Fraction& operator=(const Fraction&); // присваивание
//-----------------------------------------------------------------------------------// составные операторы присваивания
	Fraction& operator+=(const Fraction&); // +=
	Fraction& operator+=(const int64_t&);
	Fraction& operator-=(const Fraction&); // -=
	Fraction& operator-=(const int64_t&);
	Fraction& operator*=(const Fraction&); // *=
	Fraction& operator*=(const int64_t&);
	Fraction& operator/=(const Fraction&); // /=
	Fraction& operator/=(const int64_t&);

	int64_t getNumerator() const;
	int64_t getDenominator() const;
};
#endif
