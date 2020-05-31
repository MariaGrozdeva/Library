#include "Book.h"

Book::Book()
{
	title.setStr("Untitled");
	author.setStr("Unknown");
	genre.setStr("Genreless");
	un = -1;

	yearOfRelease = 2021;
	rating = -1;
	description.setStr("No descr");
}

Book::Book(String title, String author, String genre, int un,
	int yearOfRelease, double rating, String description, Vector<String> keyWords)
{
	this->title.setStr(title.getStr());
	this->author.setStr(author.getStr());
	this->genre.setStr(genre.getStr());
	this->un = un;

	this->yearOfRelease = yearOfRelease;
	this->rating = rating;
	this->description.setStr(description.getStr());

	this->keyWords = keyWords;
}

const char* Book::getTitle() const
{
	return title.getStr();
}
const char* Book::getAuthor() const
{
	return author.getStr();
}
const char* Book::getGenre() const
{
	return genre.getStr();
}
const char* Book::getDescr() const
{
	return description.getStr();
}

int Book::getUn() const
{
	return un;
}
int Book::getYearOfRelease() const
{
	return yearOfRelease;
}
double Book::getRating() const
{
	return rating;
}

Vector<String> Book::getKeyWords() const
{
	return keyWords;
}

void Book::Print() const
{
	title.print(); cout << " ";
	author.print();	cout << " ";
	genre.print(); 

	cout << " " << un << " " << yearOfRelease << " " << rating << " ";

	description.print();
	
	int len = keyWords.size();
	for (int i = 0; i < len; i++)
		cout << " " << keyWords.at(i).getStr();
}