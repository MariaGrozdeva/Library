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
void BooksLibrary::booksRemove(String title)
{
	bool bookExist = false;
	int posOfBook = -1;

	for (int i = 0; i < count; i++)
	{
		if (strcmp(books[i].getTitle(), title.getStr()) == 0)
		{
			cout << "Successfully removed "; title.print();

			bookExist = true;
			posOfBook = i;
		}
	}
	if (!bookExist)
	{
		cerr << "Invalid title, such book doesn't exist.";
		return;
	}

	for (int i = posOfBook; i < count - 1; i++)
		books[i] = books[i + 1];
	count--;
}

void BooksLibrary::booksFind(String option, String option_string)
{
	if (strcmp(option.getStr(), "title") == 0)
	{
		bool bookExist = false;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(books[i].getTitle(), option_string.getStr()) == 0)
			{
				bookExist = true;
				books[i].Print();
				break;
			}
		}
		if (!bookExist)
		{
			cerr << "Invalid title, such book doesn't exist.";
			return;
		}
	}
	else if (strcmp(option.getStr(), "author") == 0)
	{
		bool bookExist = false;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(books[i].getAuthor(), option_string.getStr()) == 0)
			{
				bookExist = true;
				books[i].Print();
				break;
			}
		}
		if (!bookExist)
		{
			cerr << "Invalid author, such book doesn't exist.";
			return;
		}
	}
	else if (strcmp(option.getStr(), "tag") == 0)
	{
		bool bookExist = false;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < books[i].getKeyWords().size(); j++)
			{
				if (strcmp(books[i].getKeyWords().at(j).getStr(), option_string.getStr()) == 0)
				{
					bookExist = true;
					books[i].Print();
					break;
				}
			}
		}
		if (!bookExist)
		{
			cerr << "Invalid tag, such book doesn't exist.";
			return;
		}
	}
}
void BooksLibrary::booksView(int isbn_value)
{
	bool bookExist = false;
	for (int i = 0; i < count; i++)
	{
		if (books[i].getUn() == isbn_value)
		{
			bookExist = true;
			books[i].Print();
			break;
		}
	}
	if (!bookExist)
	{
		cerr << "Invalid un, such book doesn't exist.";
		return;
	}
}

void BooksLibrary::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		books[i].Print();
		cout << endl;
	}
}