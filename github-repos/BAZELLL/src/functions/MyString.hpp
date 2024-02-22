#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>
#include <cstring>


class MYSTRING {
private:
	char* str;
	uint64_t size;
public:
	MYSTRING(); 
	MYSTRING(const char*); 
	friend std::ostream& operator<<(std::ostream&, const MYSTRING&); 
	MYSTRING& operator+(const MYSTRING&); 
	MYSTRING& operator=(const MYSTRING&); 
	MYSTRING& operator+=(const MYSTRING&); 
	bool operator==(const MYSTRING&); 
	bool operator!=(const MYSTRING&); 
	~MYSTRING(); 
};

#endif