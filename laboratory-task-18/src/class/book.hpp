#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <set>

class Book
{
public:
	Book();
	Book(std::string, std::string, std::string, double, size_t);
	~Book();

	void outputBookInfo(Book);
	void addAuthor(std::string);
	void deleteAuthor(std::string);

public:
	std::set<std::string> ISBN;
	std::string title;
	std::set<std::string> authors;
	double price;
	size_t count;
};

#endif
