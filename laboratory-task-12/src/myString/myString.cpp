#include "../myString/myString.hpp"

MyString::MyString() : str(nullptr), size(0) {} // по умолчанию

MyString::MyString(const char *s) : str(nullptr), size(0) // с параметрами
{
	if (s)
	{
		size = std::strlen(s);
		str = new char[size + 1];
		std::strcpy(str, s);
	}
}

MyString::MyString(const MyString &rhs) : str(nullptr), size(0) // копирования
{
	size = rhs.size;
	if (size > 0)
	{
		str = new char[size + 1];
		std::strcpy(str, rhs.str);
	}
}

MyString::~MyString() // деструктор
{
	delete[] str;
}

MyString &MyString::operator=(const MyString &rhs) // присваивание
{
	if (this != &rhs)
	{
		delete[] str;
		size = rhs.size;
		if (size > 0)
		{
			str = new char[size + 1];
			std::strcpy(str, rhs.str);
		}
		else
		{
			str = nullptr;
		}
	}
	return *this;
}

MyString MyString::operator+(const MyString &rhs) const // плюс
{
	MyString result;
	result.size = size + rhs.size;
	result.str = new char[result.size + 1];
	if (size > 0)
	{
		std::strcpy(result.str, str);
	}
	if (rhs.size > 0)
	{
		std::strcat(result.str, rhs.str);
	}
	return result;
}

MyString &MyString::operator+=(const MyString &rhs) // составной оператор присваивания
{
	*this = *this + rhs;
	return *this;
}

bool MyString::operator==(const MyString &rhs) const // равно
{
	return (size == rhs.size) && (std::strcmp(str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString &rhs) const // не равно
{
	return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &out, const MyString &string) // вывод
{
	if (string.getStr())
	{
		out << string.getStr();
	}
	return out;
}

const char *MyString::getStr() const
{
	return str;
}

int64_t MyString::getSize() const
{
	return size;
}