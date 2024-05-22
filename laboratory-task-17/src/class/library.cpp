#include "library.hpp"

// спиоск авторов
AuthorNames::AuthorNames()
{
	std::ifstream fin("../class/author.txt");
	AuthorNames::setAthorName(fin);
	fin.close();
}

void AuthorNames::setAthorName(std::ifstream &fin)
{
	std::string word;
	while (getline(fin, word, '\n'))
	{
		this->names.insert(word);
	}
}

void AuthorNames::checkName(std::string str)
{
	std::regex nameCheck("^\\b\\w+\\b\\s\\b\\w+\\b\\s\\b\\w+\\b$");
	if (!std::regex_match(str, nameCheck))
	{
		throw std::logic_error("you need write: surname name patronymic");
	}
}

void AuthorNames::addName(std::string str)
{
	checkName(str);
	this->names.insert(str);
}

void AuthorNames::deleteName(std::string str)
{
	checkName(str);
	for (const auto &item : names)
	{
		if (item == str)
		{
			this->names.erase(str);
			break;
		}
	}
}

// книги
Book::Book() : UDK_number(123), authorList(AuthorNames()), bookName("Vechera na hytore bliz Dikan'ke"), author("F I O"), yearOfPublic(2001) {}

Book::Book(size_t udk, std::string an, std::string bn, size_t yp) : UDK_number(udk), authorList(AuthorNames()), bookName(bn), author(an), yearOfPublic(yp)
{
	this->authorList.addName(an);
}

// библиотека
Library::Library()
{
	Book book;
	this->library.insert(std::make_pair(book, book.author));
}

Library::Library(size_t udk, std::string an, std::string bn, size_t yp)
{
	Book book(udk, an, bn, yp);
	this->library.insert(std::make_pair(book, an));
}

Library::~Library() {}

void Library::addBook(size_t udk, std::string an, std::string bn, size_t yp)
{
	Book book(udk, an, bn, yp);
	this->library.insert(std::make_pair(book, an));
}

void Library::addBook(Book book)
{
	library.insert(std::make_pair(book, book.author));
}

void Library::deleteBook(size_t udk, std::string an, std::string bn, size_t yp)
{
	Book temp(udk, an, bn, yp);
	for (auto item : library)
	{
		if (item.first == temp)
		{
			library.erase(temp);
			break;
		}
	}
}

void Library::deleteBook(Book book)
{
	library.erase(book);
}

void Library::FindByBookName(std::string name)
{
	bool flag = true;
	for (auto item : library)
	{
		if (item.first.bookName == name)
		{
			std::cout << item.first.bookName << '\n'
					  << item.second << '\n';
			flag = false;
		}
	}
	if (flag)
	{
		throw std::logic_error("haven't this book");
	}
}

void Library::FindAllAuthorBook(std::string an)
{
	bool flag = true;
	for (auto item : library)
	{
		if (item.second == an)
		{
			std::cout << item.first.bookName << '\n'
					  << item.second << '\n'
					  << "\n";
			flag = false;
		}
	}
	if (flag)
	{
		throw std::logic_error("haven't this book");
	}
}

void Library::addAuthor(Book book, std::string an)
{
	library.erase(book);
	book.author += ("   " + an);
	library[book] = book.author;
}

void Library::deleteAuthor(Book book)
{
	library.erase(book);
	book.author = "";
	library[book] = book.author;
}
