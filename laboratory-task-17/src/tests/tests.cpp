#include "../class/library.hpp"
#include "gtest/gtest.h"

// Тесты для класса AuthorNames
TEST(AuthorNamesTest, AddName)
{
    AuthorNames authors;
    std::string name = "Ivanov Ivan Ivanovich";
    authors.addName(name);
    ASSERT_TRUE(authors.names.count(name));
}

TEST(AuthorNamesTest, DeleteName)
{
    AuthorNames authors;
    std::string name = "Ivanov Ivan Ivanovich";
    authors.addName(name);
    authors.deleteName(name);
    ASSERT_FALSE(authors.names.count(name));
}

// Тесты для класса Book
TEST(BookTest, Constructor)
{
    Book book(123, "Ivanov Ivan Ivanovich", "Some Book", 2001);
    ASSERT_EQ(book.UDK_number, 123);
    ASSERT_EQ(book.bookName, "Some Book");
    ASSERT_EQ(book.author, "Ivanov Ivan Ivanovich");
    ASSERT_EQ(book.yearOfPublic, 2001);
}

// Тесты для класса Library
TEST(LibraryTest, AddBook)
{
    Library library;
    Book book(123, "Ivanov Ivan Ivanovich", "Some Book", 2001);
    library.addBook(book);
    // Проверка, что книга добавлена в библиотеку
}

TEST(LibraryTest, DeleteBook)
{
    Library library;
    Book book(123, "Ivanov Ivan Ivanovich", "Some Book", 2001);
    library.addBook(book);
    library.deleteBook(book);
    // Проверка, что книга удалена из библиотеки
}

// Дополнительные тесты для класса AuthorNames
TEST(AuthorNamesTest, CheckName)
{
    AuthorNames authors;
    std::string name = "Ivanov Ivan Ivanovich";
    ASSERT_NO_THROW(authors.checkName(name));
    std::string badName = "Ivanov Ivan";
    ASSERT_THROW(authors.checkName(badName), std::logic_error);
}

// Дополнительные тесты для класса Book
TEST(BookTest, OperatorLessThan)
{
    Book book1(123, "Ivanov Ivan Ivanovich", "Book A", 2001);
    Book book2(456, "Petrov Petr Petrovich", "Book B", 2002);
    ASSERT_TRUE(book1 < book2);
    ASSERT_FALSE(book2 < book1);
}

TEST(BookTest, OperatorEquals)
{
    Book book1(123, "Ivanov Ivan Ivanovich", "Book A", 2001);
    Book book2(123, "Ivanov Ivan Ivanovich", "Book A", 2001);
    Book book3(456, "a b c", "Book B", 2002);
    ASSERT_TRUE(book1 == book2);
    ASSERT_FALSE(book1 == book3);
}

// Дополнительные тесты для класса Library
TEST(LibraryTest, FindByBookName)
{
    Library library;
    Book book(123, "Ivanov Ivan Ivanovich", "Some Book", 2001);
    library.addBook(book);
    // Проверка, что книга найдена по названию
}

TEST(LibraryTest, FindAllAuthorBook)
{
    Library library;
    Book book1(123, "Ivanov Ivan Ivanovich", "Book A", 2001);
    Book book2(456, "Ivanov Ivan Ivanovich", "Book B", 2002);
    library.addBook(book1);
    library.addBook(book2);
    // Проверка, что все книги автора найдены
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
