#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>
#include <cstring>
#include <cstdint>

class MyString
{
public:
	// Конструкторы и деструктор
	MyString();						 // Конструктор по умолчанию
	MyString(const char *s);		 // Конструктор с параметром
	MyString(const MyString &other); // Конструктор копирования
	~MyString();					 // Деструктор

	// Операторы
	MyString &operator=(const MyString &other);									// Оператор присваивания
	MyString operator+(const MyString &other) const;							// +
	MyString &operator+=(const MyString &other);								// составной оператор присваивания
	bool operator==(const MyString &other) const;								// равно
	bool operator!=(const MyString &other) const;								// не равно
	friend std::ostream &operator<<(std::ostream &out, const MyString &string); // вывод

	const char *getStr() const; 
	int64_t getSize() const;	

private:
	char *str;	  
	int64_t size; 
};

#endif