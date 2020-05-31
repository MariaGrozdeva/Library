#include "Book.h"
#include "User.h"

class BooksLibrary
{
private:
	Book* books;

	int capacity;
	int count;

	void CopyFrom(const BooksLibrary& other);
	void Free();

	void Resize();

public:
	BooksLibrary();

	BooksLibrary(const BooksLibrary& other);
	BooksLibrary& operator=(const BooksLibrary& other);
	~BooksLibrary();

	Book* getBooks() const;
	int getCount() const;

	void AddBook(String title, String author, String genre, int un,
		int yearOfRelease, double rating, String description, Vector<String>keyWords);
	void booksRemove(String title);

	void booksFind(String option, String option_string);
	void booksView(int isbn_value); // booksInfo()

	void PrintAll();
};