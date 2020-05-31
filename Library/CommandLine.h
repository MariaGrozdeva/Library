#include <fstream>
#include "UsersPlatform.h"
#include "BooksLibrary.h"

const int MAX_SIZE_OF_COMMAND = 13;
class CommandLine
{
private:
	UsersPlatform pl;
	BooksLibrary lib;
	User logged;

	ofstream fileUsers;
	ofstream fileBooks;
	String fileName;

	char command[MAX_SIZE_OF_COMMAND];
	char letter;
	int countOfKeyWords;

	void setAttributes(String& sample, char del);

	//void helperForSaveAndSaveas(String& diffFileName);
	void helperToCreateNewFile();
	void writeBooksInFile();
	void writeUsersInFile();

public:
	void enterCommand();

	void save(String& fileName);
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