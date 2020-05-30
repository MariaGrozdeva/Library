#include "Book.h"

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
		int yearOfRelease, double rating, String description);

	void PrintAll();
};