#include "../class/library.hpp"
#include "gtest/gtest.h"

TEST(LibraryTest, AllMethods)
{
    Library l;
    l.addBook("a2", "a", "aname", 256, 5);
    l.addBook("a3", "b", "bname", 256, 6);
    l.addBook("a1", "c", "cname", 256, 7);
    l.findByISBN("a2");
    l.deleteByISBN("a3");
    l.addAuthorByISBN("a2", "newName");
    l.checkAllBooks();
    l.deleteAuthorByISBN("a2", "newName");
    l.sortBooksByTitle();
    l.sortBooksByISBN();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
