#include "String.h"
#include "Vector.hpp"

using namespace std;

class Book
{
private:
	String title;
	String author;
	String genre;
	int un;

	String description;
	int yearOfRelease;
	double rating;

	Vector<String> keyWords;

public:
	Book();

	Book(String title, String author, String genre, int un,
		int yearOfRelease, double rating, String description, Vector<String> keyWords);

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