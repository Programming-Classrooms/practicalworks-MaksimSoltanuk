#include "library.hpp"

Library::Library() {}

Library::~Library() {}

void Library::addBook(std::string isbn, std::string name, std::string author, double money, size_t count)
{
    library.insert({isbn, Book(isbn, name, author, money, count)});
}

void Library::findByISBN(std::string isbn)
{
    for (auto &item : library)
    {
        if (item.first == isbn)
        {
            item.second.outputBookInfo(item.second);
            return;
        }
    }
    std::cout << "haven't\n";
}

void Library::deleteByISBN(std::string isbn)
{
    for (auto &item : library)
    {
        if (item.first == isbn)
        {
            library.erase(isbn);
            return;
        }
    }
    std::cout << "haven't\n";
}

void Library::checkAllBooks()
{
    for (auto &item : library)
    {
        item.second.outputBookInfo(item.second);
        std::cout << '\n';
    }
}

void Library::addAuthorByISBN(std::string isbn, std::string name)
{
    bool checkISBN = true;
    for (auto &item : library)
    {
        if (item.first == isbn)
        {
            library[isbn].addAuthor(name);
            checkISBN = false;
        }
    }
    if (checkISBN)
    {
        std::cout << "haven't isbn\n";
    }
}

void Library::deleteAuthorByISBN(std::string isbn, std::string name)
{
    auto it = library.find(isbn);
    if (it != library.end())
    {
        it->second.deleteAuthor(name);
    }
    else
    {
        std::cout << "haven't isbn\n";
    }
}

void Library::sortBooksByTitle()
{
    std::vector<Book> books;
    for (const auto &item : library)
    {
        books.push_back(item.second);
    }
    std::sort(books.begin(), books.end(), [](const Book &a, const Book &b)
              { return a.title < b.title; });
    for (auto book : books)
    {
        book.outputBookInfo(book);
        std::cout << '\n';
    }
}

void Library::sortBooksByISBN()
{
    std::vector<Book> books;
    for (const auto &item : library)
    {
        books.push_back(item.second);
    }
    std::sort(books.begin(), books.end(), [](const Book &a, const Book &b)
              { return *(a.ISBN.begin()) < *(b.ISBN.begin()); });
    for (auto book : books)
    {
        book.outputBookInfo(book);
        std::cout << '\n';
    }
}
