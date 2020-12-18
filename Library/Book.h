#include "String.h"
#include "Vector.hpp"

using namespace std;

class Book
{
private:
	String title; /**< Type String because each book could have a title which length is undetermined. */
	String author; /**< Type String because each book could have an author which length is undetermined. */
	String genre; /**< Type String because each book could have a genre which length is undetermined. */
	int un; /**< Unique number, characterising each book. */

	String description; /**< Type String because each book could have a descr which length is undetermined. */
	int yearOfRelease;
	double rating;

	Vector<String> keyWords; /**< Dynamically allocated array(Vector) of objects of type String, undetermined length of each keyWord. */

public:
	/**
	* A default constructor and a constructor with parameters.
	* @see Book(String title, String author, String genre, int un,
		int yearOfRelease, double rating, String description, Vector<String> keyWords)
	*/
	Book();

	Book(String title, String author, String genre, int un,
		int yearOfRelease, double rating, String description, Vector<String> keyWords);

	/**
	* Getters for the different attributes of each book as const char*.
	* @see getAuthor() const @see getGenre() const @see getDescr() const
	* @see getUn() const @see getYearOfRelease() const @see getRating() const @see getKeyWords() const
	*/
	const char* getTitle() const;
	const char* getAuthor() const;
	const char* getGenre() const;
	const char* getDescr() const;

	int getUn() const;
	int getYearOfRelease() const;
	double getRating() const;

	Vector<String> getKeyWords() const;

	void Print() const;
};