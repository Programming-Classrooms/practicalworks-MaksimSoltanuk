#include "../class/library.hpp"

int main()
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

	std::cout << "Hello, World!\n";
	return 0;
}
