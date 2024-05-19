#include "book.hpp"

Book::Book() {}

Book::Book(std::string isbn, std::string name, std::string author, double money, size_t count) : title(name), price(money), count(count)
{
	ISBN.insert(isbn);
	authors.insert(author);
}

Book::~Book() {}

void Book::outputBookInfo(Book book)
{
	std::cout << "book: " << book.title << '\n';
	std::cout << "author(s): ";
	for (const auto &item : book.authors)
	{
		std::cout << item << "\t";
	}
	std::cout << '\n';
	std::cout << "ISBN: ";
	for (const auto &item : book.ISBN)
	{
		std::cout << item << "\n";
	}
	std::cout << "count: " << book.count << '\n';
	std::cout << "price: " << book.price << '\n';
}

void Book::addAuthor(std::string author)
{
	authors.insert(author);
}

void Book::deleteAuthor(std::string author)
{
	auto it = authors.find(author);
	if (it != authors.end())
	{
		authors.erase(it);
	}
	else
	{
		std::cout << "haven't this author\n";
	}
}
