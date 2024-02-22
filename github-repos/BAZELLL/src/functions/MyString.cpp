#define _CRT_SECURE_NO_WARNINGS
#include"MyString.hpp"


MYSTRING::MYSTRING() : size(size), str(nullptr) { 
	std::cout << "constructor\n";
}

MYSTRING::MYSTRING(const char* s) : size(size), str(nullptr) { 
	size = strlen(s);
	if (size < 0) {
		//throw std::exception("Size of string < 0!");
	}
	str = new char[size + 1];
	strcpy(str, s);
	std::cout << "constructor of copy\n";
}

std::ostream& operator<<(std::ostream& out, const MYSTRING& string) { 
	out << string.str;
	return out;
}



MYSTRING& MYSTRING::operator+(const MYSTRING& right) { 
	size_t newSIZE = size + right.size;
	char* STRnew = new char[newSIZE + 1];
	strcpy(STRnew, str);
	strcat(STRnew, right.str);
	str = STRnew;
	size = newSIZE;
	return *this;
}

MYSTRING& MYSTRING::operator=(const MYSTRING& right) { 
	size = right.size;
	delete[] str;
	str = new char[size + 1];
	strcpy(str, right.str);
	return *this;
}

MYSTRING& MYSTRING::operator+=(const MYSTRING& right) { 
	size_t newSIZE = size + right.size;
	char* STRnew = new char[newSIZE + 1];
	strcpy(STRnew, str);
	strcat(STRnew, right.str);
	str = STRnew;
	size = newSIZE;
	return *this;
}

bool MYSTRING::operator==(const MYSTRING& right) { 
	return !strcmp(str, right.str);
}

bool MYSTRING::operator!=(const MYSTRING& right) { 
	return !(this->str == right.str);
}


MYSTRING::~MYSTRING() { 
	std::cout << "destructor\n";
	delete[] str;
}