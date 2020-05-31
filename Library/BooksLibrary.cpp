#include "BooksLibrary.h"

void BooksLibrary::CopyFrom(const BooksLibrary& other)
{
	capacity = other.capacity;
	count = other.count;

	books = new Book[capacity + 1];
	for (int i = 0; i < count; i++)
		books[i] = other.books[i];
}
void BooksLibrary::Free()
{
	delete[] books;
}

void BooksLibrary::Resize()
{
	capacity *= 2;
	Book* helper = new Book[capacity];

	for (int i = 0; i < count; i++)
		helper[i] = books[i];

	Free();
	books = helper;
}

BooksLibrary::BooksLibrary()
{
	capacity = 4;
	count = 0;

	books = new Book[capacity];
}

BooksLibrary::BooksLibrary(const BooksLibrary& other)
{
	CopyFrom(other);
}
BooksLibrary& BooksLibrary::operator=(const BooksLibrary& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
BooksLibrary::~BooksLibrary()
{
	Free();
}

Book* BooksLibrary::getBooks() const
{
	return books;
}
int BooksLibrary::getCount() const
{
	return count;
}

void BooksLibrary::AddBook(String title, String author, String genre, int un,
	int yearOfRelease, double rating, String description, Vector<String>keyWords)
{
	if (count == capacity)
		Resize();

	books[count++] = *new Book(title, author, genre, un,
		yearOfRelease, rating, description, keyWords);
}

void BooksLibrary::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		books[i].Print();
		cout << endl;
	}
}