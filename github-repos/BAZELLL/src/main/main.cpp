#include"../functions/MyString.hpp"

int main() {
	//try
	//{
		MYSTRING str1 = "FIRSTstring";
		MYSTRING str2 = "SECONDstring";
		std::cout << str1 + " " + str2 << '\n';
	    str2 += str1;
		std::cout << str2 << '\n';
	//}
	//catch (const std::exception& err)
	//{
	//	std::cerr << err.what();
	//}
	return 0;
}