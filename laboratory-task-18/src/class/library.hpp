#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "book.hpp"
#include <map>
#include <algorithm>
#include <vector>

class Library
{
public:
	Library();
	~Library();

	void addBook(std::string, std::string, std::string, double, size_t);
	void findByISBN(std::string);
	void deleteByISBN(std::string);
	void checkAllBooks();
	void addAuthorByISBN(std::string, std::string);
	void deleteAuthorByISBN(std::string, std::string);
	void sortBooksByTitle();
	void sortBooksByISBN();

private:
	std::map<std::string, Book> library;
};

#endif
