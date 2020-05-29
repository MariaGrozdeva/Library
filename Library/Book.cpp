#include "Book.h"

Book::Book()
{
	author.setStr("Unknown");
	title.setStr("Untitled");
	title.setStr("Genreless");
	title.setStr("No descr");
	yearOfRelease = 2021;
	keyWords.setStr("No keyWords");
	rating = -1;
	un = -1;
}

Book::Book(String author, String title, String genre, String description,
	int yearOfRelease, String keyWords, double rating, int un)
{
	this->author.setStr(author.getStr());
	this->title.setStr(title.getStr());
	this->genre.setStr(genre.getStr());
	this->description.setStr(description.getStr());
	this->yearOfRelease = yearOfRelease;
	this->keyWords.setStr(keyWords.getStr());
	this->rating = rating;
	this->un = un;
}