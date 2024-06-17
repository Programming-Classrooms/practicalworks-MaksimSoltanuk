#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <set>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <iostream>


struct AuthorNames
{
	std::set<std::string> names;

	AuthorNames();
	void setAthorName(std::ifstream &);
	void checkName(std::string);

	void addName(std::string);
	void deleteName(std::string);

	bool operator==(const AuthorNames &other) const
	{
		if (names == other.names)
		{
			return true;
		}
		return false;
	}
};


struct Book : public AuthorNames
{
	size_t UDK_number;
	AuthorNames authorList;
	std::string bookName;
	std::string author;
	size_t yearOfPublic;

	Book();
	Book(size_t, std::string, std::string, size_t);

	bool operator<(const Book &other) const
	{
		return this->bookName < other.bookName;
	}
	bool operator==(const Book &other) const
	{
		if (UDK_number == other.UDK_number &&
			bookName == other.bookName &&
			author == other.author &&
			yearOfPublic == other.yearOfPublic)
		{
			return true;
		}
		return false;
	}
};


class Library
{
public:
	Library();
	Library(size_t, std::string, std::string, size_t);
	~Library();

	void addBook(size_t, std::string, std::string, size_t);
	void addBook(Book);
	void deleteBook(size_t, std::string, std::string, size_t);
	void deleteBook(Book);
	void FindByBookName(std::string);
	void FindAllAuthorBook(std::string);
	void addAuthor(Book, std::string);
	void deleteAuthor(Book);

private:
	std::map<Book, std::string> library;
};

#endif // !LIBRARY_HPP
