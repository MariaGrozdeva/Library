#include "String.h"

class Book
{
private:
	String author;
	String title;
	String genre;
	String description;
	int yearOfRelease;
	String keyWords;
	double rating;
	int un;

public:
	Book();

	Book(String author, String title, String genre, String description, 
		int yearOfRelease, String keyWords, double rating, int un);
};