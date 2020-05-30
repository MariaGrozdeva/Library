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
		int yearOfRelease, double rating, String description);

	void setUn(int un);
	void setYearOfRelease(int yearOfRelease);
	void setRating(double rating);

	int getUn() const;
	int getYearOfRelease() const;
	double getRating() const;

	void Print() const;
};