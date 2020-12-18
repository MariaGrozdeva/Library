#include "Book.h"
#include "User.h"

class BooksLibrary
{
private:
	Book* books; /**< Dynamically allocated array of objects of type Book. */

	int capacity;
	int count;

	void CopyFrom(const BooksLibrary& other);
	void Free();

	void Resize();

public:
	/**
	* Big 4.
	* @see BooksLibrary(const BooksLibrary& other) @see BooksLibrary& operator=(const BooksLibrary& other)
	* @see ~BooksLibrary()
*/
	BooksLibrary();

	BooksLibrary(const BooksLibrary& other);
	BooksLibrary& operator=(const BooksLibrary& other);
	~BooksLibrary();

	/**
	* Getters for the array of books and the number of books, which increases when the function AddBook() is called
	* and a new book is added successfully.
	*/
	Book* getBooks() const;
	int getCount() const;

	void AddBook(String title, String author, String genre, int un,
		int yearOfRelease, double rating, String description, Vector<String>keyWords); /**< Adds a new book, based on the given parametres. */
	void booksRemove(String title); /**< Removes the book with the given parametres if such exist. */

	/**
	* Searches for a book by a given criteria(title, author, tag).
	* If such exist, prints it. Else, prints an error message.
	*/
	void booksFind(String option, String option_string);
	void booksView(int isbn_value); // booksInfo() /**< Searches for a book by its isbn_value. If found, prints it. */

	void PrintAll();
};