#include <fstream>
#include "UsersPlatform.h"
#include "BooksLibrary.h"

const int MAX_SIZE_OF_COMMAND = 13;
class CommandLine
{
private:
	UsersPlatform pl;
	BooksLibrary lib;
	User logged; /**< The user logged at the moment. */

	ofstream fileUsers;
	ofstream fileBooks;
	String fileName; /**< Undetermined length of the name of a file. */

	char command[MAX_SIZE_OF_COMMAND];
	/**
	* Helper variables for reading input from file/console. Therefore, in the private section. @see countOfKeyWords
	*/
	char letter;
	int countOfKeyWords;

	/**
	* Reads from the console until it reaches the pointed out delimiter or endl. When one of the last two is read,
	* the content is written in the given sample name.
	*/
	void setAttributes(String& sample, char del);

	void helperToCreateNewFile(); /**< If the pointed out file doesn't exist, this function creates new, empty one. */

	/**
	* Inserts the library in the file. Each book is on a new line and its different attributes are separated by "|".
	*/
	void writeBooksInFile(String& fileName);
	/**
	* Inserts the users in the file. Each user is on a new line and its username, password and status
	* (if "isAdmin"- it is written in the file, else- no third attribute) are separated by ",".
	*/
	void writeUsersInFile();

public:
	void enterCommand();

	void save();
	void saveas();
	void close() const;
	void help() const;
	void exit();

	void open();

	bool login();
	void logout();

	void booksAll();
	void booksAdd();

	void usersAdd();
};