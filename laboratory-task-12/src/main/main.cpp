#include "../myString/myString.hpp"

int main()
{
	try
	{
		// конструкторы с параметрами
		MyString str1("FIRSTstring");
		MyString str2("SECONDstring");
		// вывод
		std::cout << str1 << '\n';
		// присваивание
		str1 = str2;
		// сравнение
		if (str1 == str2)
		{
			std::cout << "equal\n";
		}
		if (!(str1 != str2))
		{
			std::cout << "equal\n";
		}
		// составной операторо присваивания
		str2 += str1;
		std::cout << str2 << '\n';
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what();
	}
	return 0;
}